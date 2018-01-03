#include <stdio.h>


int removeElement(int* nums, int numsSize, int val);
void printArr(int* nums, int numsSize);
int main (void)
{
	int arr[]={3,2,2,3,4,4,4,4,3,5};
	int sizeArr=sizeof(arr)/sizeof(int);
	int output=0;
	output=removeElement(arr,sizeArr,3);
	printf("output=%d\n", output);
	printArr(arr,output);
	return 0;
}
void printArr(int* nums, int numsSize)
{
	for (int i=0;i<numsSize;i++)
	{
		printf("%d ", nums[i]);
	}

}
int removeElement(int* nums, int numsSize, int val)
{
	int r=0;

	if (numsSize==0)
		return 0;

	for (int i=0;i<numsSize;i++)
	{
		if(nums[i]==val){
			continue;
		}
		else if(i!=r){
			if (nums[i]!=val)
				nums[r++]=nums[i];
		}
		else{
			r++;
		}

	}
	return r;
}
