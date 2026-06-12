#pragma once

#include <vector>
#include <juce_core/juce_core.h>
#include "Parameters.h"

namespace hyperium
{

enum class SeedMood
{
    glassy,
    cute,
    dreamy,
    crushed,
    vocal
};

enum class SeedEnergy
{
    soft,
    medium,
    hard
};

enum class SeedMotion
{
    still,
    pulsing,
    drifting,
    glitchy,
    blooming
};

enum class SeedTexture
{
    clean,
    airy,
    dusty,
    digital,
    tape,
    grain,
    breath
};

struct ParameterAssignment
{
    juce::String parameterId;
    float normalizedValue { 0.0f };
};

struct SoundSeedResult
{
    juce::String presetName;
    juce::String description;
    std::vector<ParameterAssignment> assignments;
};

class SoundSeedEngine
{
public:
    static SoundSeedResult generate(SeedMood mood,
                                    SeedEnergy energy,
                                    SeedMotion motion,
                                    SeedTexture texture);

private:
    static void applyMood(SoundSeedResult& result, SeedMood mood);
    static void applyEnergy(SoundSeedResult& result, SeedEnergy energy);
    static void applyMotion(SoundSeedResult& result, SeedMotion motion);
    static void applyTexture(SoundSeedResult& result, SeedTexture texture);
    static void set(SoundSeedResult& result, const juce::String& parameterId, float normalizedValue);
};

} // namespace hyperium
