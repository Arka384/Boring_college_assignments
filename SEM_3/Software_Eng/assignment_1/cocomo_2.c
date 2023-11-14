#include <stdio.h>
#include <math.h>

int calculateObjectPoints(int screens, int reports, int components);
float calculateNewObjectPoints(int objectPoints, int reusePercentage);
float calculateEffort(int objectPoints);
float calculatePeople(float effort, int duration);

int main() {
    int screens, reports, components;
    int reusePercentage = 60;

    printf("Enter the number of Screens: ");
    scanf("%d", &screens);

    printf("Enter the number of Reports: ");
    scanf("%d", &reports);

    printf("Enter the number of 3GL Components: ");
    scanf("%d", &components);

    int objectPoints = calculateObjectPoints(screens, reports, components);
    float newObjectPoints = calculateNewObjectPoints(objectPoints, reusePercentage);

    printf("\nSelect Duration of Development:\n");
    printf("1. 1 year\n");
    printf("2. 2 years\n");
    printf("3. 3 years\n");
    printf("4. 4 years\n");
    printf("5. 5 years\n");

    int choice;
    printf("Enter your choice (1/2/3/4/5): ");
    scanf("%d", &choice);
    int duration = choice;  // Assume 1 choice corresponds to 1 year

    float effort = calculateEffort(newObjectPoints);
    float people = calculatePeople(effort, duration);

    printf("\nObject Points: %d\n", objectPoints);
    printf("New Object Points (with %d%% reuse): %.2f\n", reusePercentage, newObjectPoints);
    printf("Effort: %.2f Person-Months\n", effort);
    printf("Number of People for a %d year development: %.2f\n", duration, people);

    return 0;
}

int calculateObjectPoints(int screens, int reports, int components) {
    int totalObjectPoints = screens + reports + components;
    return totalObjectPoints;
}

float calculateNewObjectPoints(int objectPoints, int reusePercentage) {
    float newObjectPoints = objectPoints * (1 - (reusePercentage / 100.0));
    return newObjectPoints;
}

float calculateEffort(int objectPoints) {
    float a = 2.94;
    float b = 0.91;
    float effort = a * pow(objectPoints, b);
    return effort;
}

float calculatePeople(float effort, int duration) {
    float people = effort / (duration * 12.0);
    return people;
}