#include <stdio.h>
#include <stdlib.h>
/*
 *Input: 1->2->4, 1->3->4
  Output: 1->1->2->3->4->4
 */

struct ListNode {
     int val;
     struct ListNode *next;
};
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2);
void addNodes(int arr[],struct ListNode* node,int arrSize);
void freeNodes(struct ListNode* node);
void visitNodes(struct ListNode* node);

int main(void)
{
	int L1_Arr1[]={2};
	int L2_Arr2[]={1};
	//int L1_Arr1[]={};
	//int L2_Arr2[]={};


	struct ListNode L1;
	struct ListNode L2;
	struct ListNode *L3;

	int sizeA1=sizeof(L1_Arr1)/sizeof(int);
	int sizeA2=sizeof(L2_Arr2)/sizeof(int);
	addNodes(L1_Arr1,&L1,sizeA1);
	addNodes(L2_Arr2,&L2,sizeA2);
	
	visitNodes(&L1);
	visitNodes(&L2);

	L3=mergeTwoLists(&L1, &L2);

	visitNodes(L3);
	freeNodes(&L1);
	freeNodes(&L2);
	freeNodes(L3);

	return 0;
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
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode* currL1=l1;	
	struct ListNode* currL2=l2;	
	struct ListNode* L3=NULL;
	struct ListNode* origin_L3=NULL;
	int value=0;

	if (l1==NULL && l2==NULL){
		    return NULL;
	}

	L3=(struct ListNode *)malloc(sizeof(struct ListNode));
	origin_L3=L3;
	L3->next=NULL;

	while(currL1!=NULL || currL2!=NULL){
		if(currL2==NULL){
			value=currL1->val;
			if(currL1->next!=NULL){
				currL1=currL1->next;
			}else{
				currL1=NULL;
			}		
		}
		else if(currL1==NULL)
		{
			value=currL2->val;
			if(currL2->next!=NULL){
				currL2=currL2->next;
			}else{
				currL2=NULL;
			}
	
		}
		else if(currL1->val<=currL2->val)
		{
			value=currL1->val;
			if(currL1->next!=NULL){
				currL1=currL1->next;
			}else{
				currL1=NULL;
			}	
		}
		else{
			value=currL2->val;
			if(currL2->next!=NULL){
				currL2=currL2->next;
			}else{
				currL2=NULL;
			}
		}
	
		L3->val=value;
		if(currL1!=NULL || currL2!=NULL){
			L3->next=(struct ListNode *)malloc(sizeof(struct ListNode));
			L3=L3->next;	
		}

	}
	return origin_L3;	

}
