#include "Midi.h"
#include <chrono>
#include <thread>
#include <iostream>  // For cin, cout, endl
#include <queue>     // for push on array

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"   //for image

#include <memory>

using namespace std;

///////////////////////////////////////////////////////////////////////////////
// Application Main
///////////////////////////////////////////////////////////////////////////////


struct Image
{
	std::shared_ptr<uint8_t> pixels;
	int width, height, comp;

	Image(const char * filename)
	{
		auto p = stbi_load(filename, &width, &height, &comp, 0);
		pixels = std::shared_ptr<uint8_t>(p, stbi_image_free);
	}

	uint8_t GetPixel(int x, int y, int c) const
	{
		return pixels.get()[y*(width*comp) + x*comp + c];
	}
};

int myColor = 0;

int main(int argc, char *argv[])
{

	Image image("rainbowDebug.jpg");
	int r,g,b;

	

	{
		MidiPlayer player;
		
		cout << "red: " << endl;
		cin >> r;
		cout << "green: " << endl;
		cin >> g;
		cout << "blue: " << endl;
		cin >> b;

		player.SendMidiMessage(1, 1, r);
		player.SendMidiMessage(2, 1, g);
		player.SendMidiMessage(3, 1, b);
		std::this_thread::sleep_for(std::chrono::milliseconds(7));

		/*for (int y = 0; y < 4; ++y)
		{
			for (int x = 0; x < 32; ++x)
			{
				//player.SendMidiMessage(1, x+(y*32), image.GetPixel(x,y,0));
				player.SendMidiMessage(1, x + (y * 32), image.GetPixel(x, y, 0));
				std::this_thread::sleep_for(std::chrono::milliseconds(7));

				player.SendMidiMessage(2, x + (y * 32), image.GetPixel(x, y, 1));
				std::this_thread::sleep_for(std::chrono::milliseconds(7));

				player.SendMidiMessage(3, x + (y * 32), image.GetPixel(x, y, 2));
				std::this_thread::sleep_for(std::chrono::milliseconds(7));
			}
		}*/

		//for (int i = 0; i < 127; i++)
		//{
			
			/*if (myColor < 250)
				myColor += 50;
			else
				myColor = 1;

			uint8_t red = image.GetPixel()

			//minimum color is 1
			// ( Which grouping of lights, array placement, color)
			player.SendMidiMessage(1, i, myColor);
			
			//7 seems to be minimum
			std::this_thread::sleep_for(std::chrono::milliseconds(7));*/
		//}
		std::cout << "Done Sending!" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}

	return 0;
}