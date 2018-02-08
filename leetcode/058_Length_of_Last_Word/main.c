#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char* s);
int main(void)
{
	char str[]="b   a    ";
	int output=0;
	output=lengthOfLastWord(str);

	printf("output=%d\n", output);

	return 0;
}
int lengthOfLastWord(char* s)
{
	int length=strlen(s);
	int count=0;
	int lastCount=0;

	if (length==0)
		return 0;

	for(int i=0;i<length;i++)
	{
		if (s[i]==' ')
		{
			if (count!=0)
				lastCount=count;
			
			count=0;
		}
		else
			count++;	
	}	

	if (count==0)
		count=lastCount;
	return count;
}
