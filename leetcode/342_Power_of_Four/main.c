#include <stdio.h>
#include <math.h>

typedef int bool;
#define true 1
#define false 0

bool isPowerOfFour(int num);
int main(void)
{
		int value=65;
		bool result=false;
		result=isPowerOfFour(value);
		printf("result=%d\n", result);

		return 0;
}
bool isPowerOfFour(int num)
{
		if (num<=0)
			return false;

		if (num==pow(4,floor(log(num)/log(4))))
				return true;
		else
				return false;

}
