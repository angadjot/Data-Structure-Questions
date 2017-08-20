#include <iostream>
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

int sum(node *tree){

  if(tree == NULL)
    return 0;

  return sum(tree->left) + tree->data + sum(tree->right);
}

bool isSumTree(node *tree){

  if(tree == NULL || (tree->left == NULL && tree->right == NULL))
    return true;

  int left_sum =0, right_sum = 0;

  left_sum = sum(tree->left);
  right_sum = sum(tree->right);

  if(tree->data == left_sum + right_sum && isSumTree(tree->left) && isSumTree(tree->right))
    return true;

  return false;
}

int main()
{
    struct node *root  = newNode(26);
    root->left         = newNode(10);
    root->right        = newNode(3);
    root->left->left   = newNode(4);
    root->left->right  = newNode(6);
    root->right->right = newNode(3);
    if(isSumTree(root))
        printf("The given tree is a SumTree ");
    else
        printf("The given tree is not a SumTree ");

    return 0;
}