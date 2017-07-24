#include <Time.h>

double a0 = 30898.220428979403;
double a1 = -201.21130741705954;
double a2 = 0.5812805865181612;
double b0 = 48024.53810250233;
double b1 = 312.4980718667971;
double b2 = -0.9201749693656163;
int lfl = 2500;
int fill = 8000 - lfl;

boolean isNight() {
  int d = month() * 30 + day();
  int sunrise = (int)(a0 + a1 * d + a2 * d * d);
  int sunset = (int)(b0 + b1 * d + b2 * d * d);
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
