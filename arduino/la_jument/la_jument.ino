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
	Wire.begin();
	pinMode(pin, OUTPUT);
}

void loop()
{
	if (isNight(a0, a1, a2, b0, b1, b2)) {
		for (int i = 0; i < 3; i++) {
			digitalWrite(pin, HIGH);
			sleep(fl);
			digitalWrite(pin, LOW);
			sleep(fl);
		}
		sleep(fill);
	} else {
    day_sleep(b0, b1, b2);
	}
}
