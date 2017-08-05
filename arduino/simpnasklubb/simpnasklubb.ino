#include <Time.h>
#include <Extras.h>

double a0 = 33274.22042897941;
double a1 = -201.21130741705943;
double a2 = 0.581280586518161;
double b0 = 50400.538102502316;
double b1 = 312.4980718667972;
double b2 = -0.9201749693656168;
int lfl = 2500;
int fill = 8000 - lfl;

void setup() {
  pinMode(13, OUTPUT);
  unsigned long time = 0;
  setTime(time);
}

void loop() {
  if (isNight(a0, a1, a2, b0, b1, b2,
  	      month(), day(), hour(), minute(), second())) {
    digitalWrite(13, HIGH);
    delay(lfl);
    digitalWrite(13, LOW);
    delay(fill);
  } else {
  	delay(5 * 60000);
  }
}
