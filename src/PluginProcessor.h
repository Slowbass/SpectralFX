#pragma once

#include <juce_audio_processors/juce_audio_processors.h>
#include "Moteur.h"

class SpectralProcessor : public juce::AudioProcessor
{
public:
    SpectralProcessor();
    ~SpectralProcessor() override = default;

    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override {}
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;
    using AudioProcessor::processBlock;

    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override { return true; }

    const juce::String getName() const override { return JucePlugin_Name; }
    bool acceptsMidi() const override { return false; }
    bool producesMidi() const override { return false; }
    bool isMidiEffect() const override { return false; }
    double getTailLengthSeconds() const override { return 20.0; }

    int getNumPrograms() override { return 1; }
    int getCurrentProgram() override { return 0; }
    void setCurrentProgram (int) override {}
    const juce::String getProgramName (int) override { return juce::String::fromUTF8 ("D\xc3\xa9" "faut"); }
    void changeProgramName (int, const juce::String&) override {}

    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    juce::AudioProcessorValueTreeState& getState() { return state; }
    const std::vector<sfx::ParamDef>& getParamDefs() const { return engine.getParams(); }
    float valeurMouvement() const { return engine.valeurMouvement(); }

private:
    juce::AudioProcessorValueTreeState::ParameterLayout createLayout();
    void pushParameters (bool force);

    sfx::Engine engine;
    juce::AudioProcessorValueTreeState state;
    std::vector<std::atomic<float>*> rawValues;
    std::vector<float> lastValues;
    juce::AudioBuffer<float> monoScratch;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SpectralProcessor)
};
