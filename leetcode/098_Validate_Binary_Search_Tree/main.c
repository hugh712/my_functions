#include <limits.h>
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

bool BSTHelper(struct TreeNode* root, long leftB, long rightB);
void addBTree(int arr[],int len, struct TreeNode** p);
void visit_preorder(struct TreeNode* p);
void deleteTree(struct TreeNode* p);
void insert(struct TreeNode** tree,int val);
bool isValidBST(struct TreeNode* root);
int main(void)
{
	int arr1[]={2,1,3};
  int size_arr1=sizeof(arr1)/sizeof(int);
	struct TreeNode* root1=NULL;

  bool result;

  addBTree(arr1,size_arr1,&root1);

  visit_preorder(root1);
  printf("\n\n");

  result=isValidBST(root1);

  printf("result=%d\n", result);

  deleteTree(root1);
  return 0;	
}

bool BSTHelper(struct TreeNode* root, long leftB, long rightB)
{
  if(!root)
		return true;

	if(root->val <= leftB || root->val >= rightB)
		return false;

	if(root->val <= LONG_MIN || root->val >=LONG_MAX)
		return true;

  return 	BSTHelper(root->left,leftB,root->val) && BSTHelper(root->right,root->val,rightB); 

}
bool isValidBST(struct TreeNode* root)
{
	return BSTHelper(root,LONG_MIN,LONG_MAX);
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

