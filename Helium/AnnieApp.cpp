#include "Midi.h"
#include <chrono>
#include <thread>

using namespace std;

///////////////////////////////////////////////////////////////////////////////
// Application Main
///////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{

	{
		MidiPlayer player;

		for (int i = 0; i < 127; i++)
		{
			player.SendMidiMessage(1, i, 50);
			std::this_thread::sleep_for(std::chrono::milliseconds(4));
		}
		std::cout << "Done Sending!" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
	}

	return 0;
}