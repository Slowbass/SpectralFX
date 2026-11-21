#pragma once

#include <juce_audio_processors/juce_audio_processors.h>
#include "PluginProcessor.h"

// Interface : thème sombre, accent ambre, trois panneaux (Spectre, Résonateur, Sortie).
// La fenêtre peut être agrandie.
class SpectralEditor : public juce::AudioProcessorEditor, private juce::Timer
{
public:
    explicit SpectralEditor (SpectralProcessor&);
    ~SpectralEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    class Knob : public juce::Slider
    {
    public:
        Knob (juce::String title, sfx::Kind kind, bool bipolar);
        void paint (juce::Graphics&) override;
        juce::String title;
        sfx::Kind kind;
        bool bipolar;
    };

    class Switch : public juce::ToggleButton
    {
    public:
        Switch (juce::String title, juce::String onText, juce::String offText, bool big);
        void paintButton (juce::Graphics&, bool over, bool down) override;
        juce::String title, onText, offText;
        bool big;
    };

private:
    struct Panel
    {
        juce::String name;
        juce::Rectangle<int> bounds;
        std::vector<juce::Component*> items;
        int columns;
    };

    struct Content : public juce::Component
    {
        std::function<void (juce::Graphics&)> painter;
        void paint (juce::Graphics& g) override { if (painter) painter (g); }
    };

    void paintContent (juce::Graphics&);
    void timerCallback() override;
    juce::Component* vitesseKnob = nullptr;
    juce::Component* divisionKnob = nullptr;
    juce::Rectangle<int> ledZone;
    float ledValeur = 0;

    SpectralProcessor& processor;
    Content content;
    std::vector<std::unique_ptr<Knob>> knobs;
    std::vector<std::unique_ptr<Switch>> switches;
    std::vector<std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment>> sliderAtts;
    std::vector<std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment>> buttonAtts;
    Panel panels[4];

public:
    static constexpr int baseW = 860, baseH = 568;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SpectralEditor)
};
