// File: PluginEditor.h
#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

class ImageLoaderAudioProcessorEditor : public juce::AudioProcessorEditor,
                                        private juce::Button::Listener
{
public:
    ImageLoaderAudioProcessorEditor(ImageLoaderAudioProcessor&);
    ~ImageLoaderAudioProcessorEditor() override;

    void paint(juce::Graphics&) override;
    void resized() override;

private:
    void buttonClicked(juce::Button* button) override;
        void loadImageFromFile(const juce::File& file); // Declaration of the new method

        ImageLoaderAudioProcessor& audioProcessor;
        juce::TextButton loadButton{"Load Image"};
        juce::Image loadedImage;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ImageLoaderAudioProcessorEditor)
};
