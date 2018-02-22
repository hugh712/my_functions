#include <stdio.h>

int mySqrt(int x);
int main(void)
{
	int n=81;
	int output;
	output=mySqrt(n);

	printf("output=%d\n", output);

	return 0;
}
int mySqrt(int x)
{
	long r = x;

	while(r*r > x)
		r=(r+x/r)/2;
	return r;

}
