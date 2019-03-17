#include <stdio.h>
#include <stdlib.h>

int romanToInt(char* s)
{
  int sum = 0;
  char prevChar;

  /* Iterate through all of the characters in the input number */
  while (*s != '\0') {
    switch (*s) {
      case 'I':
        sum = sum + 1;
        break;
      case 'V':
        if ('I' == prevChar)
          sum = sum + 3; /* We have already added 1 - add 3 more to get 4 (IV = 4) */
        else
          sum = sum + 5;
        break;
      case 'X':
        if ('I' == prevChar)
          sum = sum + 8; /* We have already added 1 - add 8 more to get 9 (IX = 9) */
        else
          sum = sum + 10;
        break;
      case 'L':
        if ('X' == prevChar)
          sum = sum + 30; /* We have already added 10 - add 30 more to get 40 (XL = 40) */
        else
          sum = sum + 50;
        break;
      case 'C':
        if ('X' == prevChar)
          sum = sum + 80; /* We have already added 10 - add 80 more to get 90 (XC = 90) */
        else
          sum = sum + 100;
        break;
      case 'D':
        if ('C' == prevChar)
          sum = sum + 300; /* We have already added 100 - add 300 more to get 400 (CD = 400) */
        else
          sum = sum + 500;
        break;
      case 'M':
        if ('C' == prevChar)
          sum = sum + 800; /* We have already added 100 - add 800 more to get 900 (CM = 900) */
        else
          sum = sum + 1000;
      default:
        break;
    }

    prevChar = *s;
    s++;
  }

  return sum;
}

int main(int argc, char const *argv[])
{
  char* romanNumber = "MCMXCIV";
  int integer;

  integer = romanToInt(romanNumber);

  printf("Number = %d\n", integer);

  return 0;
}
