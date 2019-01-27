#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool isLetterPresent(char c, bool letters_arr[])
{
  if (letters_arr == NULL || (int)c > 255)
    return false;

  return letters_arr[(int)c];
}

void updatePresentLetters(char c, bool letters_arr[])
{
  if (letters_arr == NULL || (int)c > 255)
    return;

  letters_arr[(int)c] = true;
}

int lengthOfLongestSubstring(char *s)
{
  bool letters_in_substring[256] = {false};  // all characters from Extended ASCII
  int ret_length  = 0;
  char* start_p   = s;
  int count       = 0;
  bool isLetterPresent_flag = false;

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
  if (count > ret_length)
  {
    ret_length = count;
  }

  return ret_length;
}

int main(int argc, char const *argv[])
{
  int length;
  char *input = " ";

  length = lengthOfLongestSubstring(input);

  printf("Input: %s\n", input);
  printf("The length of the longest substring without repeating charachters: %d\n", length);

  return 0;
}
