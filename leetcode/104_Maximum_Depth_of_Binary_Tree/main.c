#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void addBTree(int arr[],int len, struct TreeNode** p);
void visit_preorder(struct TreeNode* p);
void deleteTree(struct TreeNode* p);
void insert(struct TreeNode** tree,int val);
int maxDepth(struct TreeNode* root);
int main(void)
{
	struct TreeNode* root1=NULL;;
  int arr1[]={5,2,4,6};
  int size_arr1=sizeof(arr1)/sizeof(int);
  int result;

  addBTree(arr1,size_arr1,&root1);

  visit_preorder(root1);
  printf("\n\n");

  result=maxDepth(root1);

  printf("result=%d\n", result);

  deleteTree(root1);
  return 0;
}
int maxDepth(struct TreeNode* root)
{
	if(root==NULL)
		return 0;
	else if(root->left==NULL && root->right==NULL)
		return 1;

	int ll=maxDepth(root->left);	
	int rr=maxDepth(root->right);	

	if(ll>rr)
		return ll+1;
	else
		return rr+1;
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

