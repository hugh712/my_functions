#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	    int val;
			struct ListNode *next;
};

void addNodes(int arr[],struct ListNode* node,int arrSize);
void freeNodes(struct ListNode* node);
void visitNodes(struct ListNode* node);
struct ListNode* removeElements(struct ListNode* head, int val);

int main(void)
{
	//int Arr[]={1,2,3,4,5,6,7,8,9,6,9,8,7};
	//int Arr[]={6,6,6,6,6,6,6,7};
	int Arr[]={6,6};
	//int Arr[]={1,2,6,3,4,5,6};
  struct ListNode *L1=(struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *L2;
  int sizeArr=sizeof(Arr)/sizeof(int);
  addNodes(Arr,L1,sizeArr);
  visitNodes(L1); 
	L2=removeElements(L1,6);
  if(L2)
		visitNodes(L2);
  if(L2)	
  	freeNodes(L2);

	return 0;
}
struct ListNode* removeElements(struct ListNode* head, int val) {
	if (!head)
		return NULL;
	struct ListNode *prev=NULL;
	struct ListNode *curr=head;
	struct ListNode *tmp=NULL;

	while (curr){
		if(curr->val==val){
			tmp=curr;
			
			if(prev){
				prev->next=curr->next;
			}
			else{
				head=curr->next;
			}
			curr=curr->next;
			free(tmp);
		}
		else{
			prev=curr;
			curr=curr->next;
		}
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


