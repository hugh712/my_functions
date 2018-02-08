#include <stdio.h>

void printArr(int Arr[][4], int row, int col);
void printArr2(int **Arr, int row, int col);
void rotate(int** matrix, int matrixRowSize, int *matrixColSizes);
int main(void)
{
	int Arr[4][4]={{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
	int *Arr2[16];
	int colSize=4;
	for(int i=0;i<16;i++)
		Arr2[i]=Arr[i];
	
	rotate(Arr2, 4,&colSize);
	//printArr(Arr,4,4);
	printArr2(Arr2,4,4);

	return 0;
}
void rotate(int** matrix, int matrixRowSize, int *matrixColSizes)
{
	int n=matrixRowSize;
	for(int i=0;i<n/2;i++){
		for(int j=i;j<n-i-1;j++){
			int z=matrix[i][j];
			matrix[i][j]=matrix[n-j-1][i];
			matrix[n-j-1][i]=matrix[n-i-1][n-j-1];
			matrix[n-i-1][n-j-1]=matrix[j][n-i-1];
			matrix[j][n-i-1]=z;
		}
	}
}
void printArr(int Arr[][4], int row, int col)
{
	for(int i=0;i<row;i++){
		for (int j=0;j<col;j++){
			printf("%d ", Arr[i][j]);
		}
		printf("\n");
	}	
}
void printArr2(int **Arr, int row, int col)
{
	for(int i=0;i<row;i++){
		for (int j=0;j<col;j++){
			printf("%d ", Arr[i][j]);
		}
		printf("\n");
	}	
}
