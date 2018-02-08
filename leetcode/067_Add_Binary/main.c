#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* addBinary(char* a, char* b);
int main(void)
{
	char *a="10000011";
	char *b="111000";
	char *c=NULL;

	c=addBinary(a,b);

	printf("c=%s\n",c);
	
	free(c);
	return 0;
}

char* addBinary(char* a, char* b)
{
	int ac=0;
	int aLen=strlen(a);
	int bLen=strlen(b);
	char * longStr=NULL;
	char * shortStr=NULL;
	char * returnStr=NULL;
	char * tempStr=NULL; 
	char * tempStr2=NULL; 
	int longLen=0;
	int shortLen=0;

	if(aLen>=bLen)
	{
		longStr=a;
		shortStr=b;
		longLen=aLen;
		shortLen=bLen;
	}
	else
	{
		longStr=b;
		shortStr=a;
		longLen=bLen;
		shortLen=aLen;
	}
	returnStr=malloc(longLen);

	for (int i=longLen,j=shortLen;i>0 || j>0; i--, j--)
	{
		if(j>0)
			returnStr[i-1]=(char)((int)(longStr[i-1])+(int)(shortStr[j-1])+ac);
		else
			returnStr[i-1]=(char)((int)(longStr[i-1])+48+ac);

		if (returnStr[i-1]=='`'){
			returnStr[i-1]='0';
			ac=0;	
		}else if (returnStr[i-1]=='a'){
			returnStr[i-1]='1';
			ac=0;	
		}else if (returnStr[i-1]=='b'){
			returnStr[i-1]='0';
			ac=1;	
		}else if (returnStr[i-1]=='c'){
			returnStr[i-1]='1';
			ac=1;	
		}
	}

	if(ac==1){
		tempStr=malloc(longLen+1);
		tempStr[0]='1';

		for(int i=1;i<longLen+1;i++){
			tempStr[i]=returnStr[i-1];
		}
		tempStr2=returnStr;
		returnStr=tempStr;

		free(tempStr2);
	}

	return returnStr;
}
