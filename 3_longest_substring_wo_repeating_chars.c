#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool isLetterPresent(char c, bool letters_arr[])
{
  int letterIntex = tolower(c) - 97;

  if (letters_arr == NULL)
    return false;

  return letters_arr[letterIntex];
}

void updatePresentLetters(char c, bool letters_arr[])
{
  int letterIntex = tolower(c) - 97;

  if (letters_arr == NULL)
    return;

  letters_arr[letterIntex] = true;
}

int lengthOfLongestSubstring(char *s)
{
  bool letters_in_substring[26] = {false};  // there are 26 letters in the english alphabhet
  int ret_length  = 0;
  char* start_p   = s;
  int count       = 0;
  bool isLetterPresent_flag = false;

  int input_length = strlen(s);
  // printf("Input length: %d\n", input_length);

  while ((*s != '\0') && (*start_p != '\0'))
  {
    isLetterPresent_flag = isLetterPresent(*s, letters_in_substring);
    
    if (true == isLetterPresent_flag)
    {
      memset(letters_in_substring, false, sizeof(bool)*sizeof(letters_in_substring));
      if (count > ret_length) 
      {
        ret_length = count;
      }
      count = 0;
      start_p++;
      s = start_p;
    }
    else if (false == isLetterPresent_flag)
    {
      updatePresentLetters(*s, letters_in_substring);
      count++;
      s++;
    }
  }

  return ret_length;
}

int main(int argc, char const *argv[])
{
  int length;
  char *input = "abcadcbb";

  length = lengthOfLongestSubstring(input);

  printf("Input: %s\n", input);
  printf("The length of the longest substring without repeating charachters: %d\n", length);

  return 0;
}
