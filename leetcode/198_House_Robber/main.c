#include <stdio.h>

#define max(a,b) ((a)>(b)?(a):(b))

int rob(int* nums, int numsSize);
void printArr(int *arr, int len);
int main(void)
{
		int arr[]={1,3,5,7,9};
		int len=sizeof(arr)/sizeof(int);
		int output=0;
		
		printArr(arr,len);
		output=rob(arr,len);
		printf("money=%d\n",output);
		return 0;	

}
int rob(int* nums, int numsSize)
{
		if (numsSize==0)
				return 0;
		int a=0,b=0;

		for(int i=0;i<numsSize;i++){
				if(i%2==0){
						a=max(a+nums[i],b);
				}else{
						b=max(a,nums[i]+b);
				}
		}
			
		return max(a,b);
}
void printArr(int *arr, int len)
{
	  for(int i=0;i<len;i++){
			    printf("%d ", arr[i]);
					  }
		  printf("\n");
}

