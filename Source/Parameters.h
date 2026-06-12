#pragma once

#include <juce_audio_processors/juce_audio_processors.h>

namespace hyperium
{
namespace ParameterID
{
    inline constexpr const char* oscAPosition = "oscA.position";
    inline constexpr const char* oscAWarp = "oscA.warp";
    inline constexpr const char* oscALevel = "oscA.level";

    inline constexpr const char* oscBPosition = "oscB.position";
    inline constexpr const char* oscBWarp = "oscB.warp";
    inline constexpr const char* oscBLevel = "oscB.level";

    inline constexpr const char* textureAmount = "texture.amount";
    inline constexpr const char* textureTone = "texture.tone";
    inline constexpr const char* textureStereo = "texture.stereo";

    inline constexpr const char* filterCutoff = "filter.cutoff";
    inline constexpr const char* filterResonance = "filter.resonance";
    inline constexpr const char* filterDrive = "filter.drive";
    inline constexpr const char* filterShape = "filter.shape";

    inline constexpr const char* motionAmount = "motion.amount";
    inline constexpr const char* motionRate = "motion.rate";
    inline constexpr const char* motionHumanize = "motion.humanize";

    inline constexpr const char* macroBright = "macro.bright";
    inline constexpr const char* macroWide = "macro.wide";
    inline constexpr const char* macroCrush = "macro.crush";
    inline constexpr const char* macroGlow = "macro.glow";
    inline constexpr const char* macroDrift = "macro.drift";
    inline constexpr const char* macroPunch = "macro.punch";
    inline constexpr const char* macroGlitch = "macro.glitch";
    inline constexpr const char* macroHuman = "macro.human";
}

juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout();

float getParameterValue(const juce::AudioProcessorValueTreeState& state, const juce::String& id);

} // namespace hyperium
