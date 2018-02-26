#include <stdio.h>

typedef int bool;
#define true 1
#define false 0

bool isPowerOfThree(int n);
int main(void)
{
		int num=45;
		bool result=false;

		result=isPowerOfThree(num);		
				
		printf("result=%d\n", result);

		return 0;
}
bool isPowerOfThree(int n)
{

		if(n==1)
			return true;

		while(n%3==0 && n!=0){
				n/=3;

				if(n==1)
					return true;
		}
		
		return false;
}
