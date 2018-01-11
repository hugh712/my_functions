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
void insert(struct TreeNode** tree,int val);
bool isSymmetric(struct TreeNode* root);
bool isSymmetricRecursive(struct TreeNode* Lnode, struct TreeNode* Rnode);

int main(void)
{
	struct TreeNode* root1=NULL;;
  int arr1[]={1,2,3};
  int size_arr1=sizeof(arr1)/sizeof(int);
  bool result;

  addBTree(arr1,size_arr1,&root1);

  visit_preorder(root1);
  printf("\n\n");

  //result=isSymmetric(root1);

  printf("result=%d\n", result);

  deleteTree(root1);

	return 0;
}
bool isSymmetric(struct TreeNode* root)
{
	if(root==NULL)
		return true;

	return isSymmetricRecursive(root->left, root->right);

}
bool isSymmetricRecursive(struct TreeNode* Lnode, struct TreeNode* Rnode)
{
	if (Lnode==NULL && Rnode==NULL)
		return true;
	else if(Lnode==NULL || Rnode==NULL)
		return false;

	return ((Lnode->val!=Rnode->val) && isSymmetricRecursive(Lnode->left, Rnode->right) && isSymmetricRecursive(Lnode->right, Rnode->left));

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

  if(!*tree){
    temp=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    temp->left=temp->right=NULL;
    temp->val=val;
    *tree=temp;
    return;
  }

  if(val < (*tree)->val){
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

