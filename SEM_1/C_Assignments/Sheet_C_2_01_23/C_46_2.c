#include <stdio.h>

typedef struct {
    int hour;
    int min;
    int second;
}time;

int update(int *val) {
    if(*val > 59) {
        *val = *val - 60;
        return 1;
    }
    return 0;
}

time addTime(time a, time b) {
    time temp;
    int c = 0;
    temp.second = a.second + b.second;
    c = update(&temp.second);
    temp.min = a.min + b.min + c;
    c = update(&temp.min);
    temp.hour = a.hour + b.hour + c;
    return temp;
}

int main()
{
    time t1, t2, t3;
    printf("\nEnter first time: ");
    scanf("%d:%d:%d", &t1.hour, &t1.min, &t1.second);
    printf("\nEnter second time: ");
    scanf("%d:%d:%d", &t2.hour, &t2.min, &t2.second);
    t3 = addTime(t1, t2);
    printf("\nAdded time is: %d:%d:%d", t3.hour, t3.min, t3.second);
}