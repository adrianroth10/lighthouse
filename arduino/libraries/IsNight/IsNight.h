#ifndef _ISNIGHT
#ifdef __cplusplus
#define _ISNIGHT

void getTime(int *second, int *minute, int *hour,
		int *day, int *month, int *year);
bool isNight(double a0, double a1, double a2,
		double b0, double b1, double b2);
void sleep(int ms);
void day_sleep(int ms);

#endif // __cplusplus
#endif /* _ISNIGHT */
