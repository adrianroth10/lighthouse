#include "IsNight.h"
#include "/usr/share/arduino/libraries/Wire/Wire.h"
#include "Arduino.h"

byte bcdToDec(byte val)
{
	return( (val/16*10) + (val%16) );
}

#define DS3231_I2C_ADDRESS 0x68
void getTime(int *second, int *minute, int *hour,
		int *day, int *month, int *year)
{
	Wire.beginTransmission(DS3231_I2C_ADDRESS);
	Wire.write(0);
	Wire.endTransmission();
	Wire.requestFrom(DS3231_I2C_ADDRESS, 7);
	// request seven bytes of data from DS3231 starting from register 00h
	*second = bcdToDec(Wire.read() & 0x7f);
	*minute = bcdToDec(Wire.read());
	*hour = bcdToDec(Wire.read() & 0x3f);
	Wire.read(); // skip weekday
	*day = bcdToDec(Wire.read());
	*month = bcdToDec(Wire.read());
	*year = bcdToDec(Wire.read());
}

bool isNight(double a0, double a1, double a2,
		double b0, double b1, double b2)
{
	int s, m, h, D, M, Y;
	getTime(&s, &m, &h, &D, &M, &Y);

	long d = ((long)M - 1) * 30 + (long)D;
	long sunrise = (long)(a0 + a1 * d + a2 * d * d);
	long sunset = (long)(b0 + b1 * d + b2 * d * d);
	long sec = (long)h * 3600 + (long)m * 60 + (long)s;
	return sec > sunset || sec < sunrise;
}
