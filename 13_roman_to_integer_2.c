#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getVal(char c) {
  switch(c) {
    case 'I':
      return 1;
    case 'V':
      return 5;
    case 'X':
      return 10;
    case 'L':
      return 50;
    case 'C':
      return 100;
    case 'D':
      return 500;
    case 'M':
      return 1000;
  }
  return 0;
}

int romanToInt(char* s) {
  int len = strlen(s);
  int sum = 0;
  int first, second;

  for (int i = 0; i < len; i++) {
    first = getVal(s[i]);
    if (i+1<len) {
      second = getVal(s[i+1]);
    }
    else {
      second = 0;
    }    

    if ( first < second ) {
      sum += second - first;
      i++;
    }
    else {
      sum += first;
    }
  }

  return sum;
}


int main(int argc, char const *argv[]) {
  char* romanNumber = "MCMXCIV";
  int integer;

  integer = romanToInt(romanNumber);

  printf("Number = %d\n", integer);

  return 0;
}
