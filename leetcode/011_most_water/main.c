#include <stdio.h>

int maxArea(int* height, int heightSize);

int main (void)
{
	int water [] = {1,8,6,2,5,4,8,3,7};
	int output = 0;

	output = maxArea(water, sizeof(water)/sizeof(int));
	printf("The output = %d\n", output);

}

int maxArea(int* height, int heightSize)
{
	int p1 = 0, p2 = heightSize-1;
	int max_area = 0;

	while (p1 < p2){
		int top = height[p1] < height[p2] ? height[p1] : height[p2] ;
		int this_area= top * (p2-p1);
		max_area = max_area > this_area ? max_area : this_area;
	  if (height[p1] > height[p2]){
			p2--;
		}
		else
		{
			p1++;
		}
	}
	return max_area;
}
