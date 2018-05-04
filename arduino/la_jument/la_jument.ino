#include <IsNight.h>

const double a0 = 32421.890507333548;
const double a1 = -110.37915299955947;
const double a2 = 0.3159008870699137;
const double b0 = 58871.6590053938;
const double b1 = 221.07513018008868;
const double b2 = -0.6533837940808941;
const int fl = 700;
const int fill = 15000 - 3 * 2 * fl;

void setup()
{
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
