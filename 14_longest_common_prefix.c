#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
  char *commonPrefix = NULL;
  int commonLength = 0;
  int theSameFlag = 1;
  char letter;
  int j = 0;

  if (strsSize == 0) {
    commonPrefix = malloc(sizeof(char));
    commonPrefix[0] = '\0';
    return commonPrefix;
  }

  /* Iterate through input strigns */
  do {
    if (strs[0][j] != '\0') {
      letter = strs[0][j];
      for(int i = 1; i < strsSize; i++) {
        if ((strs[i][j] == '\0') || (letter != strs[i][j]) ) {
          theSameFlag = 0;
          break;
        }
      }
    }
    else {
      theSameFlag = 0;
    }

    commonLength++;
    j++;
  } while (theSameFlag == 1);
  
  printf("Length of the common prefix: %d\n", commonLength-1);

  commonPrefix = malloc(commonLength*sizeof(char));
  strncpy(commonPrefix, strs[0], commonLength-1);
  commonPrefix[commonLength-1] = '\0';

  return commonPrefix;
}

int main(int argc, char const *argv[])
{
  char *inputStrings[3] = {"flow","flower","flight"};
  // char *inputStrings[1] = {""};
  char *retVal = NULL;
  
  retVal = longestCommonPrefix(inputStrings, 3);

  printf("Common prefix = \"%s\"\n", retVal);

  return 0;
}
