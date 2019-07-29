#include <Adafruit_NeoPixel.h>
#include <LM75A.h>

#define PIN D4
#define NUMPIXELS 16

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
LM75A lm75a_sensor;

void setup() {
  pixels.begin();
  pinMode(D5, OUTPUT);
  digitalWrite(D5, LOW);
  Serial.begin(115200);
}

void loop() {
  float temperature_in_degrees = lm75a_sensor.getTemperatureInDegrees();
  Serial.println(temperature_in_degrees);
  int tempInt = (int)temperature_in_degrees;
  int steps = tempInt / 2;
  for (int i = 0; i < NUMPIXELS; i++) {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    if (i < steps) {
      pixels.setPixelColor(i, pixels.Color(255, 255 - (15 * i), 0));
    } else {
      pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    }
    pixels.show();
    delay(50);
  }
}

