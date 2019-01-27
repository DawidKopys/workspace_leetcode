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
  long long int val = 0;
  
	do 
	{
		val = val * 10 + x % 10;
		x /= 10;
	} while (x);

  if (val > INT_MAX || val < INT_MIN)
    val = 0;

	return val;
}

int reverse3(int x)
{
  int pop, ret = 0;

  while (x != 0)
  {
    pop = x % 10;
    x /= 10;
    if (ret > INT_MAX/10 || (ret == INT_MAX/10 && pop > 7)) return 0;
    if (ret < INT_MIN/10 || (ret == INT_MIN/10 && pop < -8)) return 0;
    ret = ret * 10 + pop;
  }
  
  return ret;
}

int main(int argc, char const *argv[])
{
  printf("%d\n", reverse((int)2147483647));

  int a = reverse2((int)2147483647);
  printf("%d\n", a);

  printf("%d\n", reverse3((int)213123));

  return 0;
}
