#include <stdio.h>


int searchInsert(int* nums, int numsSize, int target);
int main(void)
{
	int array[]={0};
	int numsSize=sizeof(array)/sizeof(int);
	int target=2;
	int output;
	output=searchInsert(array,numsSize,target);

	printf("output=%d\n", output );
}
int searchInsert(int* nums, int numsSize, int target)
{

	int i=0;
	if (numsSize==0)
		return 0;

	if (numsSize==1)
	{
		if (nums[0] >= target)
			return 0;
		else
			return 1;	
	}

	for (i=0;i<numsSize;i++)
	{
		if(nums[i]==target)
		{
			return i;
		}
		else if(nums[i]>target)
		{
			return i;
		}

		else if(i != numsSize-1 && nums[i] < target && nums[i+1] > target)
		{
			return i+1;
		}
	}

	return i;

}
