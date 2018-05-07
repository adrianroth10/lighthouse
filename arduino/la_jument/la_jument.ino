#include <Wire.h>
#include <IsNight.h>

const double a0 = 32311.827255221066;
const double a1 = -109.74735122541995;
const double a2 = .3159008870699148;
const double b0 = 59092.08075177983;
const double b1 = 219.76836259192618;
const double b2 = -.6533837940808918;
const int fl = 700;
const int fill = 15000 - 3 * 2 * fl;

void setup()
{
	Wire.begin();
	pinMode(13, OUTPUT);
}

void loop()
{
	if (isNight(a0, a1, a2, b0, b1, b2)) {
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
