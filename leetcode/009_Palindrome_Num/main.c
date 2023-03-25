#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

bool isPalindrome(int x);
bool isPalindrome_2(int x);
int getCounts(int x);
int getDigit(int num, int which);
int main(int argc, const char *argv[])
{
  //int input=-2147447412;
	//int input=121;
	int input=0;
	bool ret=0;
	ret=isPalindrome_2(input);
	printf("ret=%d\n", ret);
	
}

int getCounts(int x){

	int count=0;
	if (x==0)
		return 0;
	else {
		while(x>0){
			count++;
			x=x/10;	
		}	
	}
	return count;

}
int getDigit(int num, int which){
	int ret=0;

	num=num % (int)(pow(10,which+1));
	num=num / pow(10,which);

	return num;	

}
bool isPalindrome(int x) {
	int digits=0;
	int firstP=0, lastP=0;;
	if (x == INT_MIN){
		return 0;
	}
	else if (x<0){
		return 0;
	}
	printf("num=%d\n\n\n", x);
	digits=getCounts(x);
	printf("digits=%d\n\n\n", digits);
	if(digits==0 || digits==1)
		return 1;
	lastP=digits;	

	while (firstP!=lastP){
		if (getDigit(x,firstP)!=getDigit(x,lastP-1))
			return 0;	
	//	printf("%d X %d\n", getDigit(x,firstP), getDigit(x,lastP-1));
	//	printf("firstP=%d\n", firstP);
	//	printf("lastP=%d\n", lastP);

		if((firstP+1)==lastP)
			break;

		firstP++;
		lastP--;
	}

	    
	return 1;
}

bool isPalindrome_2(int x) {
	if (x < 0 || (x!=0 && x%10 == 0))
		return false;
	
	int first_half=0;


	while (first_half < x)
	{
		first_half = (first_half * 10) + (x % 10);	
		x/=10;
	}
	
	return (first_half == x) || (first_half/10 == x);
}
