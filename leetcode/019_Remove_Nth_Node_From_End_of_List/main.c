#include <stdio.h>
#include <stdlib.h>

struct ListNode {
     int val;
     struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n);
void addNodes(int arr[],struct ListNode* node,int arrSize);
void freeNodes(struct ListNode* node);
void visitNodes(struct ListNode* node);
int main(void)
{
	int L1_Arr1[]={2,3};
  struct ListNode L1;
  struct ListNode *L2;
  int sizeA1=sizeof(L1_Arr1)/sizeof(int);
	int count=0;
  addNodes(L1_Arr1,&L1,sizeA1);

  visitNodes(&L1);
	L2=removeNthFromEnd(&L1,2);

  visitNodes(L2);
  freeNodes(L2);


	return 0;
}
struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
		struct ListNode* first=head;
		struct ListNode* second=head;

		while(first){
				first=first->next;

				if (n-- < 0)
					second=second->next;
		}

		if(n==0){
				first=head;
				head=head->next;
				free(first);
		}
		else{
				first=second->next;
				second->next=second->next->next;
				free(first);
		}
		return head;
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

