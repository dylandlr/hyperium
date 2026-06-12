#include "Parameters.h"

namespace hyperium
{
namespace
{
    std::unique_ptr<juce::AudioParameterFloat> makePercentParam(
        const juce::String& id,
        const juce::String& name,
        float defaultValue)
    {
        return std::make_unique<juce::AudioParameterFloat>(
            juce::ParameterID { id, 1 },
            name,
            juce::NormalisableRange<float> { 0.0f, 1.0f, 0.001f },
            defaultValue,
            juce::AudioParameterFloatAttributes()
                .withLabel("%")
                .withStringFromValueFunction([] (float value, int)
                {
                    return juce::String { juce::roundToInt(value * 100.0f) } + "%";
                })
        );
    }

    std::unique_ptr<juce::AudioParameterFloat> makeCutoffParam()
    {
        return std::make_unique<juce::AudioParameterFloat>(
            juce::ParameterID { ParameterID::filterCutoff, 1 },
            "Filter Cutoff",
            juce::NormalisableRange<float> { 20.0f, 20000.0f, 0.01f, 0.35f },
            8500.0f,
            juce::AudioParameterFloatAttributes()
                .withLabel("Hz")
                .withStringFromValueFunction([] (float value, int)
                {
                    if (value >= 1000.0f)
                        return juce::String { value / 1000.0f, 1 } + " kHz";
                    return juce::String { juce::roundToInt(value) } + " Hz";
                })
        );
    }
}

juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout()
{
    std::vector<std::unique_ptr<juce::RangedAudioParameter>> params;

    params.push_back(makePercentParam(ParameterID::oscAPosition, "OSC A Position", 0.62f));
    params.push_back(makePercentParam(ParameterID::oscAWarp, "OSC A Warp", 0.34f));
    params.push_back(makePercentParam(ParameterID::oscALevel, "OSC A Level", 0.82f));

    params.push_back(makePercentParam(ParameterID::oscBPosition, "OSC B Position", 0.41f));
    params.push_back(makePercentParam(ParameterID::oscBWarp, "OSC B Warp", 0.57f));
    params.push_back(makePercentParam(ParameterID::oscBLevel, "OSC B Level", 0.48f));

    params.push_back(makePercentParam(ParameterID::textureAmount, "Texture Amount", 0.35f));
    params.push_back(makePercentParam(ParameterID::textureTone, "Texture Tone", 0.72f));
    params.push_back(makePercentParam(ParameterID::textureStereo, "Texture Stereo", 0.64f));

    params.push_back(makeCutoffParam());
    params.push_back(makePercentParam(ParameterID::filterResonance, "Filter Resonance", 0.19f));
    params.push_back(makePercentParam(ParameterID::filterDrive, "Filter Drive", 0.31f));
    params.push_back(makePercentParam(ParameterID::filterShape, "Filter Shape", 0.46f));

    params.push_back(makePercentParam(ParameterID::motionAmount, "Motion Amount", 0.28f));
    params.push_back(makePercentParam(ParameterID::motionRate, "Motion Rate", 0.64f));
    params.push_back(makePercentParam(ParameterID::motionHumanize, "Motion Humanize", 0.22f));

    params.push_back(makePercentParam(ParameterID::macroBright, "Bright", 0.78f));
    params.push_back(makePercentParam(ParameterID::macroWide, "Wide", 0.64f));
    params.push_back(makePercentParam(ParameterID::macroCrush, "Crush", 0.39f));
    params.push_back(makePercentParam(ParameterID::macroGlow, "Glow", 0.71f));
    params.push_back(makePercentParam(ParameterID::macroDrift, "Drift", 0.22f));
    params.push_back(makePercentParam(ParameterID::macroPunch, "Punch", 0.58f));
    params.push_back(makePercentParam(ParameterID::macroGlitch, "Glitch", 0.33f));
    params.push_back(makePercentParam(ParameterID::macroHuman, "Human", 0.46f));

    return { params.begin(), params.end() };
}

float getParameterValue(const juce::AudioProcessorValueTreeState& state, const juce::String& id)
{
    if (const auto* value = state.getRawParameterValue(id))
        return value->load();

    jassertfalse;
    return 0.0f;
}

} // namespace hyperium
