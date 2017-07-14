void setup() {
    pinMode(13, OUTPUT);
}

void loop() {
  int fl = 700;
  int fill = 15000 - 3 * 2 * fl;
  for (int i = 0; i < 3; i++) {
    digitalWrite(13, HIGH);
    delay(fl);
    digitalWrite(13, LOW);
    delay(fl);
  }
  delay(fill);
}
