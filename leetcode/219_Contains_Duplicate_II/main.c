#include <stdio.h>

typedef int bool;
#define true 1
#define false 0

bool containsNearbyDuplicate(int* nums, int numsSize, int k);
int main(void)
{
	int arr[]={1,2,3,1};
	//int arr[]={1,0,1,1};
	//int arr[]={1,2,1};
	//int arr[]={99,99};
	int nums=sizeof(arr)/sizeof(int);
	int n=3;
	bool result=0;

	result=containsNearbyDuplicate(arr,nums,n);

	printf("result=%d\n", result);

}
bool containsNearbyDuplicate(int* nums, int numsSize, int k) {

	int i=0,j=0;
	for (;i<numsSize;i++){
		for (j=numsSize-1;i<j;j--){
			if(nums[i]==nums[j] && j-i<=k)
				return true;
		}
	}

	return false;
}
