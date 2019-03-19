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
  int *end = height + heightSize - 1; // the address of the last element in the input
  int *start = height;

  while (start != end) {
    if (*start < *end) {
      maxarea = max(maxarea, (end - start)*(*start));
      start++;
    }
    else {
      maxarea = max(maxarea, (end - start)*(*end));
      end--;
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
