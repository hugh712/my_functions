#include <stdio.h>

void printArr(int* nums, int numsSize);
void merge(int* nums1, int m, int* nums2, int n);
int main(void)
{
	int a[]={1,2,3,5,7};
	int b[]={2,3,4,6,8};

	int size_a=sizeof(a)/sizeof(int);
	int size_b=sizeof(b)/sizeof(int);

	merge(a, size_a, b, size_b);

	
	size_a=sizeof(a)/sizeof(int);

	printArr(a, size_a);

	return 0;
}
void merge(int* nums1, int m, int* nums2, int n)
{



}
void printArr(int* nums, int numsSize)
{
  for (int i=0;i<numsSize;i++){
    printf("%d ", nums[i]);
  }
}

