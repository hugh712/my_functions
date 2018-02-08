#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* countAndSay(int n);
int main(void)
{
	int input=9;
	char* output;


	output=countAndSay(input);

	printf("output=%s\n", output);

	free(output);
	return 0;	
}
char* countAndSay(int n)
{
	if (n==1)
		return "1";
	char * str=malloc(3);
	int i,j=0;

	str[0]='1';
	str[1]='1';
	
	if (n==2)
		return str; 

	for (i=2;i<n;i++)
	{
		int targetCurr=0;
	  char * temp=malloc(strlen(str)*3);
		char tempC='a';
		memset(temp,"/0",strlen(temp));	

		for(int stri=0;stri<strlen(str);)
		{
			int calculateC=stri;
			char curr=str[stri];
			int count=0;
			for(j=stri;j<strlen(str);j++)
			{
				if (curr==str[j])
				{
					stri++;
					count++;
				}
				else
					break;	
			}//end of forX3	

			sprintf(&tempC, "%d", count);		
			temp[targetCurr++]=tempC;
			temp[targetCurr++]=str[calculateC];
		}//end of forX2
		free(str);
		str=temp;
	}//end of forX1
	return str;

}
