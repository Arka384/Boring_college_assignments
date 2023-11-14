#include <stdio.h>
#include <math.h>

#define SIZE 10

int main() {
    double t[SIZE], R1[SIZE], R2[SIZE], R3[SIZE];
    double lambda = 0.3;
    double k = 0.9;
    double m = 0.5;

    // Time to failure
    for(int i = 0; i < SIZE; i++) {
        t[i] = i + 1;
    }

    // Case I
    for(int i = 0; i < SIZE; i++) {
        R1[i] = exp(lambda * t[i]);
    }

    // Case II
    for(int i = 0; i < SIZE; i++) {
        R2[i] = exp(-0.5 * k * pow(t[i], 2));
    }

    // Case III
    for(int i = 0; i < SIZE; i++) {
        R3[i] = exp(-pow(t[i]/k, m));
    }

    // Print the results
    printf("Time to Failure (hours) | Case I: Constant Hazard | Case II: Linearly Increasing Hazard | Case III: Weibull Distribution\n");
    for(int i = 0; i < SIZE; i++) {
        printf("%-23.2f | %-23.2f | %-33.2f | %-30.2f\n", t[i], R1[i], R2[i], R3[i]);
    }

    return 0;
}
