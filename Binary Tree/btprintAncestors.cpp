#include <iostream>
using namespace std;

struct node{
    int data;
    node *left,*right;
};

node *newnode(int val){

    node *temp = new node;
    temp->data = val;
    temp->left = temp->right = NULL;

    return temp;
}

bool printAncestors(node *tree,int target){

    if(tree == NULL)
        return false;

    if(tree->data == target)
        return true;

    if( printAncestors(tree->left,target) || printAncestors(tree->right,target)){
        cout<<tree->data<<" ";
        return true;
    }

    return false;
}

int main()
{

  /* Construct the following binary tree
              1
            /   \
          2      3
        /  \
      4     5
     /
    7
  */
  struct node *root = newnode(1);
  root->left        = newnode(2);
  root->right       = newnode(3);
  root->left->left  = newnode(4);
  root->left->right = newnode(5);
  root->left->left->left  = newnode(7);

  printAncestors(root, 7);

  return 0;
}
