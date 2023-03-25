#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target);
int* twoSum_2(int* nums, int numsSize, int target, int* returnSize);

int main(void)
{
	//Input: numbers={2, 7, 11, 15}, target=9
	//Output: index1=1, index2=2
int  array[]={2, 7, 11, 15,20};
int tar=9;
int* index;

index=twoSum(array, sizeof(array), tar);

if(index[0]==-1)
{
	printf("not fount!!\n");	
}
else
{
	printf("fount it, index= %d, %d\n", index[1], index[2]);
}

free(index);

return 0;
}

/**

 * Note: The returned array must be malloced, assume caller calls free().

 */

int* twoSum(int* nums, int numsSize, int target) {

int i=0, j=0;
int* result;

result=malloc(sizeof(int)*3);
result[0]=-1; //mean failt

for (;i<numsSize/4;i++)
{
	result[1]=i;
	for(j=i+1;j<numsSize/4;j++)
	{
		if(nums[i]+nums[j]==target)
		{
			result[0]=-2;//meant succesuss
			result[2]=j;
			break;
		}
	
	}//end of inner for
	if(result[0]==-2)
		break;

}//end of for

return result;
}

int* twoSum_2(int* nums, int numsSize, int target, int* returnSize){
    int* answer = (int*)malloc(sizeof(int)*2);

    for (int i=0; i<numsSize; i++)
    {
        for (int j=i+1; j<numsSize; j++)
        {
            if (nums[i]+nums[j] == target)
            {
                answer[0] = i;
                answer[1] = j;
                *returnSize = sizeof(answer)/sizeof(int);
                break;
            }
        }
    }

    return answer;
}
