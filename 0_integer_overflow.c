#include <stdio.h>
#include <stdlib.h>

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 

int main(int argc, char const *argv[])
{
  char i = 100, j = 240, sum;
  unsigned char iu = 100, ju = 240, sumu;
  signed char is = 100, js = 240, sums;

  sum = i+j; sumu = iu + ju; sums = is+js;
  printf("j = "BYTE_TO_BINARY_PATTERN"\n", BYTE_TO_BINARY(j));
  printf("char:           %d + %d = %3d or ASCII %c\n", i, j, sum, sum);
  printf("unsigned char:  %d + %d = %3d or ASCII %c\n", iu, ju, sumu, sumu);
  printf("signed char:    %d + %d = %3d or ASCII %c\n", is, js, sums, sums);
  return 0;
}