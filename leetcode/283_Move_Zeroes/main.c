#include <stdio.h>

void printArr(int *arr, int len);
void moveZeroes(int* nums, int numsSize);
int main(void)
{
	int Arr[]={0,0,1};
	int len=sizeof(Arr)/sizeof(int);
	moveZeroes(Arr,len);

	printArr(Arr,len);

}
void moveZeroes(int* nums, int numsSize)
{
	int p1=0;
	int p2=numsSize-1;

	while(p1<p2){
		if (nums[p1]==0){
			for (int i=p1;i<p2;i++){
				int temp=0;
				temp=nums[i];
				nums[i]=nums[i+1];
				nums[i+1]=temp;
			}//end of for
			p2--;
		}//end of if
		if(nums[p1]!=0)
			p1++;
	}//end of while
}
void printArr(int *arr, int len)
{
	for(int i=0;i<len;i++)
		printf("%d ",arr[i]);

	printf("\n");
}
