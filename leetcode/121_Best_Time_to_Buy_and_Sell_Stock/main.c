#include <stdio.h>

int maxProfit(int* prices, int pricesSize);

int main()
{
	//int input[]={7,1,5,3,6,4};
	int input[]={7,6,4,3,1};
	int len=sizeof(input)/sizeof(int);
	int output=0;

	output=maxProfit(input,len);

	printf("output=%d\n",output);


	return 0;
}
int maxProfit(int* prices, int pricesSize)
{
	int max=0;

	if(pricesSize==0 || pricesSize==1)
		return 0;

	for(int i=0;i<pricesSize-1;i++){
		for(int j=i+1;j<pricesSize;j++){
			if(prices[j]-prices[i]>max)
				max=prices[j]-prices[i];
		}
	}

	return max;
}
