#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 

int pow_my(int base, int power)
{
  int ret = 1;

  while (power)
  {
    ret = ret*base;
    power--;
  }

  return ret;
}

int reverse(int x)
{
  long int r, reverse = 0; // input 543

  while (x != 0 && x < INT_MAX)
  {
    r = x % 10; // 3, 4, 5
    reverse = reverse * 10 + r; // 3, 34, 345
    x /= 10; // 54, 5, 0
  }

  if (reverse > INT_MAX || reverse < -INT_MAX)
    reverse = 0;

  return (int)reverse;
}

int reverse2(int x) {
  long int val = 0;
	do 
	{
		val = val * 10 + x % 10;
		x /= 10;
	} while (x);
	
	return (val > INT_MAX || val < INT_MIN) ? (int)0 : (int)val;
}

int main(int argc, char const *argv[])
{
  printf("%d\n", reverse((int)2147483647));

  int a = reverse2((int)2147483647);
  printf("%d\n", a);

  printf("%d\n", (int)pow_my(2,3));
  return 0;
}
