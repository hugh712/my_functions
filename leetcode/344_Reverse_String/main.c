#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverseString(char* s);
int main(void)
{
	char * str=malloc(7);
	strcpy(str,"abcdefg");
	char * output;
	output=reverseString(str);

	printf("output=%s", output);
	return 0;
}
char* reverseString(char* s)
{
	int l=0;
	int r=strlen(s)-1;
	char temp;
	while(l<r){
		temp=s[r];
		s[r]=	s[l];
		s[l]=temp;

		l++;
		r--;
	}
	
	return s;
}
