#include <stdio.h>

int removeDuplicates(int* nums, int numsSize);
void printArr(int* arr, int size);
int main(void)
{
	int arr[]={1,1,2,3,3,4,5};
	int size_arr=sizeof(arr)/sizeof(int);
	int output=0;
	output=removeDuplicates(arr,size_arr);

	printf("output=%d\n", output);
	printArr(arr, output);
	return 0;
}
void printArr(int* arr, int size)
{
	for (int i=0;i<size;i++)
	{
		printf("%d ", arr[i]);
	}
}
int removeDuplicates(int* nums, int numsSize)
{
	int count=1;
	int last=0;
	int replace=1;
	if (numsSize==0 || numsSize==1)
		return numsSize;

	for(int i=1;i<numsSize;i++)
	{
		if (nums[i]==nums[last]){
			last++;
		}
		else{
			nums[replace++]=nums[i];
			last++;	
		}
			
	}//end of for
	return replace;
}
