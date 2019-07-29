#include <LM75A.h>
LM75A lm75a_sensor;
void setup(void) {
  Serial.begin(115200);
}
void loop() {
  float temperature_in_degrees = lm75a_sensor.getTemperatureInDegrees();
  if (temperature_in_degrees == INVALID_LM75A_TEMPERATURE) {
    Serial.println("Error while getting temperature");
  } else {
    Serial.print("Temperatur in C: ");
    Serial.print(temperature_in_degrees);
    Serial.print(" - Temperatur in F: ");
    Serial.print(LM75A::degreesToFahrenheit(temperature_in_degrees));
  }
  delay(1000);
}
