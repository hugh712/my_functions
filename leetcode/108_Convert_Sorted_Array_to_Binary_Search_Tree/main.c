#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};
struct TreeNode* sortedArrayToBST(int* nums, int numsSize);
void addBTree(int arr[],int len, struct TreeNode** p);
void visit_preorder(struct TreeNode* p);
void deleteTree(struct TreeNode* p);
void insert(struct TreeNode** tree,int val);
struct TreeNode* insertBST(int* nums,int start, int end);

int main(void)
{
	struct TreeNode* root1=NULL;;
  int arr1[]={-10,-3,0,5,9};
  int size_arr1=sizeof(arr1)/sizeof(int);

	root1=sortedArrayToBST(arr1,size_arr1);
  visit_preorder(root1);
  printf("\n\n");



  deleteTree(root1);
  return 0;
}
struct TreeNode* insertBST(int* nums,int start, int end)
{
	if (start > end)
		return NULL;

	int mid=(start+end)/2;
	struct TreeNode* curr=(struct TreeNode*)malloc(sizeof(struct TreeNode));
	curr->val=nums[mid];
	curr->left=insertBST(nums,start, mid-1);
	curr->right=insertBST(nums,mid+1, end);

	return curr;
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize)
{
	return insertBST(nums,0,numsSize-1);	

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

