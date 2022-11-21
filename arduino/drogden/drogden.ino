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

#define pin 13

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

void setup()
{
  //Serial.begin(9600);
	Wire.begin();
	pinMode(pin, OUTPUT);
  setTime(0, 53, 13, 6, 12, 2021);
}

void loop()
{
  //displayTime();
	if (isNight(a0, a1, a2, b0, b1, b2)) {
    //Serial.println("Night");
		for (int i = 0; i < 3; i++) {
      digitalWrite(pin, LOW);
			delay(fl);
      digitalWrite(pin, HIGH);
      delay(fl);
		}
		//sleep(fill);
    delay(fill);
	} else {
    //Serial.println(secs_til_night(b0, b1, b2));
    digitalWrite(pin, LOW);
    delay(200);
    //day_sleep(b0, b1, b2);
    delay(300000);
	}
}
