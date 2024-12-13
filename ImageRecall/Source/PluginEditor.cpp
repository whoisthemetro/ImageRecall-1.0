// File: PluginEditor.cpp
#include "PluginEditor.h"

ImageLoaderAudioProcessorEditor::ImageLoaderAudioProcessorEditor(ImageLoaderAudioProcessor& p)
    : AudioProcessorEditor(&p), audioProcessor(p)
{
    addAndMakeVisible(loadButton);
    loadButton.addListener(this);
    setSize(400, 300);
}

ImageLoaderAudioProcessorEditor::~ImageLoaderAudioProcessorEditor() {}

void ImageLoaderAudioProcessorEditor::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colours::black);

    if (loadedImage.isValid())
    {
        auto bounds = getLocalBounds();
        g.drawImage(loadedImage, bounds.toFloat());
    }
    else
    {
        g.setColour(juce::Colours::white);
        g.setFont(20.0f);
        g.drawFittedText("Load an image...", getLocalBounds(), juce::Justification::centred, 1);
    }
}

void ImageLoaderAudioProcessorEditor::resized()
{
    loadButton.setBounds(10, 10, 100, 30);
}

void ImageLoaderAudioProcessorEditor::buttonClicked(juce::Button* button)
{
    DBG("Button clicked!");
    if (button == &loadButton)
    {
        DBG("Load Image button confirmed!");
        juce::FileChooser chooser("Select an image file...", {}, "*.png;*.jpg;*.jpeg;*.bmp");

        chooser.launchAsync(
            juce::FileBrowserComponent::openMode | juce::FileBrowserComponent::canSelectFiles,
            [this](const juce::FileChooser& fc)
            {
                auto file = fc.getResult();
                if (file.existsAsFile())
                {
                    DBG("File selected: " + file.getFullPathName());
                    loadImageFromFile(file);
                }
                else
                {
                    DBG("No file selected.");
                }
            });
    }
}

void ImageLoaderAudioProcessorEditor::loadImageFromFile(const juce::File& file)
{
    auto image = juce::ImageFileFormat::loadFrom(file);

    if (image.isValid())
    {
        loadedImage = image;
        repaint();
    }
    else
    {
        juce::AlertWindow::showMessageBoxAsync(juce::AlertWindow::WarningIcon, "Error", "Invalid image file!");
    }
}
