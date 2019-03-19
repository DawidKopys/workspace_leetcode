#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize) {
  int *numsEnd = nums + numsSize; // address of one PAST the last element of the input array
  int **ret = (int**)calloc(64, sizeof(int*));

  int ind = 0;
  int *arr = NULL;

  for (int *i = nums; i < numsEnd; i++) {
    for (int *j = i + 1; j < numsEnd; j++) {
      for (int *u = j + 1; u < numsEnd; u++) {
        if ((*i + *j + *u) == 0) {
          /* allocate array of 3 elements */
          arr = (int*)malloc(3*sizeof(int));
          arr[0] = *i;
          arr[1] = *j;
          arr[2] = *u;
          ret[ind++] = arr;
        }
      }
    }
  }

  *returnSize = ind;
  return ret;
}

int main(int argc, char const *argv[])
{
  // int input[] = {1, 2, 3, -1, 0};
    int input[] = {-1,0,1,2,-1,-4};
  int inputSize = sizeof(input)/sizeof(input[0]);
  int **out, outSize;

  out = threeSum(input, inputSize, &outSize);
  
  printf("outSize=%d\n", outSize);

  for (int i = 0; i < 64; i++) {
    if (out[i] != NULL) {
      printf("%3d: [%d, %d, %d]\n", i, out[i][0], out[i][1], out[i][2] );
      free(out[i]);
    }
    else {
      printf("%3d: NULL\n", i);
    }
  }

  free(out);

  return 0;
}
