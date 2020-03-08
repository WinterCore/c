#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "percolation.h"



int main(int argc, char **argv) {
    int n, t, v = 0;
    if (argc < 3) {
        printf("Usage: main [size of the grid] [number of experiments to perform]");
        exit(EXIT_FAILURE);
    }
    v += sscanf(*(argv + 1), "%d", &n);
    v += sscanf(*(argv + 2), "%d", &t);
    if (v != 2) {
        printf("Invalid parameters supplied, Exiting...");
        exit(EXIT_FAILURE);
    }
    double results[t];

    for (int i = 0; i < t; i += 1)
        results[i] = run(n, false);

    double sum = 0, mean, variance, stddev;
    for (int i = 0; i < t; i += 1)
        sum += results[i];

    mean = sum / t;
    sum = 0;

    for (int i = 0; i < t; i += 1)
        sum += (results[i] - mean) * (results[i] - mean);

    variance = sum / (t - 1);
    stddev = sqrt(variance);


    printf("%-30s = %f\n", "Mean", mean);
    printf("%-30s = %f\n", "Standard Deviation", stddev);

    return 0;
}
