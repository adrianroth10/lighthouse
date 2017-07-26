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
  long d = (month() - 1) * 30 + day();
  long sunrise = (long)(a0 + a1 * d + a2 * d * d);
  long sunset = (long)(b0 + b1 * d + b2 * d * d);
  long s = (long)hour() * 3600 + minute() * 60 + second();
  return s > sunset || s < sunrise;
}

void setup() {
  pinMode(13, OUTPUT);
  unsigned long time = 0;
  // Time zone for France
  time = time + 365 * 24 * 3600;
  setTime(time);
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
  } else {
  	delay(5 * 60000);
  }
}
