#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct Cost_Driver
{
    int stage; // very low -> 0 // low -> 1 // Normal -> 2 // High -> 3 // Very High->4
    float value;
} CD;
void Simple(float screen, float reports, float components, float reusability, float productivity);
void Medium(float screen, float reports, float components, float reusability, float productivity);
void Complex(float screen, float reports, float components, float reusability, float productivity);
void EarlyDesignModel(int KLOC, float prodCostDrivers)
{
    printf("Early Stage Design Model\n");
    float effort = KLOC * prodCostDrivers;
    int time = 5; // year
    float people = ceil((effort / (time * 12)));
    printf("Effort : %f\n", effort);
    printf("People Needed : %f\n", people);
}
void PostArchitectureModel(int KLOC, float prodCostDrivers)
{
    printf("Post Architecture Stage Model\n");
    float a, b;
    printf("1. Organic\n2. Semi-Detached\n3. Embedded\n");
    int ch;
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        a = 2.4;
        break;
    case 2:
        a = 3.0;
        break;
    case 3:
        a = 3.6;
        break;
    default:
        a = 3.6; /// default embedded
    }
    b = 1.10; // let
    float effort = a * pow(KLOC, b) * prodCostDrivers;
    int time = 5; // year
    float people = ceil((effort / (time * 12)));
    printf("Effort : %f\n", effort);
    printf("People Needed : %f\n", people);
}
int main()
{
    float size;
    float screen, reports, components, reusability, productivity;
    int NoCostDrivers;
    float prodCostDrivers = 1.0;

    printf("Enter the size of the project in KLOC: ");
    scanf("%f", &size);
    printf("Enter number of Cost Drivers : ");
    scanf("%d", &NoCostDrivers);
    CD cDrivers[NoCostDrivers];
    printf("Enter Cost Drivers\n");
    printf("As Stage value (space separated):\n");
    for (int i = 0; i < NoCostDrivers; i++)
    {
        scanf("%d %f", &cDrivers[i].stage, &cDrivers[i].value);
        prodCostDrivers *= cDrivers[i].value;
    }
    printf("\nThe type of project is simple.\n");
    printf("Enter the number of screens, reports, components, reusability, productivity:\n");
    scanf("%f %f %f %f %f", &screen, &reports, &components, &reusability, &productivity);
    printf("\n");

    if (size <= 30) // Simple Project : <= 30KLOC
        Simple(screen, reports, components, reusability, productivity);
    else if (size <= 60) // Medium Project : <= 60KLOC
        Medium(screen, reports, components, reusability, productivity);
    else    // Complex Project : > 60KLOC
        Complex(screen, reports, components, reusability, productivity);
    printf("\n");
    EarlyDesignModel(size, prodCostDrivers);
    printf("\n");
    PostArchitectureModel(size, prodCostDrivers);
    return 0;
}
void Simple(float screen, float reports, float components, float reusability, float productivity)
{
    float time;
    float op, nop, effort, cost;
    int choice;
    printf("\nThe type of project is simple.\n");
    printf("Enter the number of screens, reports, components, reusability, productivity:\n");
    scanf("%f %f %f %f %f", &screen, &reports, &components, &reusability,
          &productivity);
    op = (screen * 1 + reports * 2 + components * 1);
    nop = op * (100 - reusability) / 100;
    effort = nop / productivity;
    cost = 1500 * (float)(nop / productivity);
    printf("Object Points: %.2f\n", op);
    printf("New Object Points: %.2f\n", nop);
    printf("Effort (in person-months): %.2f\n", effort);
    printf("Total Cost required: %.0f\n", cost);
}
void Medium(float screen, float reports, float components, float reusability, float productivity)
{
    float op, nop, effort, cost;
    
    op = (screen * 2 + reports * 5 + components * 1);
    nop = op * (100 - reusability) / 100;
    effort = nop / productivity;
    cost = 1500 * (float)(nop / productivity);

    printf("Object Points: %.2f\n", op);
    printf("New Object Points: %.2f\n", nop);
    printf("Effort (in person-months): %.2f\n", effort);
    printf("Total Cost required: %.0f\n", cost);
}
void Complex(float screen, float reports, float components, float reusability, float productivity)
{
    float op, nop, effort, cost;
    
    op = (screen * 3 + reports * 8 + components * 10);
    nop = op * (100 - reusability) / 100;
    effort = nop * productivity;
    cost = 1500 * (float)(nop / productivity);

    printf("Object Points: %.2f\n", op);
    printf("New Object Points: %.2f\n", nop);
    printf("Effort (in person-months): %.2f\n", effort);
    printf("Total Cost required: %.0f\n", cost);
}