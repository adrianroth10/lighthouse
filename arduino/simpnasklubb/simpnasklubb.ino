#include <avr/power.h>
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

void setup()
{
	CLKPR = 0x80;
	CLKPR = 0x08;
	// clock_prescale_set(256);
	power_adc_disable();
	Wire.begin();
	pinMode(13, OUTPUT);
}

void loop()
{
	if (isNight(a0, a1, a2, b0, b1, b2)) {
		digitalWrite(13, HIGH);
		sleep(lfl);
		digitalWrite(13, LOW);
		sleep(fill);
	} else {
		day_sleep(b0, b1, b2);
	}
}
