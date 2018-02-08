#include <stdio.h>
#include <string.h>

int strStr(char* haystack, char* needle);
int main(void)
{
	char * haystack="ppsshello";
	char * needle="ll";
	int output=0;

	output=strStr(haystack, needle);
	printf("output=%d", output);
	return 0;
}
int strStr(char* haystack, char* needle)
{
	int lenHaystack=0;	
	int lenNeedle=0;	
	int point_e=0;
	int match=0;

	lenHaystack=strlen(haystack);
	lenNeedle=strlen(needle);

	if((lenNeedle==0 && lenHaystack==0) || lenNeedle==0)
		return 0;
	else if(lenHaystack==0 && lenNeedle!=0)
		return -1;

	for (int i=0;i<lenHaystack;i++)
	{
		if(haystack[i]==needle[0])
		{
			match=0;
			for(int j=0;j<lenNeedle;j++)
			{
				if(haystack[i+j]==needle[j])
				{
					match++;
					if(match==lenNeedle)
					{
						return i;
					}
				}
			}//end of inner for
		}//end of if	
	}//end of for

	return -1;
}
