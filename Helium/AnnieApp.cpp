#include "Midi.h"
#include <chrono>
#include <thread>
#include <iostream>  // For cin, cout, endl

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"   //for image

#include <memory>

using namespace std;

///////////////////////////////////////////////////////////////////////////////
// Application Main
///////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{

	{
		MidiPlayer player;
		int myColor = 1;

		for (int i = 0; i < 127; i++)
		{
			/*if (myColor < 250)
				myColor += 50;
			else
				myColor = 1;*/


			//minimum color is 1
			// ( Which grouping of lights, array placement, color)
			player.SendMidiMessage(1, i, myColor);
			
			//7 seems to be minimum
			std::this_thread::sleep_for(std::chrono::milliseconds(7));
		}
		std::cout << "Done Sending!" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}

	return 0;
}