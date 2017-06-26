#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

/*
 Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

 The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 */
bool isValid(char* s);

int main(void)
{
	char * pattern="((";
	bool x=isValid(pattern);
	printf(x ? "true":"false");

return 0;
}

bool isValid(char* s)
{
	int len=strlen(s);

	if(len==0 || len==1)
		return 0;

	if (s[0]==')' || s[0]==']' || s[0]=='}')
		return 0;

	char *stack=malloc(sizeof(char)*len); 
	int sp=0;
	int i=0;
	for(i=0;i<len;i++)
	{
		switch(s[i])
		{
			case '(':
			case '[':
			case '{':
				stack[sp++]=s[i];
				break;
			case ')':
			case ']':
			case '}':
				if(stack[sp-1]=='(' && s[i]==')' || 
					 stack[sp-1]=='[' && s[i]==']' ||
					 stack[sp-1]=='{' && s[i]=='}')
				{
					sp--;
					break;
				}
				else
				{
					return 0;
				}
		}
	}
	
	free(stack);

	if(sp==0)
		return 1;
	else
		return 0;
}

