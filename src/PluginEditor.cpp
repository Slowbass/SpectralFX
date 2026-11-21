#include "PluginEditor.h"

using sfx::Kind;

namespace
{
const juce::Colour bg      { 0xff16181d };
const juce::Colour panelCol{ 0xff22252c };
const juce::Colour accent  { 0xffd9a441 };   // ambre
const juce::Colour textCol { 0xffe8e4dc };
const juce::Colour dimText { 0xff9a968e };
const juce::Colour track   { 0xff3a3d45 };

constexpr float startAngle = juce::MathConstants<float>::pi * 7.0f / 6.0f;   // 7 h
constexpr float endAngle   = juce::MathConstants<float>::pi * 17.0f / 6.0f;  // 5 h

constexpr int cellW = 86, cellH = 126, pad = 8, titleH = 26, gap = 10, headerH = 52, margin = 12;

juce::String u (const char* s) { return juce::String::fromUTF8 (s); }
}

//==============================================================================
SpectralEditor::Knob::Knob (juce::String t, Kind k, bool bip)
    : juce::Slider (juce::Slider::RotaryHorizontalVerticalDrag, juce::Slider::NoTextBox),
      title (std::move (t)), kind (k), bipolar (bip)
{
    setRotaryParameters (startAngle, endAngle, true);
    setMouseDragSensitivity (220);
}

void SpectralEditor::Knob::paint (juce::Graphics& g)
{
    const float w = (float) getWidth();
    const juce::Point<float> c (w / 2.0f, 46.0f);
    const float body = 21.0f;
    const float pos = (float) getNormalisableRange().convertTo0to1 (getValue());
    const float angle = startAngle + pos * (endAngle - startAngle);
    const float ring = body + 6.0f;

    juce::Path bgArc;
    bgArc.addCentredArc (c.x, c.y, ring, ring, 0.0f, startAngle, endAngle, true);
    g.setColour (track);
    g.strokePath (bgArc, juce::PathStrokeType (3.5f, juce::PathStrokeType::curved, juce::PathStrokeType::rounded));

    const float from = bipolar ? juce::MathConstants<float>::twoPi : startAngle;
    juce::Path arc;
    arc.addCentredArc (c.x, c.y, ring, ring, 0.0f, juce::jmin (from, angle), juce::jmax (from, angle), true);
    g.setColour (accent);
    g.strokePath (arc, juce::PathStrokeType (3.5f, juce::PathStrokeType::curved, juce::PathStrokeType::rounded));

    g.setGradientFill (juce::ColourGradient (juce::Colour (0xff4a4e57), c.x, c.y - body,
                                             juce::Colour (0xff1f2127), c.x, c.y + body, false));
    g.fillEllipse (juce::Rectangle<float> (body * 2, body * 2).withCentre (c));
    g.setColour (juce::Colour (0xff0c0d10));
    g.drawEllipse (juce::Rectangle<float> (body * 2, body * 2).withCentre (c), 1.2f);
    juce::Path needle;
    needle.addRoundedRectangle (-1.5f, -body + 3.0f, 3.0f, body * 0.6f, 1.5f);
    g.setColour (accent);
    g.fillPath (needle, juce::AffineTransform::rotation (angle).translated (c.x, c.y));

    g.setColour (textCol);
    g.setFont (juce::FontOptions (12.5f, juce::Font::bold));
    g.drawText (title, 0, 84, (int) w, 16, juce::Justification::centred);
    g.setColour (accent);
    g.setFont (juce::FontOptions (11.5f));
    g.drawFittedText (u (sfx::formatValue (kind, (float) getValue()).c_str()), 0, 102, (int) w, 15, juce::Justification::centred, 1, 0.8f);
}

//==============================================================================
SpectralEditor::Switch::Switch (juce::String t, juce::String on, juce::String off, bool b)
    : title (std::move (t)), onText (std::move (on)), offText (std::move (off)), big (b)
{
}

void SpectralEditor::Switch::paintButton (juce::Graphics& g, bool over, bool)
{
    const float w = (float) getWidth();
    const bool on = getToggleState();
    auto r = juce::Rectangle<float> (w - 18.0f, 52.0f).withCentre ({ w / 2.0f, 46.0f });

    g.setColour (on ? accent.withAlpha (big ? 0.9f : 0.25f) : juce::Colour (0xff2c2f36));
    g.fillRoundedRectangle (r, 8.0f);
    g.setColour (over ? accent : (on ? accent : track));
    g.drawRoundedRectangle (r, 8.0f, 1.6f);

    if (big)
    {
        g.setColour (on ? bg : textCol);
        g.setFont (juce::FontOptions (16.0f, juce::Font::bold));
        g.drawText (on ? onText : offText, r, juce::Justification::centred);
    }
    else
    {
        auto top = r.removeFromTop (r.getHeight() / 2);
        g.setFont (juce::FontOptions (12.5f, juce::Font::bold));
        g.setColour (on ? dimText : accent);
        g.drawText (offText, top, juce::Justification::centred);
        g.setColour (on ? accent : dimText);
        g.drawText (onText, r, juce::Justification::centred);
    }

    g.setColour (textCol);
    g.setFont (juce::FontOptions (12.5f, juce::Font::bold));
    g.drawText (title, 0, 84, (int) w, 16, juce::Justification::centred);
    g.setColour (accent);
    g.setFont (juce::FontOptions (11.5f));
    g.drawText (big ? (on ? u ("gel\xc3\xa9") : u ("libre")) : (on ? onText : offText), 0, 102, (int) w, 15, juce::Justification::centred);
}

//==============================================================================
SpectralEditor::SpectralEditor (SpectralProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    auto& state = processor.getState();
    content.painter = [this] (juce::Graphics& g) { paintContent (g); };
    addAndMakeVisible (content);

    const auto& defs = processor.getParamDefs();
    auto addKnob = [&] (int idx, const char* title, bool bipolar) -> juce::Component*
    {
        const auto& d = defs[(size_t) idx];
        auto k = std::make_unique<Knob> (u (title), d.kind, bipolar);
        sliderAtts.push_back (std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment> (state, juce::String (d.id), *k));
        k->setDoubleClickReturnValue (true, d.init);
        k->setTooltip (u (d.name.c_str()));
        content.addAndMakeVisible (*k);
        knobs.push_back (std::move (k));
        return knobs.back().get();
    };
    auto addSwitch = [&] (int idx, const char* title, const char* on, const char* off, bool big) -> juce::Component*
    {
        const auto& d = defs[(size_t) idx];
        auto s = std::make_unique<Switch> (u (title), u (on), u (off), big);
        buttonAtts.push_back (std::make_unique<juce::AudioProcessorValueTreeState::ButtonAttachment> (state, juce::String (d.id), *s));
        s->setTooltip (u (d.name.c_str()));
        content.addAndMakeVisible (*s);
        switches.push_back (std::move (s));
        return switches.back().get();
    };

    panels[0] = { u ("SPECTRE"), {}, {
        addSwitch (sfx::pGeler, "Geler", "GEL\xc3\x89", "GELER", true),
        addKnob (sfx::pTraine, "Tra\xc3\xae" "ne", false),
        addKnob (sfx::pDecalage, "D\xc3\xa9" "calage", true),
        addKnob (sfx::pEtirement, "\xc3\x89tirement", true),
        addKnob (sfx::pBrisure, "Brisure", false),
        addKnob (sfx::pEpure, "\xc3\x89pure", false) }, 6 };
    panels[1] = { u ("R\xc3\x89SONATEUR"), {}, {
        addKnob (sfx::pNote, "Note", false),
        addKnob (sfx::pAccord, "Accord", false),
        addSwitch (sfx::pTube, "Mati\xc3\xa8re", "Tube", "Corde", false),
        addKnob (sfx::pResonance, "R\xc3\xa9sonance", false),
        addKnob (sfx::pBrillance, "Brillance", false),
        addKnob (sfx::pMetal, "M\xc3\xa9tal", false),
        addKnob (sfx::pDerive, "D\xc3\xa9rive", false) }, 7 };
    panels[2] = { u ("SORTIE"), {}, {
        addKnob (sfx::pSalete, "Salet\xc3\xa9", false),
        addKnob (sfx::pPart, "R\xc3\xa9sonateur", false),
        addKnob (sfx::pMelange, "Sec / trait\xc3\xa9", false),
        addKnob (sfx::pSortie, "Volume", true) }, 2 };

    setResizable (true, true);
    setResizeLimits (baseW * 7 / 10, baseH * 7 / 10, baseW * 2, baseH * 2);
    getConstrainer()->setFixedAspectRatio ((double) baseW / baseH);
    setSize (baseW, baseH);
}

SpectralEditor::~SpectralEditor() = default;

void SpectralEditor::paint (juce::Graphics& g)
{
    g.fillAll (bg);
}

void SpectralEditor::resized()
{
    content.setBounds (0, 0, baseW, baseH);
    content.setTransform (juce::AffineTransform::scale ((float) getWidth() / (float) baseW));

    const int rowH = titleH + cellH + pad;
    auto place = [] (Panel& p, int x, int y, int cols)
    {
        const int rows = ((int) p.items.size() + cols - 1) / cols;
        p.bounds = { x, y, cols * cellW + 2 * pad, titleH + rows * cellH + pad + (rows - 1) * (gap + titleH - 4) };
        for (size_t i = 0; i < p.items.size(); ++i)
        {
            const int col = (int) i % cols, row = (int) i / cols;
            p.items[i]->setBounds (x + pad + col * cellW, y + titleH + row * (cellH + gap + titleH - 4), cellW, cellH);
        }
    };
    place (panels[0], margin, headerH, 6);
    place (panels[1], margin, headerH + rowH + gap, 7);
    const int rightX = margin + 7 * cellW + 2 * pad + gap;
    place (panels[2], rightX, headerH, 2);
    panels[2].bounds.setHeight (2 * rowH + gap);
    panels[2].bounds.setWidth (baseW - margin - rightX);
    // centrer les 2 colonnes de la sortie
    const int off = (panels[2].bounds.getWidth() - 2 * cellW - 2 * pad) / 2;
    for (auto* c : panels[2].items) c->setTopLeftPosition (c->getX() + off, c->getY());
}

void SpectralEditor::paintContent (juce::Graphics& g)
{
    g.fillAll (bg);

    g.setColour (accent);
    g.setFont (juce::FontOptions (25.0f, juce::Font::bold));
    g.drawText ("SpectralFX", margin + 2, 10, 160, 32, juce::Justification::centredLeft);
    g.setColour (dimText);
    g.setFont (juce::FontOptions (13.0f));
    g.drawText (u ("spectre bris\xc3\xa9 \xc2\xb7 r\xc3\xa9sonateur sale \xc2\xb7 v") + JucePlugin_VersionString,
                margin + 160, 10, 400, 32, juce::Justification::centredLeft);

    for (auto& p : panels)
    {
        g.setColour (panelCol);
        g.fillRoundedRectangle (p.bounds.toFloat(), 9.0f);
        g.setColour (accent);
        g.setFont (juce::FontOptions (12.5f, juce::Font::bold));
        g.drawText (p.name, p.bounds.getX() + 12, p.bounds.getY() + 5, 200, 17, juce::Justification::centredLeft);
        g.setColour (track);
        g.drawLine ((float) p.bounds.getX() + 12, (float) p.bounds.getY() + 24,
                    (float) p.bounds.getRight() - 12, (float) p.bounds.getY() + 24, 1.0f);
    }
}
