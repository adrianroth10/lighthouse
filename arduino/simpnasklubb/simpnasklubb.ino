void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  int lfl = 2500;
  int fill = 8000 - lfl;
  digitalWrite(13, HIGH);
  delay(lfl);
  digitalWrite(13, LOW);
  delay(fill);
}
