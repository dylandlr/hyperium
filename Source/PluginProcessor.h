#pragma once

#include <juce_audio_processors/juce_audio_processors.h>
#include <juce_dsp/juce_dsp.h>
#include "Parameters.h"
#include "dsp/WavetableOscillator.h"

class HyperiumAudioProcessor final : public juce::AudioProcessor
{
public:
    using APVTS = juce::AudioProcessorValueTreeState;

    HyperiumAudioProcessor();
    ~HyperiumAudioProcessor() override = default;

    void prepareToPlay(double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

    bool isBusesLayoutSupported(const BusesLayout& layouts) const override;

    void processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages) override;

    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override { return true; }

    const juce::String getName() const override { return JucePlugin_Name; }

    bool acceptsMidi() const override { return true; }
    bool producesMidi() const override { return false; }
    bool isMidiEffect() const override { return false; }
    double getTailLengthSeconds() const override { return 0.0; }

    int getNumPrograms() override { return 1; }
    int getCurrentProgram() override { return 0; }
    void setCurrentProgram(int index) override { juce::ignoreUnused(index); }
    const juce::String getProgramName(int index) override;
    void changeProgramName(int index, const juce::String& newName) override;

    void getStateInformation(juce::MemoryBlock& destData) override;
    void setStateInformation(const void* data, int sizeInBytes) override;

    APVTS parameters;

private:
    void handleMidi(const juce::MidiBuffer& midiMessages);
    float renderPlaceholderVoice();

    double currentSampleRate { 44100.0 };
    int activeMidiNote { -1 };
    float activeVelocity { 0.0f };

    hyperium::dsp::WavetableOscillator oscA;
    hyperium::dsp::WavetableOscillator oscB;

    juce::SmoothedValue<float> smoothedOutput;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(HyperiumAudioProcessor)
};
