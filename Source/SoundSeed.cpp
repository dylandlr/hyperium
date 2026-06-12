#include "SoundSeed.h"

namespace hyperium
{

SoundSeedResult SoundSeedEngine::generate(SeedMood mood,
                                          SeedEnergy energy,
                                          SeedMotion motion,
                                          SeedTexture texture)
{
    SoundSeedResult result;

    applyMood(result, mood);
    applyEnergy(result, energy);
    applyMotion(result, motion);
    applyTexture(result, texture);

    return result;
}

void SoundSeedEngine::applyMood(SoundSeedResult& result, SeedMood mood)
{
    switch (mood)
    {
        case SeedMood::glassy:
            result.presetName = "pink glass lead";
            result.description = "glassy · bright · modern · digital";
            set(result, ParameterID::oscAPosition, 0.70f);
            set(result, ParameterID::oscAWarp, 0.42f);
            set(result, ParameterID::oscALevel, 0.84f);
            set(result, ParameterID::oscBPosition, 0.62f);
            set(result, ParameterID::oscBWarp, 0.55f);
            set(result, ParameterID::macroBright, 0.82f);
            set(result, ParameterID::macroGlow, 0.74f);
            break;

        case SeedMood::cute:
            result.presetName = "candy pixel pluck";
            result.description = "cute · short · pop · sparkling";
            set(result, ParameterID::oscAPosition, 0.48f);
            set(result, ParameterID::oscAWarp, 0.24f);
            set(result, ParameterID::oscALevel, 0.74f);
            set(result, ParameterID::oscBPosition, 0.36f);
            set(result, ParameterID::oscBWarp, 0.32f);
            set(result, ParameterID::macroBright, 0.76f);
            set(result, ParameterID::macroHuman, 0.38f);
            break;

        case SeedMood::dreamy:
            result.presetName = "bedroom shimmer pad";
            result.description = "dreamy · wide · soft · nostalgic";
            set(result, ParameterID::oscAPosition, 0.58f);
            set(result, ParameterID::oscAWarp, 0.18f);
            set(result, ParameterID::oscALevel, 0.62f);
            set(result, ParameterID::oscBPosition, 0.67f);
            set(result, ParameterID::oscBWarp, 0.26f);
            set(result, ParameterID::macroGlow, 0.86f);
            set(result, ParameterID::macroWide, 0.78f);
            set(result, ParameterID::macroDrift, 0.42f);
            break;

        case SeedMood::crushed:
            result.presetName = "crushed candy bass";
            result.description = "crushed · hard · digital · aggressive";
            set(result, ParameterID::oscAPosition, 0.36f);
            set(result, ParameterID::oscAWarp, 0.78f);
            set(result, ParameterID::oscALevel, 0.90f);
            set(result, ParameterID::oscBPosition, 0.28f);
            set(result, ParameterID::oscBWarp, 0.81f);
            set(result, ParameterID::macroCrush, 0.78f);
            set(result, ParameterID::macroPunch, 0.74f);
            set(result, ParameterID::macroGlow, 0.24f);
            break;

        case SeedMood::vocal:
            result.presetName = "plastic vocal arp";
            result.description = "vocal · formant · glossy · animated";
            set(result, ParameterID::oscAPosition, 0.64f);
            set(result, ParameterID::oscAWarp, 0.47f);
            set(result, ParameterID::oscALevel, 0.68f);
            set(result, ParameterID::oscBPosition, 0.92f);
            set(result, ParameterID::oscBWarp, 0.62f);
            set(result, ParameterID::macroHuman, 0.52f);
            set(result, ParameterID::macroGlow, 0.62f);
            break;
    }
}

void SoundSeedEngine::applyEnergy(SoundSeedResult& result, SeedEnergy energy)
{
    switch (energy)
    {
        case SeedEnergy::soft:
            set(result, ParameterID::filterCutoff, 0.52f);
            set(result, ParameterID::filterDrive, 0.18f);
            set(result, ParameterID::filterShape, 0.20f);
            set(result, ParameterID::macroPunch, 0.30f);
            break;

        case SeedEnergy::medium:
            set(result, ParameterID::filterCutoff, 0.68f);
            set(result, ParameterID::filterDrive, 0.34f);
            set(result, ParameterID::filterShape, 0.42f);
            set(result, ParameterID::macroPunch, 0.56f);
            break;

        case SeedEnergy::hard:
            set(result, ParameterID::filterCutoff, 0.82f);
            set(result, ParameterID::filterDrive, 0.58f);
            set(result, ParameterID::filterShape, 0.68f);
            set(result, ParameterID::macroPunch, 0.78f);
            break;
    }
}

void SoundSeedEngine::applyMotion(SoundSeedResult& result, SeedMotion motion)
{
    switch (motion)
    {
        case SeedMotion::still:
            set(result, ParameterID::motionAmount, 0.00f);
            set(result, ParameterID::motionRate, 0.18f);
            set(result, ParameterID::motionHumanize, 0.10f);
            break;

        case SeedMotion::pulsing:
            set(result, ParameterID::motionAmount, 0.34f);
            set(result, ParameterID::motionRate, 0.52f);
            set(result, ParameterID::motionHumanize, 0.18f);
            break;

        case SeedMotion::drifting:
            set(result, ParameterID::motionAmount, 0.28f);
            set(result, ParameterID::motionRate, 0.22f);
            set(result, ParameterID::motionHumanize, 0.46f);
            set(result, ParameterID::macroDrift, 0.58f);
            break;

        case SeedMotion::glitchy:
            set(result, ParameterID::motionAmount, 0.56f);
            set(result, ParameterID::motionRate, 0.78f);
            set(result, ParameterID::motionHumanize, 0.62f);
            set(result, ParameterID::macroGlitch, 0.72f);
            break;

        case SeedMotion::blooming:
            set(result, ParameterID::motionAmount, 0.42f);
            set(result, ParameterID::motionRate, 0.30f);
            set(result, ParameterID::motionHumanize, 0.28f);
            set(result, ParameterID::macroGlow, 0.82f);
            break;
    }
}

void SoundSeedEngine::applyTexture(SoundSeedResult& result, SeedTexture texture)
{
    switch (texture)
    {
        case SeedTexture::clean:
            set(result, ParameterID::textureAmount, 0.08f);
            set(result, ParameterID::textureTone, 0.50f);
            set(result, ParameterID::textureStereo, 0.40f);
            break;

        case SeedTexture::airy:
            set(result, ParameterID::textureAmount, 0.28f);
            set(result, ParameterID::textureTone, 0.78f);
            set(result, ParameterID::textureStereo, 0.68f);
            break;

        case SeedTexture::dusty:
            set(result, ParameterID::textureAmount, 0.32f);
            set(result, ParameterID::textureTone, 0.38f);
            set(result, ParameterID::textureStereo, 0.54f);
            break;

        case SeedTexture::digital:
            set(result, ParameterID::textureAmount, 0.36f);
            set(result, ParameterID::textureTone, 0.72f);
            set(result, ParameterID::textureStereo, 0.62f);
            break;

        case SeedTexture::tape:
            set(result, ParameterID::textureAmount, 0.34f);
            set(result, ParameterID::textureTone, 0.42f);
            set(result, ParameterID::textureStereo, 0.58f);
            break;

        case SeedTexture::grain:
            set(result, ParameterID::textureAmount, 0.44f);
            set(result, ParameterID::textureTone, 0.64f);
            set(result, ParameterID::textureStereo, 0.76f);
            break;

        case SeedTexture::breath:
            set(result, ParameterID::textureAmount, 0.30f);
            set(result, ParameterID::textureTone, 0.68f);
            set(result, ParameterID::textureStereo, 0.66f);
            break;
    }
}

void SoundSeedEngine::set(SoundSeedResult& result, const juce::String& parameterId, float normalizedValue)
{
    const auto clampedValue = juce::jlimit(0.0f, 1.0f, normalizedValue);

    for (auto& assignment : result.assignments)
    {
        if (assignment.parameterId == parameterId)
        {
            assignment.normalizedValue = clampedValue;
            return;
        }
    }

    result.assignments.push_back({ parameterId, clampedValue });
}

} // namespace hyperium
