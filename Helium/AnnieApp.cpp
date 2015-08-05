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

int myColor = 255;
int arrayPos;
int x, y;

Image image("redToOrange.jpg");

int Map(int value, int inMin, int inMax, int outMin, int outMax){
	return(value - inMin) * (outMax - outMin) / (inMax - inMin) + outMin;
}

void UpdateScreen()
{
	MidiPlayer player;
	
	for (int y = 0; y < 8; ++y)
	{
		for (int x = 0; x < 32; ++x)
		{
			int otherY = Map(y, 0, 7, 0, image.height - 2);
			int otherX = Map(x, 0, 31, 0, image.width - 2);
		for (int c = 0; c < 3; ++c)
			{
				int sample1 = image.GetPixel(otherX, otherY, c);
				int sample2 = image.GetPixel(otherX + 1, otherY, c);
				int sample3 = image.GetPixel(otherX, otherY + 1, c);
				int sample4 = image.GetPixel(otherX + 1, otherY + 1, c);
				int sampleAverage = (sample1 + sample2 + sample3 + sample4) / 4;

				if (c == 0)
				{
					cout << "x: " << x << " y: " << y << " red: "<< sampleAverage << endl;
				}

				if (x + (y * 32) < 128)
					player.SendMidiMessage(c + 1, x + (y * 32), sampleAverage);
				if (x + (y * 32) >= 128)
					player.SendMidiMessage(c + 4, (x + (y * 32)) - 128, sampleAverage);
				std::this_thread::sleep_for(std::chrono::milliseconds(6));
			}
		}
	}
}



int main(int argc, char *argv[])
{
	UpdateScreen();


	//while(1){
		
		
		/*cout << "x? " << endl;
		cin >> x;
		cout << "y? " << endl;
		cin >> y;
		cout << "  red: " << (int)image.GetPixel(x, y, 0) << "  green: " << (int)image.GetPixel(x, y, 1) << "  blue: " << (int)image.GetPixel(x, y, 2) << endl;
		*/

		/*cout << "array Position? " << arrayPos << endl;
		cin >> arrayPos;
		cout << "r? " << endl;
		cin >> r;
		cout << "g? " << endl;
		cin >> g;
		cout << "b? " << endl;
		cin >> b;

		player.SendMidiMessage(1, arrayPos, r);
		player.SendMidiMessage(2, arrayPos, g);
		player.SendMidiMessage(3, arrayPos, b);
		std::this_thread::sleep_for(std::chrono::milliseconds(7));*/


		
		

		/*for (int y = 0; y < 4; y++)
		{
			for (int x = 0; x < 32; x++)
			{
				player.SendMidiMessage(1, x + (y * 32), (int)image.GetPixel(x, y, 0));
				player.SendMidiMessage(2, x + (y * 32), (int)image.GetPixel(x, y, 1));
				player.SendMidiMessage(3, x + (y * 32), (int)image.GetPixel(x, y, 2));
				std::this_thread::sleep_for(std::chrono::milliseconds(7));
			}
		}*/

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
	//	std::cout << "Done Sending!" << std::endl;
	//	std::this_thread::sleep_for(std::chrono::milliseconds(50));
	//}

	
	return 0;
}