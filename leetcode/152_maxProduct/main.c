#include <stdio.h>

int maxProduct(int* nums, int numsSize);

int main(void){
	int nums [] = {2, 3, -2, 4, 3};
	int output = 0;
	
	output = maxProduct(nums, sizeof(nums)/sizeof(int));
	printf("output=%d\n", output);

	return 0;
}

int maxProduct(int* nums, int numsSize)
{
	int result = nums[0];
	
	for(int i=1, min=result, max=result; i<numsSize; i++)
	{
		// Change min and max because of negtive number
		if (nums[i] < 0){
			int temp = max;
			max = min;
			min = temp;
		}

		max*=nums[i];
		min*=nums[i];

		max = nums[i] > max ? nums[i] : max;
	    min = nums[i] < min ? nums[i] : min;

		result = result > max ? result : max;
	}

	return result;
}

