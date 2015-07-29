#include "Midi.h"
#include <chrono>
#include <thread>

MidiPlayer player;

using namespace std;

///////////////////////////////////////////////////////////////////////////////
// Application Main
///////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
	while(true)
	{
		for (int i = 0; i < 127; i++)
		{
			player.SendMidiMessage(1, i, 255);
			std::this_thread::sleep_for(std::chrono::milliseconds(150));
		}
		std::cout << "Done Sending!" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(250));
	}
	return 0;
}