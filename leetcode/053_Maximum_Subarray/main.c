#include <stdio.h>

int maxSubArray(int* nums, int numsSize);
int main(void)
{
	//int array[]={-2,1,-3,4,-1,2,1,-5,4};
	int array[]={-2,-1};
	int numsSize=sizeof(array)/sizeof(int);
	int output=0;

	output=maxSubArray(array,numsSize);

	printf("output=%d", output);

	return 0;
}
int maxSubArray(int* nums, int numsSize)
{
	int max=-999;

	if (numsSize==1)
		return nums[0];


	for (int i=0;i<numsSize;i++)
	{
		int sum=0;
		for(int j=i;j<numsSize;j++)
		{
			sum=sum+nums[j];

			if(sum > max)
				max=sum;
		
		}	
	}
	return max;
}
