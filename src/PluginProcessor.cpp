#include "PluginProcessor.h"
#include "PluginEditor.h"

using sfx::Kind;

SpectralProcessor::SpectralProcessor()
    : AudioProcessor (BusesProperties()
                        .withInput  (juce::String::fromUTF8 ("Entr\xc3\xa9" "e"), juce::AudioChannelSet::stereo(), true)
                        .withOutput ("Sortie", juce::AudioChannelSet::stereo(), true)),
      state (*this, nullptr, "SpectralFX", createLayout())
{
    jassert (engine.allZonesFound());
    for (const auto& p : engine.getParams())
        rawValues.push_back (state.getRawParameterValue (juce::String (p.id)));
    lastValues.assign (rawValues.size(), std::numeric_limits<float>::quiet_NaN());
    setLatencySamples (sfx::fftSizeFor (44100.0));
}

juce::AudioProcessorValueTreeState::ParameterLayout SpectralProcessor::createLayout()
{
    juce::AudioProcessorValueTreeState::ParameterLayout layout;
    for (const auto& p : engine.getParams())
    {
        const juce::ParameterID pid { juce::String (p.id), 1 };
        const auto name = juce::String::fromUTF8 (p.name.c_str());
        if (p.kind == Kind::Toggle)
        {
            layout.add (std::make_unique<juce::AudioParameterBool> (pid, name, p.init > 0.5f));
            continue;
        }
        const Kind k = p.kind;
        juce::NormalisableRange<float> range (p.min, p.max, p.step);
        if (p.symetrique)
            range = juce::NormalisableRange<float> (p.min, p.max, p.step, 0.5f, true);
        else if (p.centre > 0.0f)
            range.setSkewForCentre (p.centre);
        auto attrs = juce::AudioParameterFloatAttributes()
            .withStringFromValueFunction ([k] (float v, int) { return juce::String::fromUTF8 (sfx::formatValue (k, v).c_str()); })
            .withValueFromStringFunction ([k] (const juce::String& t)
            {
                if (k == Kind::Percent) return t.getFloatValue() / 100.0f;
                return t.replaceCharacter (',', '.').retainCharacters ("0123456789.-+").getFloatValue();
            });
        layout.add (std::make_unique<juce::AudioParameterFloat> (pid, name, range, p.init, attrs));
    }
    return layout;
}

bool SpectralProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
    const auto in = layouts.getMainInputChannelSet();
    const auto out = layouts.getMainOutputChannelSet();
    if (in != out) return false;
    return out == juce::AudioChannelSet::stereo() || out == juce::AudioChannelSet::mono();
}

void SpectralProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    pushParameters (true);
    engine.prepare (sampleRate);
    monoScratch.setSize (1, juce::jmax (64, samplesPerBlock));
    setLatencySamples (engine.latency());
}

void SpectralProcessor::pushParameters (bool force)
{
    for (size_t i = 0; i < rawValues.size(); ++i)
    {
        const float v = rawValues[i]->load();
        if (! force && juce::exactlyEqual (v, lastValues[i])) continue;
        lastValues[i] = v;
        engine.setParam (i, v);
    }
}

void SpectralProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer&)
{
    juce::ScopedNoDenormals noDenormals;
    pushParameters (false);

    // tempo et position de Cubase, pour le mouvement calé sur le tempo
    double bpm = 120, ppq = 0;
    bool lecture = false;
    if (auto* ph = getPlayHead())
        if (auto pos = ph->getPosition())
        {
            if (auto b = pos->getBpm()) bpm = *b;
            if (auto q = pos->getPpqPosition()) ppq = *q;
            lecture = pos->getIsPlaying();
        }
    engine.setTempo (bpm, lecture, ppq);

    const int n = buffer.getNumSamples();
    const int nIn = getTotalNumInputChannels();
    for (int ch = nIn; ch < buffer.getNumChannels(); ++ch) buffer.clear (ch, 0, n);

    float* left = buffer.getWritePointer (0);
    if (buffer.getNumChannels() > 1)
    {
        engine.process (left, buffer.getWritePointer (1), n);
    }
    else
    {
        // piste mono : on traite en stéréo et on garde le canal gauche
        if (monoScratch.getNumSamples() < n) monoScratch.setSize (1, n, false, false, true);
        float* tmp = monoScratch.getWritePointer (0);
        juce::FloatVectorOperations::copy (tmp, left, n);
        engine.process (left, tmp, n);
    }
}

juce::AudioProcessorEditor* SpectralProcessor::createEditor()
{
    return new SpectralEditor (*this);
}

void SpectralProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    if (auto xml = state.copyState().createXml())
        copyXmlToBinary (*xml, destData);
}

void SpectralProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    if (auto xml = getXmlFromBinary (data, sizeInBytes))
        if (xml->hasTagName (state.state.getType()))
            state.replaceState (juce::ValueTree::fromXml (*xml));
}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SpectralProcessor();
}
