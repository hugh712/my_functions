#include <stdio.h>
#include <stdlib.h>

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize);
void printArr(int* nums, int len);
int main (void)
{
	int arr1[]={1,2,2,1,5,7};
	int arr2[]={2,7,2};
	int* arr3;
	int len1=sizeof(arr1)/sizeof(int);
	int len2=sizeof(arr2)/sizeof(int);
	int lenout=0;

	arr3=intersect(arr1,len1,arr2,len2,&lenout);
		
	printArr(arr3,lenout);

	free(arr3);

	return 0;
}
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
	int *longArr;
	int *shortArr;
	int longLen=0;
	int shortLen=0;
	int * nums3=NULL;
	*returnSize=0;
	if(nums1Size==0 || nums2Size==0){
		*returnSize=0;
		return NULL;
	}

	if (nums1Size >=nums2Size){
		longArr=nums1;
		shortArr=nums2;
		longLen=nums1Size;
		shortLen=nums2Size;
	}else{
		longArr=nums2;
		shortArr=nums1;
		longLen=nums2Size;
		shortLen=nums1Size;
	}

	for(int i=0;i<shortLen;i++){
		for(int j=0;j<longLen;j++){
			if(shortArr[i]==longArr[j]){
				(*returnSize)++;
				nums3=realloc(nums3, (*returnSize)*sizeof(int));
				nums3[*returnSize-1]=shortArr[i];
				break;
			}
		}
	}
	return nums3;
}
void printArr(int* nums, int len)
{
	for(int i=0;i<len;i++){
		printf("%d ", nums[i]);
	}
	printf("\n ");
}
