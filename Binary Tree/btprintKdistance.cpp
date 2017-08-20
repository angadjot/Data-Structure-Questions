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

void printKdistance(node *tree,int k){

  if(tree == NULL)
    return ;

  if(k == 0){
    cout<<tree->data<<endl;
    return;
  }
  else{
    printKdistance(tree->left,k-1);
    printKdistance(tree->right,k-1);
  }
}

int main()
{

  /* Constructed binary tree is
            1
          /   \
        2      3
      /  \    /
    4     5  8
  */
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(8);

  printKdistance(root, 2);

  getchar();
  return 0;
}