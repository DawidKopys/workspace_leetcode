#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* check if b is in a, return index of this, -1 if not there */
int myIndexOf(const char *a, const char *b) {
  char *result = strstr(a, b);
  if (result == NULL) return -1;
  int position = result - a;
  // int substringLength = strlen(*a) - position;
  return position;
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
    while (myIndexOf(strs[i], prefix) != 0) {
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
  // char *inputStrings[2] = {"aa", "a"};
  char *retVal = NULL;
  
  int input_size = sizeof(inputStrings)/sizeof(inputStrings[0]);

  retVal = longestCommonPrefix(inputStrings, input_size);

  printf("Common prefix = \"%s\"\n", retVal);

  free(retVal);

  // char *c = "Dawid";
  // char *c2 = createSubstring(c, 3);

  // printf("*c=%s\n", c);
  // printf("*c2=%s\n", c2);

  // printf("mystrcmp(c,c2)=%d\n", mystrcmp(c, c2));
  // printf("mystrcmp(\"Dawid\",\"Dab\")=%d\n", mystrcmp("Dawid", "Dab"));
  // printf("mystrcmp(\"Dawid\",\"Daw\")=%d\n", mystrcmp("Dawid", "Daw"));

  // free(c2);

  return 0;
}
