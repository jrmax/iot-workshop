#include <Adafruit_NeoPixel.h>
#define PIN D4
#define NUMPIXELS 16
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int delayVal = 250;

void setup() {
  pixels.begin();
}

void loop() {
  for (int i = 0; i < NUMPIXELS; i++) {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0, 150, 0));
    pixels.show();
    delay(delayVal);
  }
}

