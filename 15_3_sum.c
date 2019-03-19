#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b) {
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize) {
  int *numsEnd = nums + numsSize; // address of one PAST the last element of the input array
  int **ret = (int**)calloc(120, sizeof(int*));

  int ind = 0;
  int *arr = NULL;
  int isDuplicate = 0;

  for (int *i = nums; i < numsEnd; i++) {
    for (int *j = i + 1; j < numsEnd; j++) {
      for (int *u = j + 1; u < numsEnd; u++) {
        if ((*i + *j + *u) == 0) {
          /* order the numbers before allocating the array - from the smallest to the biggest */
          if (*i > *u) swap(i, u);
          if (*i > *j) swap(i, j);
          if (*j > *u) swap(j, u);

          /* check if the triplet is not a duplicate */
          for (int a = 0; a < ind; a++) {
            if (*i==ret[a][0] && *j==ret[a][1] && *u==ret[a][2]) {
              isDuplicate = 1;
            }
          }

          if (isDuplicate == 0) {
            /* allocate array of 3 elements */
            arr = (int*)malloc(3*sizeof(int));
            arr[0] = *i;
            arr[1] = *j;
            arr[2] = *u;
            ret[ind++] = arr;
          }
          else {
            isDuplicate = 0;
          }
        }
      }
    }
  }

  int **tmp = realloc(ret, ind*sizeof(int*));
  if (tmp != NULL) {
    ret = tmp;
  }
  else {
    printf("Error kurwa\n");
  }

  *returnSize = ind;
  return ret;
}

int main(int argc, char const *argv[])
{
  // int input[] = {1, 2, 3, -1, 0};
  int input[] = {-1,0,1,2,-1,-4,-14,14,-23,22};
  // [-1,0,1,2,-1,-4]
  // int input[] = {-13,5,13,12,-2,-11,-1,12,-3,0,-3,-7,-7,-5,-3,-15,-2,14,14,13,6,-11,-11,5,-15,-14,5,-5,-2,0,3,-8,-10,-7,11,-5,-10,-5,-7,-6,2,5,3,2,7,7,3,-10,-2,2,-12,-11,-1,14,10,-9,-15,-8,-7,-9,7,3,-2,5,11,-13,-15,8,-3,-7,-12,7,5,-2,-6,-3,-10,4,2,-5,14,-3,-1,-10,-3,-14,-4,-3,-7,-4,3,8,14,9,-2,10,11,-10,-4,-15,-9,-1,-1,3,4,1,8,1};
  int inputSize = sizeof(input)/sizeof(input[0]);
  int **out, outSize;

  out = threeSum(input, inputSize, &outSize);
  
  printf("outSize=%d\n", outSize);

  for (int i = 0; i < outSize; i++) {
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
