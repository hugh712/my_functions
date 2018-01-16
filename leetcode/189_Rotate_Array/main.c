#include <stdio.h>
#include <stdlib.h>

void printArr(int *arr, int len);
void swap(int * a, int * b);
void rotate(int* nums, int numsSize, int k);
int main(void)
{
	int arr[]={1,2,3,4,5,6,7};
	int len=sizeof(arr)/sizeof(int);

	printArr(arr,len);
	rotate(arr,len,11);
	printArr(arr,len);
	return 0;
}
void printArr(int *arr, int len)
{
	for(int i=0;i<len;i++){
		printf("%d ", arr[i]);
	}	
	printf("\n");
}
void swap(int * a, int * b)
{
	*a=*a+*b;
	*b=*a-*b;
	*a=*a-*b;
}
void rotate(int* nums, int numsSize, int k)
{
		int *arr2=malloc(sizeof(int)*numsSize);
		k=k%numsSize;

		for(int i=0;i<numsSize;i++){
			int newIndex=((i+k)>=numsSize)?(i+k-numsSize):i+k;
			arr2[newIndex]=nums[i];
		}

		for (int j=0;j<numsSize;j++){
			nums[j]=arr2[j];
		}
		free(arr2);

}
