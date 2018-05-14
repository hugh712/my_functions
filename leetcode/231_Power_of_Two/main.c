#include <stdio.h>

typedef int bool;
#define true 1
#define false 0

bool isPowerOfTwo(int n);
int main(void)
{
	int num=0;
	bool output=false;

	output=isPowerOfTwo(num);

	printf("output is %d\n", output);

}

bool isPowerOfTwo(int n)
{
	
	if (n<=0)
		return false;

	if (n==1)
		return true;

	while(n>=1){
		if (n%2!=0)
			return false;
		n=n/2;

		if(n<2)
			return true;
	}
	return true;

}

