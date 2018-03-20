#include <stdio.h>
#include <stdlib.h>

int** generate(int numRows, int** columnSizes);
int main(void)
{
	int input=5;
	int *size=NULL;
	int **output=generate(input,&size);


	for (int i=0;i<input;i++){
		free(*(output+i));
		//free(*(size);
		*(output+i)=NULL;
		//*(size+i)=NULL;
	}
	free(output);
	free(size);
	output=NULL;
	size=NULL;

	return 0;
}
int** generate(int numRows, int** columnSizes)
{
	if(numRows==0)
	{
		return NULL;	
	}
	int **result=(int**)malloc(sizeof(int*)*numRows);
	*columnSizes=(int*)malloc(sizeof(int)*numRows);
//	*columnSizes=*size;
	int *last=NULL;
	int i,j=0;

	if(numRows>=1){
		*(result)=(int*)malloc(sizeof(int*));
		//*(size)=(int*)malloc(sizeof(int*));

		**(result)=1;
		**(columnSizes)=1;
	}
	if(numRows>=2){
		*(result+1)=(int*)malloc(sizeof(int*)*2);
		//*(size+1)=(int*)malloc(sizeof(int*));

		**(result+1)=1;
		*(*(result+1)+1)=1;
		*((*columnSizes)+1)=2;
	}

	if(numRows<=2)
		return result;

	last=*(result+1);

	for (i=2;i<numRows;i++){
		*(result+i)=(int*)malloc(sizeof(int*)*i+1);
		//*(size+i)=(int*)malloc(sizeof(int*));

		*((*columnSizes)+i)=i+1;

		//set first and last to 1
		**(result+i)=1;
		*(*(result+i)+i)=1;

		for(j=1;j<i;j++){
			*(*(result+i)+j)=*(last+(j-1)) + (*(last+j));
		}
		last=*(result+i);
	}

	return result;



}
