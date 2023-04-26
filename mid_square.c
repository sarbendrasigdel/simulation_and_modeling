#include <stdio.h>
#include <math.h>

#define N 5 // Number of random numbers to generate
#define W 2 // Width of the resulting random numbers (in digits)

int main(void) { 
  double num;
  printf("Enter Seed Value:");
  scanf("%lf",&num);
  // Initialize the random number generator with the seed value

  for (int i = 0; i < N; i++) {
    // Calculate the square of the current number
    long long square = (long long) num * num;

    // Extract W digits from the middle of the result
    int digits = (int) (square / pow(10, (int) (log10(square) - W + 1)));
    num = (double)(digits % (int) pow(10, W));
    printf("%.2lf\n", num/100); // Print the random number with the specified width
  }
  return 0;
}
