#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 50  // Number of samples to generate

int main(void) {
  srand(time(NULL));  // Seed the random number generator

  // Generate N random samples
  double samples[N];
  for (int i = 0; i < N; i++) {
    samples[i] = (double)rand()/ RAND_MAX;
    printf("%lf,\t",samples[i]);
  }

  // Count the frequency of each unique sample
  int counts[N] = {0};  // Initialize all counts to 0
  for (int i = 0; i < N; i++) {
    counts[(int)samples[i]]++;
  }

  // Calculate the expected frequency
  float expected = (float)N / (float)RAND_MAX;

  // Check the randomness of the samples by comparing the frequency of each sample to the expected frequency
  int random = 1;  // Assume the samples are random
  for (int i = 0; i < RAND_MAX; i++) {
    float diff = (float)counts[i] - expected;
    if (diff < (-expected) || diff > expected) {
      random = 0;  // The samples are not random
      break;
    }
  }

  if (random==1) {
    printf("\n\n + The samples are random.\n");
  } else {
    printf("\n\n + The samples are not random.\n");
  }

  return 0;
}
