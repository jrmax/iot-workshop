void setup() {
  pinMode(D4, OUTPUT);
  pinMode(D2, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(D2) == HIGH) {
    digitalWrite(D4, HIGH);
  } else {
    digitalWrite(D4, LOW);
  }
}

