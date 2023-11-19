#include <stdio.h>
#include <stdlib.h>

int findCenter(int** edges, int edgesSize, int* edgesColSize);

int main ()
{
  int n=0, r=3, c=2;
	int center=0;
	int **edges = (int **)malloc(r * sizeof(int*));
	int value [] = {1,2,2,3,4,2};
	int edgesColSize [3]={2,2,2};

	for (int i=0; i<r;i++)
	{
		edges[i] = (int*)malloc(sizeof(int)*c);
		edges[i][0] = value[n++];
		edges[i][1] = value[n++];
	
	}
	center = findCenter(edges, 3, edgesColSize );
	printf("center = %d\n", center);

	for (int i=0; i<r;i++)
		free(edges[i]);

	free(edges);
	return 0;
}

int findCenter(int** edges, int edgesSize, int* edgesColSize){
    int x;
    x=(edges[0][0]==edges[1][0] || edges[0][0]==edges[1][1]) ? edges[0][0] : edges[0][1];
   return x;
}
