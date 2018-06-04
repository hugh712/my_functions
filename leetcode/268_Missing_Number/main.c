#include <stdio.h>
#include <limits.h>

int missingNumber(int* nums, int numsSize);

int main(void)
{
	int arr[]={9,6,4,2,3,5,7,0,1};
	//int arr[]={2,1};
	int size=sizeof(arr)/sizeof(int);
	int output=-1;

	output=missingNumber(arr,size);

	printf("output= %d\n", output);


	return 0;
}



int missingNumber(int* nums, int numsSize) {

	int max=0, i=0, miss=0;
	int sum_miss=0, sum_full=0;
	int isZero=0, diff=0;

	for (;i<numsSize;i++){
		if (nums[i]>=max)
			max=nums[i];

		if(nums[i]==0)
			isZero=1;

		sum_miss+=nums[i];
	}

	for (i=0;i<=max;i++){
		sum_full+=i;
	}

	diff=sum_full-sum_miss;

	if(diff==0)
	{
		if (isZero)
			diff=max+1;
		else
			diff=0;
	}

	return diff;
}
