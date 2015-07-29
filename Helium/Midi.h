#pragma once

#include "AppConfig.h"
#include "JuceHeader.h"
#include <stdint.h>
#include <condition_variable>
#include <memory>

class MidiPlayer
{

public:

	MidiPlayer()
	{
		juce::StringArray outputDevices = juce::MidiOutput::getDevices();

		std::cout << "Listing MIDI Interfaces: " << std::endl;
		for (int i = 0; i < outputDevices.size(); i++)
		{
			std::cout << i << " is " << outputDevices[i].toStdString().c_str() << std::endl;
		}

		// On dimitri's computer, arduino_midi is 2, but may change
		int desiredDevice = 1; 
		mOut.reset(juce::MidiOutput::openDevice(desiredDevice));

	};

	~MidiPlayer()
	{

	}

	// Channel = Group (0 or 1)
	// Pitch = Which LED (1-127, OR 128-256)
	// Velocity = Brightness of all 3 colors (white)
	void SendMidiMessage(uint8_t channel, uint8_t pitch, uint8_t velocity)
	{
		juce::MidiMessage message = juce::MidiMessage::noteOn(channel, pitch, velocity);
		mOut->sendMessageNow(message);
	}


private:

	std::unique_ptr<juce::MidiOutput> mOut;

};
