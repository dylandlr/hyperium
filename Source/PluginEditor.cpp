#include "PluginEditor.h"

namespace
{
    juce::Colour bgDeep() { return juce::Colour::fromString("ff07070d"); }
    juce::Colour panel() { return juce::Colour::fromString("dd11111c"); }
    juce::Colour panelSoft() { return juce::Colour::fromString("dd171725"); }
    juce::Colour textPrimary() { return juce::Colour::fromString("fff4f1ff"); }
    juce::Colour textSecondary() { return juce::Colour::fromString("ffa7a2be"); }
    juce::Colour textMuted() { return juce::Colour::fromString("ff6e6985"); }
    juce::Colour violet() { return juce::Colour::fromString("ff9b5cff"); }
    juce::Colour cyan() { return juce::Colour::fromString("ff56d8ff"); }
    juce::Colour pink() { return juce::Colour::fromString("ffff7dcd"); }
    juce::Colour orange() { return juce::Colour::fromString("ffff9a5c"); }

    void styleButton(juce::TextButton& button, bool active = false)
    {
        button.setColour(juce::TextButton::buttonColourId, active ? violet().withAlpha(0.82f) : juce::Colours::white.withAlpha(0.055f));
        button.setColour(juce::TextButton::buttonOnColourId, violet().withAlpha(0.9f));
        button.setColour(juce::TextButton::textColourOffId, textPrimary());
        button.setColour(juce::TextButton::textColourOnId, textPrimary());
    }

    void styleLabel(juce::Label& label, float height, juce::Colour colour = textPrimary(), bool bold = false)
    {
        label.setColour(juce::Label::textColourId, colour);
        label.setFont(juce::FontOptions { height, bold ? juce::Font::bold : juce::Font::plain });
        label.setInterceptsMouseClicks(false, false);
    }
}

HyperiumAudioProcessorEditor::HyperiumAudioProcessorEditor(HyperiumAudioProcessor& processor)
    : AudioProcessorEditor(&processor), audioProcessor(processor)
{
    setSize(1200, 760);
    setResizable(true, true);
    setResizeLimits(900, 600, 1600, 1000);

    styleLabel(taglineLabel, 11.0f, textMuted(), true);
    taglineLabel.setText("MINIMAL WAVETABLE SYNTH", juce::dontSendNotification);
    addAndMakeVisible(taglineLabel);

    styleLabel(brandLabel, 34.0f, textPrimary(), true);
    brandLabel.setText("HYPERIUM", juce::dontSendNotification);
    addAndMakeVisible(brandLabel);

    styleButton(presetButton);
    styleButton(saveButton);
    styleButton(menuButton);
    styleButton(generateButton, true);
    addAndMakeVisible(presetButton);
    addAndMakeVisible(saveButton);
    addAndMakeVisible(menuButton);
    addAndMakeVisible(generateButton);

    styleLabel(seedTitle, 18.0f, textPrimary(), true);
    seedTitle.setText("glassy · hard · glitchy · digital", juce::dontSendNotification);
    addAndMakeVisible(seedTitle);

    styleLabel(morphTitle, 15.0f, textSecondary(), true);
    morphTitle.setText("center", juce::dontSendNotification);
    addAndMakeVisible(morphTitle);

    styleLabel(movementLabel, 15.0f, textSecondary(), true);
    movementLabel.setText("Glitch → Wave Position", juce::dontSendNotification);
    addAndMakeVisible(movementLabel);

    for (auto seed : { "glassy", "cute", "dreamy", "crushed", "vocal" })
        addSeedButton(seed);

    for (auto motion : { "Pulse", "Drift", "Glitch", "Bloom", "Orbit" })
        addMotionButton(motion);

    addFxButton("Pitch", true);
    addFxButton("Crush", true);
    addFxButton("Drive", true);
    addFxButton("Chorus", false);
    addFxButton("Space", true);
    addFxButton("Comp", true);

    addSlider("Position", hyperium::ParameterID::oscAPosition);
    addSlider("Warp", hyperium::ParameterID::oscAWarp);
    addSlider("Level", hyperium::ParameterID::oscALevel);

    addSlider("Position", hyperium::ParameterID::oscBPosition);
    addSlider("Warp", hyperium::ParameterID::oscBWarp);
    addSlider("Level", hyperium::ParameterID::oscBLevel);

    addSlider("Amount", hyperium::ParameterID::textureAmount);
    addSlider("Tone", hyperium::ParameterID::textureTone);
    addSlider("Stereo", hyperium::ParameterID::textureStereo);

    addSlider("Cutoff", hyperium::ParameterID::filterCutoff);
    addSlider("Res", hyperium::ParameterID::filterResonance);
    addSlider("Drive", hyperium::ParameterID::filterDrive);
    addSlider("Shape", hyperium::ParameterID::filterShape);

    addSlider("Amount", hyperium::ParameterID::motionAmount);
    addSlider("Rate", hyperium::ParameterID::motionRate);
    addSlider("Humanize", hyperium::ParameterID::motionHumanize);

    addSlider("Bright", hyperium::ParameterID::macroBright, juce::Slider::RotaryHorizontalVerticalDrag);
    addSlider("Wide", hyperium::ParameterID::macroWide, juce::Slider::RotaryHorizontalVerticalDrag);
    addSlider("Crush", hyperium::ParameterID::macroCrush, juce::Slider::RotaryHorizontalVerticalDrag);
    addSlider("Glow", hyperium::ParameterID::macroGlow, juce::Slider::RotaryHorizontalVerticalDrag);
    addSlider("Drift", hyperium::ParameterID::macroDrift, juce::Slider::RotaryHorizontalVerticalDrag);
    addSlider("Punch", hyperium::ParameterID::macroPunch, juce::Slider::RotaryHorizontalVerticalDrag);
    addSlider("Glitch", hyperium::ParameterID::macroGlitch, juce::Slider::RotaryHorizontalVerticalDrag);
    addSlider("Human", hyperium::ParameterID::macroHuman, juce::Slider::RotaryHorizontalVerticalDrag);
}

HyperiumAudioProcessorEditor::BoundSlider& HyperiumAudioProcessorEditor::addSlider(
    const juce::String& labelText,
    const juce::String& parameterId,
    juce::Slider::SliderStyle style)
{
    auto bound = std::make_unique<BoundSlider>();

    styleLabel(bound->label, 12.0f, textSecondary());
    bound->label.setText(labelText, juce::dontSendNotification);

    bound->slider.setSliderStyle(style);
    bound->slider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 74, 18);
    bound->slider.setColour(juce::Slider::thumbColourId, cyan());
    bound->slider.setColour(juce::Slider::trackColourId, violet().withAlpha(0.55f));
    bound->slider.setColour(juce::Slider::backgroundColourId, juce::Colours::white.withAlpha(0.08f));
    bound->slider.setColour(juce::Slider::textBoxTextColourId, textPrimary());
    bound->slider.setColour(juce::Slider::textBoxOutlineColourId, juce::Colours::transparentBlack);

    addAndMakeVisible(bound->label);
    addAndMakeVisible(bound->slider);

    auto* raw = bound.get();
    sliders.push_back(std::move(bound));
    sliderAttachments.push_back(std::make_unique<SliderAttachment>(audioProcessor.parameters, parameterId, raw->slider));

    return *raw;
}

void HyperiumAudioProcessorEditor::addSeedButton(const juce::String& text)
{
    auto button = std::make_unique<juce::TextButton>(text);
    styleButton(*button, text == "glassy");
    button->onClick = [this, text]
    {
        for (auto& seedButton : seedButtons)
            styleButton(*seedButton, seedButton->getButtonText() == text);

        presetButton.setButtonText(text == "cute" ? "candy pixel pluck"
            : text == "dreamy" ? "bedroom shimmer pad"
            : text == "crushed" ? "crushed candy bass"
            : text == "vocal" ? "plastic vocal arp"
            : "pink glass lead");

        seedTitle.setText(text + " · generated workflow seed", juce::dontSendNotification);
    };

    addAndMakeVisible(*button);
    seedButtons.push_back(std::move(button));
}

void HyperiumAudioProcessorEditor::addMotionButton(const juce::String& text)
{
    auto button = std::make_unique<juce::TextButton>(text);
    styleButton(*button, text == "Glitch");
    button->onClick = [this, text]
    {
        for (auto& motionButton : motionButtons)
            styleButton(*motionButton, motionButton->getButtonText() == text);

        movementLabel.setText(text + " → Wave Position", juce::dontSendNotification);
    };

    addAndMakeVisible(*button);
    motionButtons.push_back(std::move(button));
}

void HyperiumAudioProcessorEditor::addFxButton(const juce::String& text, bool active)
{
    auto button = std::make_unique<juce::TextButton>(text);
    styleButton(*button, active);
    button->setClickingTogglesState(true);
    button->setToggleState(active, juce::dontSendNotification);
    button->onClick = [button = button.get()]
    {
        styleButton(*button, button->getToggleState());
    };

    addAndMakeVisible(*button);
    fxButtons.push_back(std::move(button));
}

void HyperiumAudioProcessorEditor::paint(juce::Graphics& g)
{
    g.fillAll(bgDeep());

    auto bounds = getLocalBounds().toFloat();
    juce::ColourGradient bg(violet().withAlpha(0.24f), bounds.getX(), bounds.getY(),
                            cyan().withAlpha(0.08f), bounds.getRight(), bounds.getBottom(), false);
    bg.addColour(0.72, pink().withAlpha(0.09f));
    g.setGradientFill(bg);
    g.fillRoundedRectangle(bounds.reduced(8.0f), 34.0f);

    drawPanel(g, morphPanel, "MACRO MORPH", "dream · soft · crush · glitch");
    drawPanel(g, movementPanel, "ACTIVE MOVEMENT", movementLabel.getText());
    drawPanel(g, oscAPanel, "OSC A", "glass table");
    drawPanel(g, oscBPanel, "OSC B", "vocal chrome");
    drawPanel(g, texturePanel, "TEXTURE", "glass");
    drawPanel(g, filterPanel, "FILTER / SHAPE", "hyper lp · mirror fold");
    drawPanel(g, motionPanel, "MOTION", "one movement layer");
    drawPanel(g, fxPanel, "FX", "curated chain");
    drawPanel(g, macroPanel, "MACROS", "performance controls");

    drawWavePreview(g, oscAPanel.reduced(16).withTrimmedTop(34).removeFromTop(82), 1.0f);
    drawWavePreview(g, oscBPanel.reduced(16).withTrimmedTop(34).removeFromTop(82), 3.0f);
    drawTexturePreview(g, texturePanel.reduced(16).withTrimmedTop(34).removeFromTop(82));

    auto pad = morphPanel.reduced(16).withTrimmedTop(36).withTrimmedBottom(12);
    g.setColour(juce::Colours::white.withAlpha(0.055f));
    g.fillRoundedRectangle(pad.toFloat(), 22.0f);
    g.setColour(cyan().withAlpha(0.18f));
    g.drawLine(pad.getCentreX(), pad.getY() + 18, pad.getCentreX(), pad.getBottom() - 18, 1.0f);
    g.drawLine(pad.getX() + 18, pad.getCentreY(), pad.getRight() - 18, pad.getCentreY(), 1.0f);
    g.setColour(textSecondary());
    g.setFont(11.0f);
    g.drawText("DREAM", pad.removeFromTop(24), juce::Justification::centred);
}

void HyperiumAudioProcessorEditor::resized()
{
    auto area = getLocalBounds().reduced(24);

    auto header = area.removeFromTop(62);
    taglineLabel.setBounds(header.removeFromLeft(310).removeFromTop(18));
    brandLabel.setBounds(24, 42, 300, 40);
    menuButton.setBounds(header.removeFromRight(74).reduced(4, 10));
    saveButton.setBounds(header.removeFromRight(74).reduced(4, 10));
    presetButton.setBounds(header.removeFromRight(230).reduced(4, 10));

    auto seed = area.removeFromTop(58).reduced(0, 2);
    seedTitle.setBounds(seed.removeFromLeft(330).reduced(14, 8));
    generateButton.setBounds(seed.removeFromRight(108).reduced(8, 10));
    auto seedButtonArea = seed.reduced(8, 10);
    for (auto& button : seedButtons)
        button->setBounds(seedButtonArea.removeFromLeft(88).reduced(4, 0));

    auto morphRow = area.removeFromTop(210);
    morphPanel = morphRow.removeFromLeft(330).reduced(0, 6);
    movementPanel = morphRow.reduced(6, 6);
    morphTitle.setBounds(morphPanel.withTrimmedTop(38).reduced(24, 12).removeFromBottom(24));
    movementLabel.setBounds(movementPanel.reduced(20).removeFromTop(24));

    auto moduleRow = area.removeFromTop(224);
    oscAPanel = moduleRow.removeFromLeft(moduleRow.getWidth() / 3).reduced(0, 6);
    oscBPanel = moduleRow.removeFromLeft(moduleRow.getWidth() / 2).reduced(6, 6);
    texturePanel = moduleRow.reduced(6, 6);

    layoutSliderRow(0, 3, oscAPanel.reduced(16).withTrimmedTop(126));
    layoutSliderRow(3, 3, oscBPanel.reduced(16).withTrimmedTop(126));
    layoutSliderRow(6, 3, texturePanel.reduced(16).withTrimmedTop(126));

    filterPanel = area.removeFromTop(96).reduced(0, 6);
    layoutSliderRow(9, 4, filterPanel.reduced(16).withTrimmedTop(32));

    motionPanel = area.removeFromTop(92).reduced(0, 6);
    auto motionButtonsArea = motionPanel.reduced(16).withTrimmedTop(34).removeFromLeft(430);
    for (auto& button : motionButtons)
        button->setBounds(motionButtonsArea.removeFromLeft(82).reduced(4, 8));
    layoutSliderRow(13, 3, motionPanel.reduced(16).withTrimmedTop(34).withTrimmedLeft(440));

    fxPanel = area.removeFromTop(70).reduced(0, 6);
    auto fxButtonArea = fxPanel.reduced(16).withTrimmedLeft(170).withTrimmedTop(16);
    for (auto& button : fxButtons)
        button->setBounds(fxButtonArea.removeFromLeft(86).reduced(5, 8));

    macroPanel = area.reduced(0, 6);
    layoutSliderRow(16, 8, macroPanel.reduced(16).withTrimmedTop(30));
}

void HyperiumAudioProcessorEditor::drawPanel(juce::Graphics& g, juce::Rectangle<int> bounds, const juce::String& title, const juce::String& subtitle) const
{
    auto r = bounds.toFloat();
    g.setColour(panel());
    g.fillRoundedRectangle(r, 20.0f);

    g.setColour(juce::Colours::white.withAlpha(0.09f));
    g.drawRoundedRectangle(r, 20.0f, 1.0f);

    g.setFont(11.0f);
    g.setColour(textMuted());
    g.drawText(title, bounds.reduced(16).removeFromTop(18), juce::Justification::left);

    g.setFont(13.0f);
    g.setColour(textSecondary());
    g.drawText(subtitle, bounds.reduced(16).removeFromTop(18), juce::Justification::right);
}

void HyperiumAudioProcessorEditor::drawWavePreview(juce::Graphics& g, juce::Rectangle<int> bounds, float variant) const
{
    g.setColour(juce::Colours::white.withAlpha(0.045f));
    g.fillRoundedRectangle(bounds.toFloat(), 16.0f);

    juce::Path path;
    const auto centerY = static_cast<float>(bounds.getCentreY());
    const auto amplitude = static_cast<float>(bounds.getHeight()) * 0.28f;

    for (int x = 0; x < bounds.getWidth(); ++x)
    {
        auto t = static_cast<float>(x) / static_cast<float>(juce::jmax(1, bounds.getWidth()));
        auto wave = std::sin(t * juce::MathConstants<float>::twoPi * (2.0f + variant)) * 0.7f
                  + std::sin(t * juce::MathConstants<float>::twoPi * (7.0f + variant)) * 0.22f;
        auto y = centerY + wave * amplitude;

        if (x == 0)
            path.startNewSubPath(static_cast<float>(bounds.getX() + x), y);
        else
            path.lineTo(static_cast<float>(bounds.getX() + x), y);
    }

    juce::ColourGradient grad(cyan(), bounds.getX(), bounds.getY(), pink(), bounds.getRight(), bounds.getBottom(), false);
    g.setGradientFill(grad);
    g.strokePath(path, juce::PathStrokeType(2.4f));
}

void HyperiumAudioProcessorEditor::drawTexturePreview(juce::Graphics& g, juce::Rectangle<int> bounds) const
{
    g.setColour(juce::Colours::white.withAlpha(0.045f));
    g.fillRoundedRectangle(bounds.toFloat(), 16.0f);

    for (int i = 0; i < 18; ++i)
    {
        const auto x = bounds.getX() + 14 + (i * 37) % juce::jmax(1, bounds.getWidth() - 28);
        const auto y = bounds.getY() + 12 + (i * 23) % juce::jmax(1, bounds.getHeight() - 24);
        const auto colour = i % 3 == 0 ? pink() : i % 3 == 1 ? cyan() : violet();
        g.setColour(colour.withAlpha(0.72f));
        g.fillEllipse(static_cast<float>(x), static_cast<float>(y), 6.0f, 6.0f);
    }
}

void HyperiumAudioProcessorEditor::layoutSlider(BoundSlider& boundSlider, juce::Rectangle<int> bounds)
{
    boundSlider.label.setBounds(bounds.removeFromTop(18));
    boundSlider.slider.setBounds(bounds);
}

void HyperiumAudioProcessorEditor::layoutSliderRow(int firstIndex, int count, juce::Rectangle<int> bounds)
{
    const auto gap = 8;
    const auto width = (bounds.getWidth() - gap * (count - 1)) / count;

    for (int i = 0; i < count; ++i)
    {
        if (auto index = firstIndex + i; juce::isPositiveAndBelow(index, static_cast<int>(sliders.size())))
        {
            auto cell = bounds.removeFromLeft(width);
            layoutSlider(*sliders[static_cast<size_t>(index)], cell);
            bounds.removeFromLeft(gap);
        }
    }
}
