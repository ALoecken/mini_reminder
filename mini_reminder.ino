#include "SPI.h"

/*** LIGHT SETUP ***/
#include <Adafruit_NeoPixel.h>

// Choose which 2 pins you will use for output.
#define LED_DATA_PIN  5    // Yellow wire on Adafruit Pixel
#define NUM_PIXELS 1
// Set the first variable to the NUMBER of pixels.
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_PIXELS, LED_DATA_PIN, NEO_GRB + NEO_KHZ800);

/*** SOUND SETUP ***/
#include "PCM.h"
#define SOUND_PIN 11 // 10 or 9 on mega, 11 or 3 on uno, 
#define SAMPLE_RATE 16000 // the processor of the 3V Mini Pro is half as fast --> sample rate 16000 instead of 8000
// load sounds
//#include "tippen.h"
#include "dong.h"
//#include "tippen_small.h"

#define LIGHT_MILLIS 30000
#define SOUND_MILLIS 5000
unsigned long target_milli = 0;
bool first_run = true;

void setup() {
  initSpeaker(SOUND_PIN, SAMPLE_RATE);
  
  // startPlayback(dong_sound, sizeof(dong_sound));
  // Init LEDs
  strip.begin();
  strip.show();
}


void loop() {
  // get millis and play sound
  unsigned long current_millis = millis();
  long millis_since = target_milli - current_millis;
  if (millis_since < 0) {
    target_milli = current_millis + LIGHT_MILLIS + SOUND_MILLIS;
   if (!first_run){
      startPlayback(dong_sound, sizeof(dong_sound));
    }
    first_run = false;
  } 
  
  if (!isPlaying()){
    color_change(millis_since);
  } else {
    strip.setPixelColor(0, strip.Color(0 ,255, 0));
    strip.show(); 
  }
}

void color_change( long millis_since) {
  int green = (255 * millis_since ) / (LIGHT_MILLIS ) ;
  if (green > 255) green = 255; 
  if (green < 0) green = 0;
  strip.setPixelColor(0, strip.Color( green, 255-green, 0));
  strip.show();   // write all the pixels out
  delay (20);
}

/*
// Slightly different, this one makes the rainbow wheel equally distributed 
// along the chain
void rainbowCycle(uint8_t wait) {
  int i, j;
  
  for (j=0; j < 256 * 5; j++) {     // 5 cycles of all 25 colors in the wheel
    for (i=0; i < strip.numPixels(); i++) {
      // tricky math! we use each pixel as a fraction of the full 96-color wheel
      // (thats the i / strip.numPixels() part)
      // Then add in j which makes the colors go around per pixel
      // the % 96 is to make the wheel cycle around
      strip.setPixelColor(i, Wheel( ((i * 256 / strip.numPixels()) + j) % 256) );
    }  
    strip.show();   // write all the pixels out
    delay(wait);
  }
}


// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else if(WheelPos < 170) {
    WheelPos -= 85;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  }
}

*/
