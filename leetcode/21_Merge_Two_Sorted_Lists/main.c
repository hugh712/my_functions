#include <stdio.h>
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
	int L1_Arr1[]={1,2,4};
	int L2_Arr2[]={1,3,4};

	struct ListNode L1;
	struct ListNode L2;

	int sizeA1=sizeof(L1_Arr1)/sizeof(int);
	int sizeA2=sizeof(L2_Arr2)/sizeof(int);
	addNodes(&L1_Arr1,&L1,sizeA1);
	addNodes(&L2_Arr2,&L2,sizeA2);


	return 0;
}
void freeNodes(struct ListNode* node){


}
void addNodes(int arr[],struct ListNode* node, int arrSize){

	struct ListNode* currNode=node;	
	for (int i=0;i<arrSize;i++){
		
	}
}
void visitNodes(struct ListNode* node){
	struct ListNode* currNode=node;	
	printf("%d->", currNode->val);

	while(currNode->next!=NULL){
		currNode=currNode->next;
		printf("%d->", currNode->val);
	}

}
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    
}
