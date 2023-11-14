#include <stdio.h>
#include <math.h>

double Organic(double kloc, double eaf);
double Semi_Detached(double kloc, double eaf);
double Embedded(double kloc, double eaf);

int main() {
    double kloc, eaf = 1.0;
    // double costDrivers[15] = {1.15, 1.08, 1.15, 1.11, 1.06, 1.15, 1.07, 0.86, 
    //                           0.91, 0.86, 0.90, 0.95, 0.91, 0.91, 1.10};
    double costDrivers[15];

    printf("Enter KLOC: ");
    scanf("%lf", &kloc);

    printf("Enter values of 15 cost dirvers(space separated): \n");
    for(int i=0;i<15;i++)
        scanf("%lf", &costDrivers[i]);

    // calculate the effort adjustment factor
    for(int i=0;i<15;i++)
        eaf *= costDrivers[i];

    // find the value of eaf *****

    printf("_______For Organic________\n");
    double effort = Organic(kloc, eaf);
    double time = 2.5 * pow(effort, 0.38);
    double person = effort / time;
    printf("Effort required: %.0lf person-months\n", round(effort));
    printf("Time required: %.0lf months\n", round(time));
    printf("Person required: %d\n", (int)(person + 0.5));

    printf("_______For Semi_Detached________\n");
    effort = Semi_Detached(kloc, eaf);
    time = 2.5 * pow(effort, 0.35);
    person = effort / time;
    printf("Effort required: %.0lf person-months\n", round(effort));
    printf("Time required: %.0lf months\n", round(time));
    printf("Person required: %d\n", (int)(person + 0.5));

    printf("_______For Embedded________\n");
    effort = Embedded(kloc, eaf);
    time = 2.5 * pow(effort, 0.32);
    person = effort / time;
    printf("Effort required: %.0lf person-months\n", round(effort));
    printf("Time required: %.0lf months\n", round(time));
    printf("Person required: %d\n", (int)(person + 0.5));

    return 0;
}	

double Organic(double kloc, double eaf) {
    double a = 3.2;
    double b = 1.05;
    double c = 2.5;
    double d = 0.38;
    double E = a * pow(kloc, b) * eaf;
    double time = c * pow(E, d);
    double person_required = E / time;
    return E;
}

double Semi_Detached(double kloc, double eaf) {
    double a = 3.0;
    double b = 1.12;
    double c = 2.5;
    double d = 0.35;
    double E = a * pow(kloc, b) * eaf;
    double time = c * pow(E, d);
    double person_required = E / time;
    return E;
}

double Embedded(double kloc, double eaf) {
    double a = 2.8;
    double b = 1.20;
    double c = 2.5;
    double d = 0.32;
    double E = a * pow(kloc, b) * eaf;
    double time = c * pow(E, d);
    double person_required = E / time;
    return E;
}