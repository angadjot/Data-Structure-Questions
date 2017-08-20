#include <iostream>
#include <queue>
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

void printBoundaryLeft(node *tree){

  if(tree == NULL)
    return ;

  if(tree->left){
    cout<<tree->data<<" ";
    printBoundaryLeft(tree->left);
  }
  else if(tree->right){
    cout<<tree->data<<" ";
    printBoundaryLeft(tree->right);
  }
}

void printLeaf(node *tree){

  if(tree == NULL)
    return;

  printLeaf(tree->left);

  if(tree->left == NULL && tree->right == NULL) {
    cout<<tree->data<<" ";
  }

  printLeaf(tree->right);

}

void printBoundaryRight(node *tree){

  if(tree == NULL)
    return ;

  if(tree->right){
    printBoundaryRight(tree->right);
    cout<<tree->data<<" ";
  }
  else if(tree->left){
    printBoundaryRight(tree->left);
    cout<<tree->data<<" ";
  }

}

void printBoundary(node *root){

  if(root == NULL)
    return ;

  cout<<root->data<<" ";

  printBoundaryLeft(root->left);
  printLeaf(root->left);
  printLeaf(root->right);
  printBoundaryRight(root->right);

}

int main()
{
    // Let us construct the tree given in the above diagram
    struct node *root         = newNode(20);
    root->left                = newNode(8);
    root->left->left          = newNode(4);
    root->left->right         = newNode(12);
    root->left->right->left   = newNode(10);
    root->left->right->right  = newNode(14);
    root->right               = newNode(22);
    root->right->right        = newNode(25);

    printBoundary( root );

    return 0;
}