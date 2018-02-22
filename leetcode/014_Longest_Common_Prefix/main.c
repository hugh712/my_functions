#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
 *Write a function to find the longest common prefix string amongst an array of strings.

 Longest common prefix for a pair of strings S1 and S2 is the longest string S which is the prefix of both S1 and S2.

 As an example, longest common prefix of "abcdefgh" and "abcefgh" is "abc".

 Given the array of strings, you need to find the longest S which is the prefix of ALL the strings in the array.
 
 [

   "abcdefgh",

	 "aefghijk",

	 "abcefghd"
] is a
 
 *
 */
#define ArraySize 0

char* longestCommonPrefix(char** strs, int strsSize);
int main(void)
{
	//char *ss[ArraySize]={"abcdefgh","abfghijk","abcefghd"};
	char *ss[1]={"abcdefg"};
	int size=0;
	char *output;


	output=longestCommonPrefix(&ss,size);

	printf("output='%s'\n\n", output);
	free(output);
	return 0;
}

char* longestCommonPrefix(char** strs, int strsSize)
{
	int point=0;
	int length=strlen(strs[0]);
	char curr;
	char * output;

	if (strsSize==0)
	{
		output=malloc(sizeof(char)*2);
		strcpy(output,"");
		return output;
	}
	if (strsSize==1)
	{
		output=malloc(sizeof(char)*length);
		strcpy(output,strs[0]);
		return output;
	}


	for (int i=0;i<length;i++){
		for (int j=0;j<strsSize;j++){
			if(j==0){
				curr=strs[j][i];
			}
			else{
				if(curr!=strs[j][i]){
					point=i-1;
					i=length;j=strsSize;break;
				}
			}
		}			
	}//end of for
	
	printf("point=%d\n\n", point);
	output=malloc(sizeof(char)*(point+1));
	strncpy(output,strs[0], point+1);	

	return output;
}
