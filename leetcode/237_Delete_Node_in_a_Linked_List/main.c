#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
void addNodes(int arr[],struct ListNode* node,int arrSize);
void freeNodes(struct ListNode* node);
void visitNodes(struct ListNode* node);
void deleteNode(struct ListNode* node);
int main(void)
{
		 int L1_Arr1[]={2,1,3,5,8};
		 struct ListNode L1;
		 struct ListNode *currNode;
		 int sizeA1=sizeof(L1_Arr1)/sizeof(int);
		 addNodes(L1_Arr1,&L1,sizeA1);
		 currNode=&L1;
		 visitNodes(&L1);
		 for (int i=0;i<sizeA1;i++){
				if(currNode->val==3){			
		 			deleteNode(currNode);
					break;
				}
				else{
					currNode=currNode->next;
				}
		 }
		 
		 visitNodes(&L1);
		 freeNodes(&L1);
			return 0;
}
void deleteNode(struct ListNode* node)
{
	*node=*node->next;
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

