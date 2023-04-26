#include <stdio.h>
#include <stdlib.h>
#define N 10
int check (int arr[], int num){
    for (int i = 0; i < N; i++)
    {
       if(arr[i]==num){
        return 0;
       }else{
        return 1;
       }
    }
    
}
void generateRN(int a, int x0, int c, int m){
    int x1;
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        x1 = (a*x0+c)%m;
        x0 = x1;
        if(check(arr,x1)==1){
            arr[i] = x1;
            printf("%d \t",x1);
        }else{
            printf("finish after repeating sequence");
            break;
        }
    }
    printf("\n ------ \n");
}

int main(void) {
  // Constants for the LCG algorithm
  int a, c, m;   
  // Initialize the random number generator with a seed value
  int seed = 27;
  while (1) {
    // Display the menu options
    puts("Menu:\n1. Additive LCG\n2. Multiplicative LCG\n3. Mixed LCG\n4.Quit");
    printf("Enter your choice: ");
    a = 23;
    c = 42;
    m = 100;
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
      // Use parameters for an additive LCG
      a = 1;
      generateRN(a,seed,c,m);
    } else if (choice == 2) {
      // Use parameters for a multiplicative LCG
      c = 0;
      generateRN(a,seed,c,m);
    } else if (choice == 3) {
      // Use parameters for a mixed LCG
      generateRN(a,seed,c,m);
    } else if (choice == 4) {
      // Quit the program
      break;
    } else {
      puts("Invalid choice! Please try again.");
    }
  }
  return 0;
}
