#include <gamma.h>
#include <Adafruit_NeoPixel.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_GFX.h>
#include <math.h>

#include <MIDI.h>
#include <midi_Defs.h>
#include <midi_Message.h>
#include <midi_Namespace.h>
#include <midi_Settings.h>

MIDI_CREATE_DEFAULT_INSTANCE();

#define PIN 6

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(32, 8, PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
  NEO_GRB            + NEO_KHZ800);

int x;
int y;
    
// Note on message will control all LEDS (8 * 16)
// Channel 0 = 1-127
// Channel 1 = 128-256
void HandleNoteOn(byte channel, byte pitch, byte velocity) 
{ 
    y = ceil(pitch / 32);
    
    matrix.drawPixel(pitch - (32*y),y,matrix.Color(velocity, 0, 0));
    matrix.show();  
}

void setup()
{
  matrix.begin();
  matrix.setBrightness(32);
  
  MIDI.begin(MIDI_CHANNEL_OMNI);
  MIDI.setHandleNoteOn(HandleNoteOn); 
  
  delay(250);
  
  matrix.fillScreen(0);
  matrix.setCursor(0,0);
  
}

void loop()
{
  unsigned long currentMillis = millis();

  MIDI.read();
}

