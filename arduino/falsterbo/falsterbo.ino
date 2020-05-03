#include <Wire.h>
#include <IsNight.h>

const double a0 = 32313.729583;
const double a1 = -158.733227;
const double a2 = 0.460269;
const double b0 = 53972.20695;
const double b1 = 269.366564;
const double b2 = -0.798887;
const int fl = 700;
const int fill = 12000 - 4 * 2 * fl;

int special_days[] = {5, 4};
int special_days_length = 1;
// int special_days[] = {4, 5,  4, 10,  5, 15,  8, 19};
// int special_days_length = 4;

void setup()
{
	Wire.begin();
	pinMode(10, OUTPUT);
	pinMode(11, OUTPUT);
}

void set_pins(int value)
{
	for (int pin = 10; pin < 12; pin++) {
		digitalWrite(pin, value);
	}
}

void loop()
{
	if (!is_special_day(special_days, special_days_length)) {
	  day_sleep(a0, a1, a2, b0, b1, b2);
	}

	for (int i = 0; i < 4; i++) {
		set_pins(HIGH);
		delay(fl);
		set_pins(LOW);
		delay(fl);
	}
	delay(fill);
}
