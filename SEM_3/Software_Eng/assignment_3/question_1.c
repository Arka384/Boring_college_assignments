#include <stdio.h>
#include <math.h>
#define SIZE 6

int main() {
    double time_intervals[SIZE] = {1000, 2000, 3000, 4000, 5000, 6000};
    int failures_in_interval[SIZE] = {59, 24, 29, 30, 17, 13};
    int val = 172;
    int survivors[SIZE];
    int cumulative_failures[SIZE] = {0};
    double reliability[SIZE] = {0.0};
    double cumulative_fail_distri[SIZE] = {0.0};
    double failure_density_func[SIZE] = {0.0};
    double hazard_rate[SIZE] = {0.0};

    // Calculate survivors
    for(int i = 0; i < SIZE; i++) {
        survivors[i] = val - cumulative_failures[i];
    }

    // Calculate cumulative failures and reliability
    for(int i = 0; i < SIZE; i++) {
        cumulative_failures[i] = i > 0 ? cumulative_failures[i-1] + failures_in_interval[i] : failures_in_interval[i];
        reliability[i] = (double)survivors[i] / val;
        cumulative_fail_distri[i] = (double)cumulative_failures[i] / val;
    }

    // Calculate density function and hazard rate
    for(int i = 0; i < SIZE - 1; i++) {
        failure_density_func[i] = (double)(cumulative_failures[i + 1] - cumulative_failures[i]) / (time_intervals[i] * val);
        hazard_rate[i] = (double)(cumulative_failures[i + 1] - cumulative_failures[i]) / (time_intervals[i] * survivors[i]);
    }

    // Print the results
    printf("\n t \t\t R(t) \t F(t) \tf(t) \tz(t)\n");
    printf("----------------------------------------------------------\n");
    for(int i = 0; i < SIZE - 1; i++) {
        printf("%f\t%.3f\t%.3f\t%.5f\t%.5f\n", time_intervals[i], reliability[i], cumulative_fail_distri[i], failure_density_func[i], hazard_rate[i]);
    }
    return 0;
}
