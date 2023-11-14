#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int time[] = {8, 20, 34, 46, 63, 86, 111, 141, 186, 266};
    int num_of_failures[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int val = 172;
    int survivors[10];
    int cumulative_failures[10] = {0};
    double reliability[10] = {0.0};
    double cumulative_fail_distri[10] = {0.0};
    double failure_density_func[10] = {0.0};
    double hazard_rate[10] = {0.0};

    // Calculate cumulative failures and reliability
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j <= i; j++) {
            cumulative_failures[i] += num_of_failures[j];
        }
        survivors[i] = val - cumulative_failures[i];
        reliability[i] = (double)survivors[i] / 172;
        cumulative_fail_distri[i] = (double)cumulative_failures[i] / 172;
    }

    // Calculate density function and hazard rate
    for (int i = 0; i < 9; i++) {
        failure_density_func[i] = (cumulative_failures[i + 1] - cumulative_failures[i]) / (999.0 * 172);
        hazard_rate[i] = (cumulative_failures[i + 1] - cumulative_failures[i]) / (999.0 * survivors[i]);
    }

    // Print the results
    printf("\n t \tR(t) \tF(t) \tf(t) \tz(t)\n");
    printf("----------------------------------------------------------\n");
    for (int i = 0; i < 9; i++) {
        printf("%d\t%.3f\t%.3f\t%.5f\t%.5f\n", time[i], reliability[i], cumulative_fail_distri[i], failure_density_func[i], hazard_rate[i]);
    }
    return 0;
}
