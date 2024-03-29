#include "IsNight.h"
#include "LowPower.h"
#include "Wire.h"
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

int calculate_days(int M, int D)
{
	long d = ((long)M - 1) * 30 + (long)D;
	return d;
}

bool isNight(double a0, double a1, double a2,
		double b0, double b1, double b2)
{
	int s, m, h, D, M, Y;
	getTime(&s, &m, &h, &D, &M, &Y);

	long d = calculate_days(M, D);
	long sunrise = (long)(a0 + a1 * d + a2 * d * d);
	long sunset = (long)(b0 + b1 * d + b2 * d * d);
	long sec = (long)h * 3600 + (long)m * 60 + (long)s;
	return sec > sunset || sec < sunrise;
}

enum {
	TWO = 2000,
	FOUR = 4000,
	EIGHT = 8000
}; 

void sleep(long ms) {
  if (ms <= 0) return;
  else if (ms <= TWO) {
    delay(ms);
    return;
  }
  long ms_compensation = 0.0447 * ms;
	int n_eight, n_four, n_two, rest;

  ms = ms - ms_compensation;
	n_eight = ms / EIGHT;
	rest = ms % EIGHT;
	n_four = rest / FOUR;
	rest = rest % FOUR;
	n_two = rest / TWO;
	rest = rest % TWO;
	for (int i = 0; i < n_eight; i++) {
		LowPower.powerDown(SLEEP_8S, ADC_ON, BOD_OFF);
	}
	if (n_four) LowPower.powerDown(SLEEP_4S, ADC_ON, BOD_OFF);
	if (n_two) LowPower.powerDown(SLEEP_2S, ADC_ON, BOD_OFF);
	delay(rest);
}

long secs_til_night(double b0, double b1, double b2)
{
	int s, m, h, D, M, Y;
	getTime(&s, &m, &h, &D, &M, &Y);
	long d = calculate_days(M, D);
	long sunset = (long)(b0 + b1 * d + b2 * d * d);
	long sec = (long)h * 3600 + (long)m * 60 + (long)s;
  return sunset - sec;
}

void day_sleep(double b0, double b1, double b2)
{
  long secs;
  secs = secs_til_night(b0, b1, b2);
  sleep(secs * 1000);
  secs = secs_til_night(b0, b1, b2);
  delay(secs * 1000 + 1000); // to make sure the night has begun
}

bool is_special_date(int *special_date, int length)
{
	int s, m, h, D, M, Y;
	getTime(&s, &m, &h, &D, &M, &Y);
	for (int i = 0; i < length; i++) {
		if (M == special_date[2*i] && D == special_date[2*i + 1]) {
			return 1;
		}
	}
	return 0;
}
