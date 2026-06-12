#pragma once

#include <juce_audio_processors/juce_audio_processors.h>
#include "PluginProcessor.h"

class HyperiumAudioProcessorEditor final : public juce::AudioProcessorEditor
{
public:
    explicit HyperiumAudioProcessorEditor(HyperiumAudioProcessor& processor);
    ~HyperiumAudioProcessorEditor() override = default;

    void paint(juce::Graphics& g) override;
    void resized() override;

private:
    struct BoundSlider
    {
        juce::Label label;
        juce::Slider slider;
    };

    using SliderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;

    BoundSlider& addSlider(const juce::String& labelText,
                           const juce::String& parameterId,
                           juce::Slider::SliderStyle style = juce::Slider::LinearHorizontal);

    void addSeedButton(const juce::String& text);
    void addMotionButton(const juce::String& text);
    void addFxButton(const juce::String& text, bool active);

    void drawPanel(juce::Graphics& g, juce::Rectangle<int> bounds, const juce::String& title, const juce::String& subtitle) const;
    void drawWavePreview(juce::Graphics& g, juce::Rectangle<int> bounds, float variant) const;
    void drawTexturePreview(juce::Graphics& g, juce::Rectangle<int> bounds) const;
    void layoutSlider(BoundSlider& boundSlider, juce::Rectangle<int> bounds);
    void layoutSliderRow(int firstIndex, int count, juce::Rectangle<int> bounds);

    HyperiumAudioProcessor& audioProcessor;

    juce::Label brandLabel;
    juce::Label taglineLabel;
    juce::TextButton presetButton { "pink glass lead" };
    juce::TextButton saveButton { "Save" };
    juce::TextButton menuButton { "Menu" };

    juce::Label seedTitle;
    juce::TextButton generateButton { "Generate" };

    juce::Label morphTitle;
    juce::Label movementLabel;

    std::vector<std::unique_ptr<juce::TextButton>> seedButtons;
    std::vector<std::unique_ptr<juce::TextButton>> motionButtons;
    std::vector<std::unique_ptr<juce::TextButton>> fxButtons;

    std::vector<std::unique_ptr<BoundSlider>> sliders;
    std::vector<std::unique_ptr<SliderAttachment>> sliderAttachments;

    juce::Rectangle<int> oscAPanel;
    juce::Rectangle<int> oscBPanel;
    juce::Rectangle<int> texturePanel;
    juce::Rectangle<int> morphPanel;
    juce::Rectangle<int> movementPanel;
    juce::Rectangle<int> filterPanel;
    juce::Rectangle<int> motionPanel;
    juce::Rectangle<int> fxPanel;
    juce::Rectangle<int> macroPanel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(HyperiumAudioProcessorEditor)
};
