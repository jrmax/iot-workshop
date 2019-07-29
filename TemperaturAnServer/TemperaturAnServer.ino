#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <LM75A.h>

const char* ssid = "SSID";
const char* password = "Geheim";

LM75A lm75a_sensor;

void setup () {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print("Connecting..");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    float temperature = lm75a_sensor.getTemperatureInDegrees();
    HTTPClient http;
    http.begin("http://TUTU:8080/log");
    http.addHeader("Content-Type", "application/json");
    String payload = "{\"name\":\"julian\",\"temperature\":\"" + String(temperature) + "\"}";
    int httpCode = http.POST(payload);
    Serial.println(httpCode);
    if (httpCode > 0) {
      String payload = http.getString();
      Serial.println(payload);
    }
    http.end();
  }
  delay(3000);
}

