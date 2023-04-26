#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 50 // Number of data points in the sample
#define G 10 // Number of gaps
int main(void) {
  // Generate a sample of random numbers between 0 and 1 (inclusive)
  double data[N];
  for (int i = 0; i < N; i++) {
    data[i] = (double) rand() / RAND_MAX;
    printf("%lf ,\t",data[i]);
  }
  // Calculate the expected number of occurrences in each gap
  double expected = (double) N / G;
  // Count the number of occurrences in each gap
  int count[G];
  for (int i = 0; i < G; i++) {
    count[i] = 0;
  }
  for (int i = 0; i < N; i++) {
    int gap = (int) (data[i] * G);
    count[gap]++;
  }
  // Calculate the chi-square statistic
  double chi_square = 0.0;
  for (int i = 0; i < G; i++) {
    chi_square += pow(count[i] - expected, 2) / expected;
  }
  // Determine whether the sample comes from a uniform distribution
  if (chi_square < 16.919) {
    puts("\nThe sample comes from a uniform distribution (accept H0)");
  } else {
    puts("\nThe sample does NOT come from a uniform distribution (reject H0)");
  }
  return 0;
}
