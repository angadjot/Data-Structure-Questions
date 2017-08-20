#include <iostream>
using namespace std;

struct node{
    int data;
    node *left,*right;
};

node* newNode(int val){

    node *temp = new node;
    temp->data = val;
    temp->left = temp->right = NULL;

    return temp;
}

bool isBalanced(node *tree,int *height){

    int lh=0,rh=0;

    int l=0,r=0;

    if(tree==NULL){
        *height = 0;
        return 1;
    }

    l = isBalanced(tree->left,&lh);
    r = isBalanced(tree->right,&rh);

    *height = max(lh,rh)+1;

    if((lh-rh >= 2) || (rh-lh >= 2))
        return false;

    return l && r;
}

int main(){
    int height = 0;

  /* Constructed binary tree is
             1
           /   \
         2      3
       /  \    /
     4     5  6
    /
   7
  */
  struct node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6);
  root->left->left->left = newNode(7);

  if(isBalanced(root, &height))
    printf("Tree is balanced");
  else
    printf("Tree is not balanced");

  return 0;
}