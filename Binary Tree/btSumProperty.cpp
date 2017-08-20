#include <iostream>
using namespace std;

struct node{
    int data;
    node *left,*right;
};

int isSumProperty(node *tree){

    int left_data = 0, right_data = 0;

    if(tree== NULL || (tree->left == NULL && tree->right == NULL))
        return 1;
    else{

        if(tree->left != NULL)
            left_data = tree->left->data;
        if(tree->right != NULL)
            right_data = tree->right->data;

        if(tree->data == left_data+right_data && isSumProperty(tree->left) && isSumProperty(tree->right))
            return 1;
        else
            return 0;
    }
}

node *newNode(int val){

    node *temp = new node;
    temp->data = val;
    temp->left = temp->right = NULL;

    return temp;
}

int main()
{
  struct node *root  = newNode(10);
  root->left         = newNode(8);
  root->right        = newNode(2);
  root->left->left   = newNode(3);
  root->left->right  = newNode(5);
  root->right->right = newNode(2);
  if(isSumProperty(root))
    printf("The given tree satisfies the children sum property ");
  else
    printf("The given tree does not satisfy the children sum property ");

  return 0;
}