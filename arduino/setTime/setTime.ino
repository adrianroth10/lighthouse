#include <Wire.h>
#include <IsNight.h>

void parseCurrentTime(byte *s, byte *m, byte *h,
		byte *D, byte *M, byte *Y)
{
	const char *datestr = __DATE__;
	const char *timestr = __TIME__;
	char s_month[5];
	int ls, lm, lh, lD, lY;
	static const char month_names[] = "JanFebMarAprMayJunJulAugSepOctNovDec";

	sscanf(datestr, "%s %d %d", s_month, &lD, &lY);
	sscanf(timestr, "%d:%d:%d", &lh, &lm, &ls);

	*s = ls;
	*m = lm;
	*h = lh;
	*D = lD;
	*M = (strstr(month_names, s_month)-month_names)/3 + 1;
	*Y = lY - 2000;
}

// Convert normal decimal numbers to binary coded decimal
byte decToBcd(byte val)
{
	return( (val/10*16) + (val%10) );
}

#define DS3231_I2C_ADDRESS 0x68
void setTime(byte second, byte minute, byte hour, 
		byte day, byte month, byte year)
{
	// sets time and date data to DS3231
	Wire.beginTransmission(DS3231_I2C_ADDRESS);
	Wire.write(0);
	Wire.write(decToBcd(second));
	Wire.write(decToBcd(minute));
	Wire.write(decToBcd(hour));
	Wire.write(decToBcd(1)); //ignoring weekday
	Wire.write(decToBcd(day));
	Wire.write(decToBcd(month));
	Wire.write(decToBcd(year));
	Wire.endTransmission();
}

void setup()
{
	Wire.begin();
	Serial.begin(9600);
	// set the initial time here:
	byte second, minute, hour, day, month, year;
	parseCurrentTime(&second, &minute, &hour,
			&day, &month, &year);
	//setTime(second, minute, hour, day, month, year);
}

void displayTime()
{
	int second, minute, hour, day, month, year;
	getTime(&second, &minute, &hour,
		&day, &month, &year);

	Serial.print(hour);
	Serial.print(":");
	if (minute<10) Serial.print("0");
	Serial.print(minute);
	Serial.print(":");
	if (second<10) Serial.print("0");
	Serial.print(second);
	Serial.print(" 20");
	Serial.print(year);
	Serial.print("-");
	if (month<10) Serial.print("0");
	Serial.print(month);
	Serial.print("-");
	if (day<10) Serial.print("0");
	Serial.println(day);
}

void loop()
{
	displayTime();
	delay(1000);
}
