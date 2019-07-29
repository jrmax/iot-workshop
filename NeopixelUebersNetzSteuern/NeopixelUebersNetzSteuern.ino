#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <Adafruit_NeoPixel.h>

#define PIN            D5
#define NUMPIXELS      16

ESP8266WebServer server(80);

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void handleRoot() {
  server.send(200, "text/html", "<h1>You are connected!</h1>");
}

void setLight(uint32_t color, uint8_t wait) {
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, color);
    pixels.show();
    delay(wait);
  }
}

void handleOn() {
  int red = server.arg("red").toInt();
  int green = server.arg("green").toInt();
  int blue = server.arg("blue").toInt();
  setLight(pixels.Color(red, green, blue), 50);
  server.send(200, "text/html", "<h1>LED on</h1>");
}

void handleOff() {
  server.send(200, "text/html", "<h1>LED off</h1>");
  setLight(pixels.Color(0, 0, 0), 0);
}

void setup() {
  Serial.begin(115200);
  pixels.begin();
  setLight(pixels.Color(0, 0, 0), 0);

  delay(1000);

  Serial.println();
  Serial.print("Configuring access point...");
  WiFi.softAP("FooBar");

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  
  server.on("/", handleRoot);
  server.on("/on",  handleOn);
  server.on("/off", handleOff);
  server.begin();
  
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
