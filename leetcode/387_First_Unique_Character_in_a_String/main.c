#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int firstUniqChar(char* s);
int main(void)
{
	char *str="loveloveel";
	int output=firstUniqChar(str);

	printf("output=%d\n", output);
	return 0;
}
int firstUniqChar(char* s)
{
	int len=strlen(s);
	int count=0;
	for(int i=0;i<len;i++){
		count=0;
		for(int j=0;j<len;j++){
			if(s[i]==s[j] && i!=j){
				count=1;
				break;
			}
		}
		if(count==0){
			return i;
		}
	}
	return -1;
}
