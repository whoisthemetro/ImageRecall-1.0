// File: PluginProcessor.cpp
#include "PluginProcessor.h"
#include "PluginEditor.h"

ImageLoaderAudioProcessor::ImageLoaderAudioProcessor()
     : AudioProcessor(BusesProperties().withOutput("Output", juce::AudioChannelSet::stereo(), true))
{}

ImageLoaderAudioProcessor::~ImageLoaderAudioProcessor() {}

void ImageLoaderAudioProcessor::prepareToPlay(double, int) {}
void ImageLoaderAudioProcessor::releaseResources() {}
bool ImageLoaderAudioProcessor::isBusesLayoutSupported(const BusesLayout& layouts) const
{
    return layouts.getMainOutputChannelSet() == juce::AudioChannelSet::stereo();
}

void ImageLoaderAudioProcessor::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer&)
{
    buffer.clear();
}

juce::AudioProcessorEditor* ImageLoaderAudioProcessor::createEditor() { return new ImageLoaderAudioProcessorEditor(*this); }
bool ImageLoaderAudioProcessor::hasEditor() const { return true; }
const juce::String ImageLoaderAudioProcessor::getName() const { return JucePlugin_Name; }
bool ImageLoaderAudioProcessor::acceptsMidi() const { return false; }
bool ImageLoaderAudioProcessor::producesMidi() const { return false; }
bool ImageLoaderAudioProcessor::isMidiEffect() const { return false; }
double ImageLoaderAudioProcessor::getTailLengthSeconds() const { return 0.0; }
int ImageLoaderAudioProcessor::getNumPrograms() { return 1; }
int ImageLoaderAudioProcessor::getCurrentProgram() { return 0; }
void ImageLoaderAudioProcessor::setCurrentProgram(int) {}
const juce::String ImageLoaderAudioProcessor::getProgramName(int) { return {}; }
void ImageLoaderAudioProcessor::changeProgramName(int, const juce::String&) {}
void ImageLoaderAudioProcessor::getStateInformation(juce::MemoryBlock&) {}
void ImageLoaderAudioProcessor::setStateInformation(const void*, int) {}

// Function to create an instance of the plugin
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new ImageLoaderAudioProcessor();
}
