#include <stdio.h>
#include <string.h>

typedef int bool;
#define true 1
#define false 0

bool isAnagram(char* s, char* t);
int main(void)
{
	//char *s="anagram";
	//char *t="nagaram";
	char *s="rat";
	char *t="car";

	
	bool output;

	output=isAnagram(s,t);

	printf("output=%d\n", output);

	return 0;
}
bool isAnagram(char* s, char* t)
{
	int lens=strlen(s);
	char *tb1[123]={0};
	char *tb2[123]={0};

	if(lens!=strlen(t))
		return false;

	for(int i=0;i<lens;i++){
		tb1[s[i]]++;
		tb2[t[i]]++;
	}

	for(int i=0;i<123;i++){
		if(tb1[i]!=tb2[i])
			return false;
	}
	return true;
}
