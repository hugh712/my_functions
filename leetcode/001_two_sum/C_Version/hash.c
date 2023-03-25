#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct{
	int key;
	int value;
} Htable;

int hash(int key, int numsSize){
	int SIZE = numsSize;
	int r = (abs(key) * 17) % SIZE;
	return r;
}

void insert (Htable* hashT,int numsSize, int value, int arr_index)
{

	int index = hash(value, numsSize);

  while (hashT[index].key)
  {
      index = (index + 1) % numsSize;
  }

  hashT[index].key = arr_index;
  hashT[index].value = value;
}

int search (Htable* hashT,int numsSize, int value)
{

	int index = hash(value, numsSize);

	
	while (hashT[index].key)
  {
      if (hashT[index].value == value)
      {
          return hashT[index].key;
      }
      index = (index + 1) % numsSize;
  }
  
	return 0;
}

void init_hash_table(Htable* hashT, int numsSize)
{
	for (int i=0; i<numsSize; i++)
	{
		hashT[i].key=0;
		hashT[i].value=0;
	}
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
	*returnSize = 2;
	Htable* table = (Htable*)malloc(sizeof(Htable)*numsSize);
	init_hash_table(table, numsSize);

	for (int i = 0; i < numsSize; i++)
	{
		int complements = target - nums[i];
		int value = search(table, numsSize,  complements);

		if (value)
		{
			int* indices = (int *)malloc(sizeof(int) * 2);
			indices[0] = value - 1;
			indices[1] = i;
			return indices;
		}
		insert(table, numsSize, nums[i], i+1);
	}

	free(table);
	return NULL;
}

void printArr(int* nums, int numsSize)
{
  for (int i=0;i<numsSize;i++){
    printf("%d ", nums[i]);
  }
	printf("\n");
}

int main (void)
{
	int array[] = {-3,4,3,90};
	int tar = 0 ;
	int array_len;
	int* index;
	int* returnSize;

	array_len = sizeof(array) / sizeof(int);
	returnSize = (int*)malloc(sizeof(int));
	
	index = twoSum(array, array_len, tar, returnSize);

	printArr(index, *returnSize);
	free(returnSize);
	free(index);

	return 0;
}
