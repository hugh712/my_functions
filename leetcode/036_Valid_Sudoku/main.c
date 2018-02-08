#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int bool;
#define true 1
#define false 0

void printArr(char **table, int row, int col);
bool isValidSudoku(char** board, int boardRowSize, int boardColSize);
int main(void)
{
	char table[9][9]={{'.','.','.','.','5','.','.','1','.'},{'.','4','.','3','.','.','.','.','.'},{'.','.','.','.','.','3','.','.','1'},{'8','.','.','.','.','.','.','2','.'},{'.','.','2','.','7','.','.','.','.'},{'.','1','5','.','.','.','.','.','.'},{'.','.','.','.','.','2','.','.','.'},{'.','2','.','9','.','.','.','.','.'},{'.','.','4','.','.','.','.','.','.'}};
	char *table2[81];
	bool result=0;

	for(int i=0;i<9*9;i++)
		table2[i]=table[i];	

	printArr(table2,9,9);	
	result=isValidSudoku(table2,9,9);
	printf("result=%d\n", result);

	return 0;
}
bool isValidSudoku(char** board, int boardRowSize, int boardColSize)
{
	int rtable[9][9]={0};
	int ctable[9][9]={0};
	int blocktable[3][3][9]={0};
	for (int r=0;r<boardRowSize;r++){
		for (int c=0;c<boardColSize;c++){
			if( board[r][c]!='.'){
					int value=board[r][c]-'1';
					if(rtable[r][value]++)	return false;	
					if(ctable[c][value]++)	return false;	
					if(blocktable[r/3][c/3][value]++) return false;
			}
		}
	}
	return true;
}
void printArr(char **table, int row, int col)
{
	for (int i=0;i<row;i++){
		for (int j=0;j<col;j++){
			printf("%c ", table[i][j]);
		}
		printf("\n");
	}
}
