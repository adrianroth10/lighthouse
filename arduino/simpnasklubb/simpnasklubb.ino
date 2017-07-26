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
  long d = (month() - 1) * 30 + day();
  long sunrise = (long)(a0 + a1 * d + a2 * d * d);
  long sunset = (long)(b0 + b1 * d + b2 * d * d);
  long s = (long)hour() * 3600 + minute() * 60 + second();
  return s > sunset || s < sunrise;
}

void setup() {
  pinMode(13, OUTPUT);
  unsigned long time = 0;
  // Time zone for Sweden
  time = time + 365 * 24 * 3600;
  setTime(time);
}

void loop() {
  if (isNight()) {
    digitalWrite(13, HIGH);
    delay(lfl);
    digitalWrite(13, LOW);
    delay(fill);
  } else {
  	delay(5 * 60000);
  }
}
