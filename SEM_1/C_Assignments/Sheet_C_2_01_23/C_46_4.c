#include <stdio.h>

typedef struct Date {
	int day;
	int month;
	int year;
}Date;

int compareDate(Date a, Date b) {
	if(a.day != b.day || a.month != b.month || a.year != b.year)
		return 0;
	return 1;
}

int main()
{
	Date d1, d2;
	printf("Enter date 1: ");
	scanf("%d/%d/%d", &d1.day, &d1.month, &d1.year);
	
	printf("Enter date 2: ");
	scanf("%d/%d/%d", &d2.day, &d2.month, &d2.year);
	
	int f = compareDate(d1, d2);
	if(f)
		printf("\nTwo dates are equal");
	else
		printf("\nTwo dates are not equal");
}
