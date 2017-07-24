#include <Time.h>

double a0 = 30045.89050733355;
double a1 = -110.37915299955958;
double a2 = 0.31590088706991387;
double b0 = 56495.65900539382;
double b1 = 221.07513018008873;
double b2 = -0.6533837940808938;
int fl = 700;
int fill = 15000 - 3 * 2 * fl;

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
    for (int i = 0; i < 3; i++) {
      digitalWrite(13, HIGH);
      delay(fl);
      digitalWrite(13, LOW);
      delay(fl);
    }
    delay(fill);
  }
}
