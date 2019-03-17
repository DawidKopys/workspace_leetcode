#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mystrcmp(const char *a, const char *b) {
  
}

char *createSubstring(const char* s, int len) {
  if (len==0) return calloc(1,1);

  char *ret = malloc((len+1)*sizeof(char));
  memcpy(ret, s, len);
  ret[len] = '\0';
  
  return ret;
}

char* longestCommonPrefix(char** strs, int strsSize) {
  if (strsSize == 0) return calloc(1,1);

  // char *prefix = strs[0];
  char *prefix = malloc((strlen(strs[0])+1)*sizeof(char));
  // memcpy(prefix, strs[0], strlen(strs[0])+1);
  strcpy(prefix, strs[0]);
  /* Iterate through input strings */
  for (int i = 1; i < strsSize; i++) 
  {
    while (strcmp(prefix, strs[i]) != 0) {
      prefix[strlen(prefix)-1] = '\0';
      if (strlen(prefix)==0) {
        free(prefix);
        return calloc(1,1);
      }
    }
  }
  return prefix;
}

int main(int argc, char const *argv[])
{
  char *inputStrings[3] = {"flow","flower","flight"};
  // char *inputStrings[1] = {""};
  char *retVal = NULL;
  

  retVal = longestCommonPrefix(inputStrings, 3);

  printf("Common prefix = \"%s\"\n", retVal);

  free(retVal);

  // char *c = "Dawid";
  // char *c2 = createSubstring(c, 3);

  // printf("%s\n", c2);

  // free(c2);

  return 0;
}
