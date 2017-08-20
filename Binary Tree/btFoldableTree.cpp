#include <iostream>
#include <queue>
using namespace std;

struct node{
    int data;
    node *left,*right;
};

node *newNode(int val){

    node *temp = new node;
    temp->data = val;
    temp->left = temp->right = NULL;

    return temp;
}

bool isFoldableUtil(node *n1,node *n2){

    if(n1 == NULL && n2 == NULL)
        return true;

    if(n1 == NULL || n2 == NULL)
        return false;

    return isFoldableUtil(n1->left,n2->right) && isFoldableUtil(n1->right,n2->left);
}

bool isFoldable(node *tree){

    if(tree == NULL)
        return true;

    return isFoldableUtil(tree->left,tree->right);
}

int main(void)
{
  /* The constructed binary tree is
         1
       /   \
      2     3
      \    /
       4  5
  */
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->right  = newNode(4);
  root->right->left = newNode(5);

  if(isFoldable(root) == true)
  { printf("\n tree is foldable"); }
  else
  { printf("\n tree is not foldable"); }

  return 0;
}