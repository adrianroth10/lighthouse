#include <Wire.h>
#include <IsNight.h>

const double a0 = 33073.590402;
const double a1 = -200.048746;
const double a2 = 0.581281;
const double b0 = 50712.115999;
const double b1 = 310.657722;
const double b2 = -0.920175;
const int lfl = 2500;
const int fill = 8000 - lfl;

const int pin = 10;

void setup()
{
  Wire.begin();
	pinMode(pin, OUTPUT);
}

void loop()
{
  if (isNight(a0, a1, a2, b0, b1, b2)) {
    digitalWrite(pin, HIGH);
    delay(lfl);
    digitalWrite(pin, LOW);
    delay(fill);
  } else {
    sleep(296000);  // 37 * 8 seconds ~ 5 min
  }
}
