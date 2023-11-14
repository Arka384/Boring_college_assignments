#include <stdio.h>
#include <math.h>

double Organic(double kloc);
double Semi_Detached(double kloc);
double Embedded(double kloc);

int main() {
    double kloc;

    printf("Enter KLOC: ");
    scanf("%lf", &kloc);

    printf("_______For Organic________\n");
    double effort = Organic(kloc);
    double time = 2.5 * pow(effort, 0.38);
    double person = effort / time;
    printf("Effort required: %.0lf person-months\n", round(effort));
    printf("Time required: %.0lf months\n", round(time));
    printf("Person required: %d\n", (int)(person + 0.5));

    printf("_______For Semi_Detached________\n");
    effort = Semi_Detached(kloc);
    time = 2.5 * pow(effort, 0.35);
    person = effort / time;
    printf("Effort required: %.0lf person-months\n", round(effort));
    printf("Time required: %.0lf months\n", round(time));
    printf("Person required: %d\n", (int)(person + 0.5));

    printf("_______For Embedded________\n");
    effort = Embedded(kloc);
    time = 2.5 * pow(effort, 0.32);
    person = effort / time;
    printf("Effort required: %.0lf person-months\n", round(effort));
    printf("Time required: %.0lf months\n", round(time));
    printf("Person required: %d\n", (int)(person + 0.5));

    return 0;
}	

double Organic(double kloc) {
    double a = 2.4;
    double b = 1.05;
    double c = 2.5;
    double d = 0.38;
    double E = a * pow(kloc, b);
    double time = c * pow(E, d);
    double person_required = E / time;
    return E;
}

double Semi_Detached(double kloc) {
    double a = 3.0;
    double b = 1.12;
    double c = 2.5;
    double d = 0.35;
    double E = a * pow(kloc, b);
    double time = c * pow(E, d);
    double person_required = E / time;
    return E;
}

double Embedded(double kloc) {
    double a = 3.6;
    double b = 1.20;
    double c = 2.5;
    double d = 0.32;
    double E = a * pow(kloc, b);
    double time = c * pow(E, d);
    double person_required = E / time;
    return E;
}