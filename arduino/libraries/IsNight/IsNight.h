#ifndef _ISNIGHT
#ifdef __cplusplus
#define _ISNIGHT

void getTime(int *second, int *minute, int *hour,
		int *day, int *month, int *year);
bool isNight(double a0, double a1, double a2,
		double b0, double b1, double b2);
void sleep(long ms);
void day_sleep(double a0, double a1, double a2,
		double b0, double b1, double b2);
bool is_special_date(int *special_date, int length);

#endif // __cplusplus
#endif /* _ISNIGHT */
