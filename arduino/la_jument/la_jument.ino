#include <Time.h>
#include <Extras.h>

double a0 = 32421.890507333548;
double a1 = -110.37915299955947;
double a2 = 0.3159008870699137;
double b0 = 58871.6590053938;
double b1 = 221.07513018008868;
double b2 = -0.6533837940808941;
int fl = 700;
int fill = 15000 - 3 * 2 * fl;

void setup() {
  pinMode(13, OUTPUT);
  unsigned long time = 0;
  // Time zone for France
  time = time + 3600;
  setTime(time);
}

void loop() {
  if (isNight(a0, a1, a2, b0, b1, b2,
  	      month(), day(), hour(), minute(), second())) {
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
