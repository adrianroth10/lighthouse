#include <Wire.h>
#include <IsNight.h>

const double a0 = 32313.729583;
const double a1 = -158.733227;
const double a2 = 0.460269;
const double b0 = 53972.20695;
const double b1 = 269.366564;
const double b2 = -0.798887;
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
      digitalWrite(pin, LOW);
			delay(fl);
      digitalWrite(pin, HIGH);
      delay(fl);
		}
		sleep(fill);
	} else {
    digitalWrite(pin, LOW);
    day_sleep(b0, b1, b2);
    //int stn = secs_til_night(b0, b1, b2);
    //if (stn > 3600) {
    //  sleep(3600000); // 1h
    //} else {
    //  sleep(300000); // 5 mins
    //} 
	}
}
