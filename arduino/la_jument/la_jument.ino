#include <Time.h>

double a0 = 32421.890507333548;
double a1 = -110.37915299955947;
double a2 = 0.3159008870699137;
double b0 = 58871.6590053938;
double b1 = 221.07513018008868;
double b2 = -0.6533837940808941;
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
