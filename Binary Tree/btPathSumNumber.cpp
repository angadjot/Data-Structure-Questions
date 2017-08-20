#include <iostream>
using namespace std;

struct node{
    int data;
    node *left,*right;
};

node* newnode(int val){

    node *temp = new node;
    temp->data = val;
    temp->left = temp->right = NULL;

    return temp;
}

bool hasPathSum(node *tree,int sum){

    if(tree == NULL){
        if(sum == 0)
            return true;
        else
            return false;
    }

    bool ans = false;

    int subSum = sum - tree->data;

    if(subSum == 0 && tree->left == NULL && tree->right == NULL)
        return true;

    if(tree->left != NULL)
        ans = ans || hasPathSum(tree->left,subSum);

    if(tree->right != NULL)
        ans = ans || hasPathSum(tree->right,subSum);

    return ans;
}

int main(){

    int sum = 21;

  /* Constructed binary tree is
            10
          /   \
        8      2
      /  \    /
    3     5  2
  */
  struct node *root = newnode(10);
  root->left        = newnode(8);
  root->right       = newnode(2);
  root->left->left  = newnode(3);
  root->left->right = newnode(5);
  root->right->left = newnode(2);

  if(hasPathSum(root, sum))
    printf("There is a root-to-leaf path with sum %d", sum);
  else
    printf("There is no root-to-leaf path with sum %d", sum);

 return 0;

}