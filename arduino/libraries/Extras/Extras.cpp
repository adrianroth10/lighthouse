#include "Extras.h"

bool isNight(double a0, double a1, double a2,
	     double b0, double b1, double b2,
	     int month, int day,
	     int hour, int minute, int second)
{
  long d = (month - 1) * 30 + day;
  long sunrise = (long)(a0 + a1 * d + a2 * d * d);
  long sunset = (long)(b0 + b1 * d + b2 * d * d);
  long s = (long)hour * 3600 + minute * 60 + second;
  return s > sunset || s < sunrise;
}
