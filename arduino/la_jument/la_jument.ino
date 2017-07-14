#include <Time.h>

double a1 = 30045.89050733355;
double b1 = -110.37915299955958;
double c1 = 0.31590088706991387;
double a2 = 56495.65900539382;
double b2 = 221.07513018008873;
double c2 = -0.6533837940808938;
int fl = 700;
int fill = 15000 - 3 * 2 * fl;

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
    for (int i = 0; i < 3; i++) {
      digitalWrite(13, HIGH);
      delay(fl);
      digitalWrite(13, LOW);
      delay(fl);
    }
    delay(fill);
  }
}
