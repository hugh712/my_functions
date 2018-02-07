#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
typedef int bool;
#define true 1
#define false 0

void addNodes(int arr[],struct ListNode* node,int arrSize);
void freeNodes(struct ListNode* node);
void visitNodes(struct ListNode* node);
bool hasCycle(struct ListNode *head);
int main(void)
{
		 int L1_Arr1[]={-21,10,17,8,4,26,5,35,33,-7,-16,27,-12,6,29,-12,5,9,20,14,14,2,13,-24,21,23,-21,5};
     struct ListNode L1;
     int sizeA1=sizeof(L1_Arr1)/sizeof(int);
     bool result;
		 addNodes(L1_Arr1,&L1,sizeA1);
     visitNodes(&L1);
		 result=hasCycle(&L1);
		 printf("result=%d\n", result);

     freeNodes(&L1);
     return 0;

}
bool hasCycle(struct ListNode *head)
{
	if (!head)
		return false;
	struct ListNode *O1=head;
	struct ListNode *p2=head;
	int c1,c2;
	
	if(!head->next)
		false;
	head=head->next;
	c1=1;

	while(head){
		p2=O1;
		c2=0;
		while(p2 && c2<c1){
			if(head->next==p2){
				return true;
			}
			c2++;
			p2=p2->next;
		}
		c1++;
		head=head->next;	
	}
	return false;
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

