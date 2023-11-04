#include <stdio.h>

int lengthOfLongestSubstring(char *s);

int main (void){
  char *input = "pwwkew";
  int output = 0;
  output = lengthOfLongestSubstring(input);
  printf("output=%d\n", output);

return 0;
}

int lengthOfLongestSubstring(char *s) {
    int hash[128], i, start = - 1, maxLen = 0;
 
  for (i = 0; i < 128; i++) hash[i] = -1;

  i = 0;
    
  while(s[i]){
        if (hash[s[i]] > start)
            start = hash[s[i]];

        if(i - start > maxLen)
            maxLen = i - start;

        hash[s[i]] = i;
        i++;
    }
    return maxLen;
}
