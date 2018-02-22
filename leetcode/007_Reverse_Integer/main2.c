#include <stdio.h>
#include <limits.h>

int reverse(int x);
int main(void)
{
	int n=1534236469;
	int output=reverse(n);

	printf("output=%d\n", output);

	return 0;
}
int reverse(int x)
{
	int output=0;
	int digi=0;
	int sign=0;

	if (x<0){
		x*=-1;
		sign=1;
	}

	while(x>0){
		digi=x%10;
		x=x/10;

		if(output > INT_MAX/10){
        return 0;
    }

		output=output*10+digi;
	}

	if(sign==1)
		output*=-1;

	return output;
}
