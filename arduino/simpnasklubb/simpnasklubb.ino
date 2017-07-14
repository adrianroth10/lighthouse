#include <Time.h>

double a1 = 30898.220428979403;
double b1 = -201.21130741705954;
double c1 = 0.5812805865181612;
double a2 = 48024.53810250233;
double b2 = 312.4980718667971;
double c2 = -0.9201749693656163;
int lfl = 2500;
int fill = 8000 - lfl;

boolean isNight() {
  int d = month() * 30 + day();
  int sunrise = (int)(a1 + b1 * d + c1 * d * d);
  int sunset = (int)(a2 + b2 * d + c2 * d * d);
  int s = hour() * 60 + second();
  return s > sunset || s < sunrise;
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
