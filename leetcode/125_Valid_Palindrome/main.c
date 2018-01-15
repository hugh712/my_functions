#include <stdio.h>
#include <string.h>

typedef int bool;
#define true 1
#define false 0

bool isPalindrome(char* s);
bool isRange(char c);
int main(void)
{
	//char *str="A man, a plan, a canal: Panama";
	char *str="0P0";
	bool output=isPalindrome(str);

	//A-Z 65~90
	//a-z 97~122

	printf("output=%d\n",output);
	return 0;
}

bool isRange(char c)
{
	int cn=(int)c;
	return ((cn>=65 && cn<=90) || (cn>=97 && cn<=122) || (cn>=48 && cn<=57));	
}
char toLower(char c)
{
	if((int)c >= 65 && (int)c <=90)
		return (char)((int)c+32);
	else 
		return c;
}
bool isPalindrome(char* s)
{
	int p2=strlen(s);
	int p1=0;

	if (p2==0 || p2==1)
		return true;

	while(p1<=p2){
		if(!isRange(s[p1])){
				p1++;
				continue;
		}
		else if(!isRange(s[p2])){
				p2--;
				continue;
		}

		if(toLower(s[p1++])!=toLower(s[p2--]))
			return false;
	}

	return true;

}
