#include <stdio.h>
#include <string.h>

typedef int bool;
#define  true 1
#define  false 0

bool isIsomorphic(char* s, char* t);

int main(void)
{
	char *ss="ab";
	char *tt="ca";
	bool output=false;
	output=isIsomorphic(ss,tt);

	printf("output=%d\n", output);

	return 0;
}

bool isIsomorphic(char* s, char* t) {
	char *hash[128]={0};	
	char *hash_r[128]={0};	
	int len=strlen(s);
	int i=0;

	if (len!=strlen(t))
		return false;

	for (int i=0;i<len;i++){
		if ((hash[s[i]]!=0 && hash[s[i]]!=t[i]) || (hash_r[t[i]]!=0 && hash_r[t[i]]!=s[i])){
			return false;
		}
		else if(hash[s[i]]==t[i]){
			continue;
		}
		else{
			hash[s[i]]=t[i];
			hash_r[t[i]]=s[i];
		}	
	}
	return true; 
}
