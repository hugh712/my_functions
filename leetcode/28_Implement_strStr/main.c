#include <stdio.h>
#include <string.h>

int strStr(char* haystack, char* needle);
int main(void)
{
	char * haystack="hello";
	char * needle="ll";
	int output=0;

	output=strStr(haystack, needle);
	printf("output=%d", output);
	return 0;
}
int strStr(char* haystack, char* needle)
{
	int len=0;	

	printf("strlen=%ld\n", strlen(haystack));
	printf("strlen=%ld\n", strlen(needle));

	return len;
}
