#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void addNodes(int arr[],struct ListNode* node,int arrSize);
void freeNodes(struct ListNode* node);
void visitNodes(struct ListNode* node);
struct ListNode* deleteDuplicates(struct ListNode* head);
int main(void)
{
	int Arr[]={1,1,1,1};
	struct ListNode L1;
	struct ListNode *L2;
	int sizeArr=sizeof(Arr)/sizeof(int);

  addNodes(Arr,&L1,sizeArr);
	L2=deleteDuplicates(&L1);
 	visitNodes(L2);	
	freeNodes(&L1);
	freeNodes(L2);

	return 0;
}
struct ListNode* deleteDuplicates(struct ListNode* head)
{
	if(head)
	{
		struct ListNode* p=head;
		while(p->next)
		{
			if(p->val!=p->next->val){
				p=p->next;	
			}
			else{
				struct ListNode* temp=p->next;
				p->next=p->next->next;
				free(temp);
			}
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

