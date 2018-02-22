#include <stdio.h>

typedef int bool;
#define true 1
#define false 0

bool containsDuplicate(int* nums, int numsSize);
int main(void)
{
	int arr[]={1,2,3,4,5,6,7};	
	int len=sizeof(arr)/sizeof(int);
	bool output=containsDuplicate(arr,len);

	printf("output=%d\n", output);
}
bool containsDuplicate(int* nums, int numsSize)
{
	
	if (numsSize==0 || numsSize==1)
		return false;
	
	for(int i=0;i<numsSize-1;i++){
		for (int j=i+1;j<numsSize;j++){
			if(nums[i]==nums[j])	
				return true; 
		}
	}
	return false;
}
