#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
const char* ssid = "SSID";
const char* password = "Geheim";

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
    HTTPClient http;
    http.begin("http://TUTU:8080/log");
    int httpCode = http.GET();
    Serial.println(httpCode);
    if (httpCode > 0) {
      String payload = http.getString();
      Serial.println(payload);
    }
    http.end();
  }
  delay(30000);
}

