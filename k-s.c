#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 20 // Number of data points in the sample

int main(void) {
  // Generate a sample of random numbers between 0 and 1 (inclusive)
  double data[N];
  printf("Sample: \n");
  for (int i = 0; i < N; i++) {
    data[i] = (double) rand() / RAND_MAX;
    printf("%lf,\t",data[i]);
  }

  // Calculate the maximum difference between the cumulative distribution function (CDF) of the data and the CDF of the uniform distribution
  double max_diff = 0.0;
  for (int i = 0; i < N; i++) {
    double diff = fabs((double) (i + 1) / N - data[i]);
    if (diff > max_diff) {
      max_diff = diff;
    }
  }
  // Calculate the critical value of the KS test at the 0.05 significance level
  double critical_value = 1.36 / sqrt((double) N);
  // Determine whether the sample comes from a uniform distribution
  if (max_diff > critical_value) {
    puts(" \n The sample does NOT come from a uniform distribution (reject H0)");
  } else {
    puts("\n The sample comes from a uniform distribution (accept H0)");
  }

  return 0;
}
