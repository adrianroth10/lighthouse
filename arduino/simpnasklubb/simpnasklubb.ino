#include <IsNight.h>

const double a0 = 33274.22042897941;
const double a1 = -201.21130741705943;
const double a2 = 0.581280586518161;
const double b0 = 50400.538102502316;
const double b1 = 312.4980718667972;
const double b2 = -0.9201749693656168;
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
