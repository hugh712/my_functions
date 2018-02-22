#include <stdio.h>


int Combination(int n, int r);
int climbStairs(int n);
int main(void)
{
	int n=24;
	int output;
	output=climbStairs(n);
	printf("output=%d\n", output);

	return 0;
}
int climbStairs(int n) {
    int a = 1, b = 1;
    while (n--)
    {
        b+=a;
        a = b - a;
    }
    return a;
}


