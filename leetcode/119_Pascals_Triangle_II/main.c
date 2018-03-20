#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* getRow(int rowIndex, int* returnSize);
int main(void)
{
	int input=5;
	int size=0;
	int *output=getRow(input,&size);
	
	free(output);
	output=NULL;
	return 0;
}
int* getRow(int rowIndex, int* returnSize)
{
	int *last=NULL;
	int *curr=NULL;

	if(rowIndex<=0)
	{
		last=(int *)malloc(sizeof(int));
		*last=1;
		*returnSize=1;
	}
	else
	{
		last=(int *)malloc(sizeof(int)*2);
		*last=1;
		*(last+1)=1;
		*returnSize=2;
	}
	
	if(rowIndex<=1)
		return last;


	for (int i=2;i<rowIndex+1;i++)
	{
		curr=(int *)malloc(sizeof(int)*i+1);
		memset(curr,0,i+1);

		*curr=1;
		*(curr+i)=1;
		*returnSize=i+1;
		
		for (int j=1;j<i;j++){
			*(curr+j)=*(last+(j-1)) + (*(last+j));
		}
		free(last);
		last=curr;
	}
	return curr;

}
