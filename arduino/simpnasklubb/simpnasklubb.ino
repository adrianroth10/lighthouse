int a1, b1, c1, a2, b2, c2;
a1 = 30898.220428979403;
b1 = -201.21130741705954;
c1 = 0.5812805865181612;
a2 = 48024.53810250233;
b2 = 312.4980718667971;
c2 = -0.9201749693656163;
int lfl = 2500;
int fill = 8000 - lfl;

boolean isNigth() {
  return TRUE;
}

void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  if (isNight()) {
    digitalWrite(13, HIGH);
    delay(lfl);
    digitalWrite(13, LOW);
    delay(fill);
  }
}
