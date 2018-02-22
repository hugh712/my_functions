#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize);
void visitArray(int * arr, int size);

int main(void)
{
	//int arr[]={9,9,9,9};
	//int arr[]={1,2,3,4};
	//int arr[]={7,3,5,9};
	int arr[]={0};
	int length=sizeof(arr)/sizeof(int);
	int returnSize=0;
	int *output;

	output=plusOne(arr,length,&returnSize);

	//visitArray(arr,length);
	visitArray(output,returnSize);
	
	free(output);
	return 0;
}

int* plusOne(int* digits, int digitsSize, int* returnSize)
{
	int ac=1;
	int *newArr=NULL;

	for (int i=digitsSize-1;i>=0;i--)
	{
		
		if(ac>=1)
		{
			digits[i]=digits[i]+1;
			ac=0;
		}
		if (digits[i]>=10)
		{
			digits[i]=0;
			ac=1;	
		}	
	}

	if(ac>=1)
	{
		*returnSize=digitsSize+1;
	}
	else
	{
		*returnSize=digitsSize;
	}

	newArr=malloc(sizeof(int)*(*returnSize));

	for(int i=digitsSize-1;i>=0;i--)
	{
		newArr[i]=digits[i];
	}

	if(ac>=1)
	{
		newArr[0]=1;
	}

	return newArr;

}
void visitArray(int * arr, int size)
{
	for (int i=0;i<size;i++)
	{
		printf("%d ", arr[i]);
	}
}
