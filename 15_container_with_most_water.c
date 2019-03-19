#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b) {
  return ((a < b) ? (a) : (b));
}

int max(int a, int b) {
  return ((a > b) ? (a) : (b));
}

int maxArea(int* height, int heightSize) {
  // int area;
  int maxarea = 0;
  int *heightEnd = height + heightSize; // the address of the one PAST last element in the input
  for (int *i = height; i < heightEnd; i++) {
    for (int *j = i + 1; j < heightEnd; j++) {
      maxarea = max(maxarea, (j - i)*min(*i, *j));
    }
  }
  return maxarea;
}

int main(int argc, char const *argv[])
{
  // int input[] = {1, 2, 3};
  int input[] = {1,8,6,2,5,4,8,3,7};
  int inputSize = sizeof(input)/sizeof(input[0]);
  int out;

  out = maxArea(input, inputSize);
  
  printf("Maximum area: %d\n", out);

  return 0;
}
