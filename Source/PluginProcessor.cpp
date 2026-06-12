#include "PluginProcessor.h"
#include "PluginEditor.h"

HyperiumAudioProcessor::HyperiumAudioProcessor()
    : AudioProcessor(BusesProperties()
          .withOutput("Output", juce::AudioChannelSet::stereo(), true)),
      parameters(*this, nullptr, "HyperiumParameters", hyperium::createParameterLayout())
{
}

void HyperiumAudioProcessor::prepareToPlay(double sampleRate, int samplesPerBlock)
{
    juce::ignoreUnused(samplesPerBlock);

    currentSampleRate = sampleRate;
    oscA.prepare(sampleRate);
    oscB.prepare(sampleRate);

    smoothedOutput.reset(sampleRate, 0.02);
    smoothedOutput.setCurrentAndTargetValue(0.0f);
}

void HyperiumAudioProcessor::releaseResources()
{
}

bool HyperiumAudioProcessor::isBusesLayoutSupported(const BusesLayout& layouts) const
{
    const auto& mainOutput = layouts.getMainOutputChannelSet();
    return mainOutput == juce::AudioChannelSet::mono()
        || mainOutput == juce::AudioChannelSet::stereo();
}

void HyperiumAudioProcessor::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;

    handleMidi(midiMessages);
    buffer.clear();

    const auto oscALevel = hyperium::getParameterValue(parameters, hyperium::ParameterID::oscALevel);
    const auto oscBLevel = hyperium::getParameterValue(parameters, hyperium::ParameterID::oscBLevel);
    const auto textureAmount = hyperium::getParameterValue(parameters, hyperium::ParameterID::textureAmount);
    const auto bright = hyperium::getParameterValue(parameters, hyperium::ParameterID::macroBright);
    const auto punch = hyperium::getParameterValue(parameters, hyperium::ParameterID::macroPunch);

    const auto targetLevel = activeMidiNote >= 0
        ? juce::jlimit(0.0f, 0.28f, (oscALevel + oscBLevel * 0.65f + textureAmount * 0.08f) * activeVelocity * 0.18f)
        : 0.0f;

    smoothedOutput.setTargetValue(targetLevel);

    for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
    {
        auto value = renderPlaceholderVoice();
        value *= smoothedOutput.getNextValue();

        // Temporary macro feel: Bright adds harmonic edge, Punch tightens perceived level.
        value = std::tanh(value * (1.0f + bright * 0.45f + punch * 0.18f));

        for (int channel = 0; channel < buffer.getNumChannels(); ++channel)
            buffer.setSample(channel, sample, value);
    }
}

void HyperiumAudioProcessor::handleMidi(const juce::MidiBuffer& midiMessages)
{
    for (const auto metadata : midiMessages)
    {
        const auto message = metadata.getMessage();

        if (message.isNoteOn())
        {
            activeMidiNote = message.getNoteNumber();
            activeVelocity = message.getVelocity();
        }
        else if (message.isNoteOff() && message.getNoteNumber() == activeMidiNote)
        {
            activeMidiNote = -1;
            activeVelocity = 0.0f;
        }
        else if (message.isAllNotesOff() || message.isAllSoundOff())
        {
            activeMidiNote = -1;
            activeVelocity = 0.0f;
        }
    }
}

float HyperiumAudioProcessor::renderPlaceholderVoice()
{
    if (activeMidiNote < 0)
        return 0.0f;

    const auto baseFrequency = juce::MidiMessage::getMidiNoteInHertz(activeMidiNote);
    const auto oscAPosition = hyperium::getParameterValue(parameters, hyperium::ParameterID::oscAPosition);
    const auto oscAWarp = hyperium::getParameterValue(parameters, hyperium::ParameterID::oscAWarp);
    const auto oscALevel = hyperium::getParameterValue(parameters, hyperium::ParameterID::oscALevel);

    const auto oscBPosition = hyperium::getParameterValue(parameters, hyperium::ParameterID::oscBPosition);
    const auto oscBWarp = hyperium::getParameterValue(parameters, hyperium::ParameterID::oscBWarp);
    const auto oscBLevel = hyperium::getParameterValue(parameters, hyperium::ParameterID::oscBLevel);

    const auto drift = hyperium::getParameterValue(parameters, hyperium::ParameterID::macroDrift);
    const auto wide = hyperium::getParameterValue(parameters, hyperium::ParameterID::macroWide);

    oscA.setFrequency(baseFrequency * (1.0f + drift * 0.0015f));
    oscB.setFrequency(baseFrequency * (1.0f + wide * 0.006f + drift * 0.0025f));

    const auto a = oscA.process(oscAPosition, oscAWarp) * oscALevel;
    const auto b = oscB.process(oscBPosition, oscBWarp) * oscBLevel;

    return (a + b * 0.72f) * 0.58f;
}

juce::AudioProcessorEditor* HyperiumAudioProcessor::createEditor()
{
    return new HyperiumAudioProcessorEditor(*this);
}

const juce::String HyperiumAudioProcessor::getProgramName(int index)
{
    juce::ignoreUnused(index);
    return {};
}

void HyperiumAudioProcessor::changeProgramName(int index, const juce::String& newName)
{
    juce::ignoreUnused(index, newName);
}

void HyperiumAudioProcessor::getStateInformation(juce::MemoryBlock& destData)
{
    if (auto state = parameters.copyState(); auto xml = state.createXml())
        copyXmlToBinary(*xml, destData);
}

void HyperiumAudioProcessor::setStateInformation(const void* data, int sizeInBytes)
{
    if (auto xml = getXmlFromBinary(data, sizeInBytes))
        if (xml->hasTagName(parameters.state.getType()))
            parameters.replaceState(juce::ValueTree::fromXml(*xml));
}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new HyperiumAudioProcessor();
}
