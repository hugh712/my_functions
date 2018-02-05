#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
typedef int bool;
#define true 1
#define false 0
void printArr(int *arr, int len);
void addNodes(int arr[],struct ListNode* node,int arrSize);
void freeNodes(struct ListNode* node);
void visitNodes(struct ListNode* node);
bool isPalindrome(struct ListNode* head);

int main(void)
{
	int L1_Arr1[]={1,2,3,2,1,4};
  struct ListNode L1;
  int sizeA1=sizeof(L1_Arr1)/sizeof(int);
	bool result;;
  addNodes(L1_Arr1,&L1,sizeA1);

  visitNodes(&L1);
  result=isPalindrome(&L1);

  freeNodes(&L1);
	printf("result=%d\n", result);

  return 0;
}
bool isPalindrome(struct ListNode* head)
{
		if(!head)
			return true;

		int count=0;
		int* arr=malloc(sizeof(int));

		//get all values
		while(head){
				count++;
				arr=realloc(arr,sizeof(int)*count);
				arr[count-1]=head->val;
				head=head->next;
		}

		//check Value
		for (int i=0;i<count/2;i++){
				if(arr[i]!=arr[count-i-1])
					return false;
		}
		free(arr);
	return true;
}
void freeNodes(struct ListNode* node){
  //free from second node
  struct ListNode* currNode=NULL;
  struct ListNode* lastNode=NULL;

  if(node->next==NULL)
    return;

  currNode=node->next;


  while(currNode->next!=NULL){
    lastNode=currNode;
    currNode=currNode->next;
    free(lastNode);
  }

  free(currNode);

}
void addNodes(int arr[],struct ListNode* node, int arrSize){

  struct ListNode* currNode=node;
  struct ListNode* nextNode=NULL;
  for (int i=0;i<arrSize;i++){
    currNode->val=arr[i];
    if (i==arrSize-1){
      currNode->next=NULL;
    }else{
      nextNode=malloc(sizeof(struct ListNode));
      currNode->next=nextNode;
      currNode=currNode->next;
    }
  }
}
void visitNodes(struct ListNode* node){
  struct ListNode* currNode=node;
  printf("%d->", currNode->val);

  while(currNode->next!=NULL){
    currNode=currNode->next;
    printf("%d->", currNode->val);
  }

  printf("\n");
}
void printArr(int *arr, int len)
{
	  for(int i=0;i<len;i++){
			    printf("%d ", arr[i]);
					  }
		  printf("\n");
}


