#include <stdio.h>

typedef int bool;
#define true 1
#define false 0

bool isBadVersion(int version);
int firstBadVersion(int n);

int main(void)
{
	int a=2;
  int result=0;

	result=firstBadVersion(a);	
	printf("result=%d\n", result);

	return 0;
}
int firstBadVersion(int n)
{
	int p1=0,p2=n;
	int middle=(p2-p1)/2;

  if(n==1)
		if(isBadVersion(1))
			return true;
		else		
			return false;

	while((p2-p1)>1){
		if(!isBadVersion(middle)){
			p1=middle;
			
		}else{
		  if(!isBadVersion(middle-1))
				return middle;
			p2=middle;
		}
		
		middle=p1+(p2-p1)/2;
	}
	
	//last one
	if(isBadVersion(n))
		return n;
	else
		return -1;

}
bool isBadVersion(int version)
{
	int gate=2;
	if (version >= gate)
		return true;
	else
		return false;		
}
