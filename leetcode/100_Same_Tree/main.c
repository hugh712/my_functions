#include <stdio.h>
#include <stdlib.h>

typedef int bool;
#define true 1
#define false 0

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
void addBTree(int arr[],int len, struct TreeNode** p);
void visit_preorder(struct TreeNode* p);
void deleteTree(struct TreeNode* p);
bool isSameTree(struct TreeNode* p, struct TreeNode* q);
void insert(struct TreeNode** tree,int val);
int main(void)
{
	struct TreeNode* root1=NULL;;
	struct TreeNode* root2=NULL;
	int arr1[]={1,2,3};
	int arr2[]={1,2,3,4};
	int size_arr1=sizeof(arr1)/sizeof(int);
	int size_arr2=sizeof(arr2)/sizeof(int);
	bool result;

	addBTree(arr1,size_arr1,&root1);
	addBTree(arr2,size_arr2,&root2);

	visit_preorder(root1);
	printf("\n\n");
	visit_preorder(root2);

	result=isSameTree(root1,root2);

	printf("result=%d\n", result);

	deleteTree(root1);
	deleteTree(root2);
	return 0;
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
	if (p==NULL && q==NULL){
		return true;
	}

	if(p==NULL || q==NULL){
		return false;
	}
	else{	
		if ((p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right)){
			return true;
		}	
		else{
			return false;
		}
	}
}

void addBTree(int arr[],int len, struct TreeNode** p)
{
	for (int i=0;i<len;i++){
				insert(p,arr[i]);
	}
}
void insert(struct TreeNode** tree,int val)
{
	struct TreeNode *temp=NULL;

	if(!*tree)
	{
		temp=(struct TreeNode*)malloc(sizeof(struct TreeNode));
		temp->left=temp->right=NULL;
		temp->val=val;
		*tree=temp;	
		return;
	}

	if(val < (*tree)->val)
	{
			insert(&(*tree)->left,val);
	}else{
			insert(&(*tree)->right,val);
	}
}
void visit_preorder(struct TreeNode* p)
{
	if(p){
		printf("%d ", p->val);
		visit_preorder(p->left);	
		visit_preorder(p->right);	
	}
}
void deleteTree(struct TreeNode* p)
{
	if(p){
		deleteTree(p->left);
		deleteTree(p->right);
		free(p);
	}
}
