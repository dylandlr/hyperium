#pragma once

#include <array>
#include <cmath>
#include <juce_core/juce_core.h>

namespace hyperium::dsp
{

class WavetableOscillator
{
public:
    void prepare(double newSampleRate)
    {
        sampleRate = juce::jmax(1.0, newSampleRate);
        reset();
    }

    void reset()
    {
        phase = 0.0;
    }

    void setFrequency(float newFrequencyHz)
    {
        frequencyHz = juce::jlimit(1.0f, 20000.0f, newFrequencyHz);
    }

    float process(float position, float warp)
    {
        const auto normalizedPosition = juce::jlimit(0.0f, 1.0f, position);
        const auto normalizedWarp = juce::jlimit(0.0f, 1.0f, warp);

        advancePhase();

        const auto tablePosition = normalizedPosition * static_cast<float>(tableCount - 1);
        const auto tableA = static_cast<int>(std::floor(tablePosition));
        const auto tableB = juce::jmin(tableA + 1, tableCount - 1);
        const auto blend = tablePosition - static_cast<float>(tableA);

        const auto a = sampleTable(tableA, static_cast<float>(phase), normalizedWarp);
        const auto b = sampleTable(tableB, static_cast<float>(phase), normalizedWarp);

        return juce::jmap(blend, a, b);
    }

private:
    static constexpr int tableCount = 4;

    void advancePhase()
    {
        phase += static_cast<double>(frequencyHz) / sampleRate;

        if (phase >= 1.0)
            phase -= std::floor(phase);
    }

    static float softClip(float value)
    {
        return std::tanh(value);
    }

    static float sampleTable(int tableIndex, float phase01, float warp)
    {
        const auto twoPi = juce::MathConstants<float>::twoPi;
        const auto angle = twoPi * phase01;

        switch (tableIndex)
        {
            case 0: // clean sine / soft starter
                return std::sin(angle);

            case 1: // bright pop saw-ish shape
            {
                const auto saw = 2.0f * phase01 - 1.0f;
                const auto folded = std::abs(std::fmod(phase01 * (2.0f + warp * 4.0f), 2.0f) - 1.0f) * 2.0f - 1.0f;
                return softClip(saw * (0.8f + warp * 0.8f) + folded * 0.35f);
            }

            case 2: // glass: upper harmonic sparkle
                return softClip(std::sin(angle)
                    + 0.34f * std::sin(angle * (2.0f + warp * 3.0f))
                    + 0.18f * std::sin(angle * (5.0f + warp * 8.0f))
                    + 0.08f * std::sin(angle * 13.0f));

            case 3: // vocal chrome: vowel-ish harmonic weighting
                return softClip(0.72f * std::sin(angle)
                    + 0.28f * std::sin(angle * (3.0f + warp * 2.0f))
                    + 0.22f * std::sin(angle * (6.0f + warp * 6.0f))
                    - 0.10f * std::sin(angle * 9.0f));

            default:
                return 0.0f;
        }
    }

    double sampleRate { 44100.0 };
    double phase { 0.0 };
    float frequencyHz { 440.0f };
};

} // namespace hyperium::dsp
