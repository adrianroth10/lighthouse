#include <IsNight.h>

const double a0 = 33073.59040214887;
const double a1 = -200.04874624402333;
const double a2 = .5812805865181618;
const double b0 = 50712.11599939978;
const double b1 = 310.6577219280652;
const double b2 = -.9201749693656144;
const int lfl = 2500;
const int fill = 8000 - lfl;

void setup()
{
	pinMode(13, OUTPUT);
}

void loop()
{
	if (isNight(a0, a1, a2, b0, b1, b2)) {
		digitalWrite(13, HIGH);
		delay(lfl);
		digitalWrite(13, LOW);
		delay(fill);
	} else {
		delay(5 * 60000);
	}
}
