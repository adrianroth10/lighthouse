#include <Wire.h>
#include <IsNight.h>

const double a0 = 32311.827255;
const double a1 = -109.747351;
const double a2 = 0.315901;
const double b0 = 59092.080752;
const double b1 = 219.768363;
const double b2 = -0.653384;
const int fl = 700;
const int fill = 15000 - 3 * 2 * fl;

const int pin = 13;

void setup()
{
  // Serial.begin(9600);
	Wire.begin();
	pinMode(pin, OUTPUT);
}

void loop()
{
	if (isNight(a0, a1, a2, b0, b1, b2)) {
    Serial.println("Night");
		for (int i = 0; i < 3; i++) {
			digitalWrite(pin, HIGH);
			delay(fl);
			digitalWrite(pin, LOW);
			delay(fl);
		}
		sleep(fill);
	} else {
    sleep(296000);  // 37 * 8 seconds ~ 5 min
	}
}
