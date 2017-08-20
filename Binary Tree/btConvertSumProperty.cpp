#include <iostream>
using namespace std;

struct node{
    int data;
    node *left, *right;
};

void increment(node *tree,int diff){

    if(tree->left != NULL){
        tree->left->data +=diff;

        increment(tree->left,diff);
    }
    else if(tree->right != NULL){
        tree->right->data += diff;

        increment(tree->right,diff);
    }
}

void ConvertTree(node *tree){

    int left_data = 0, right_data =0;

    if(tree == NULL || (tree->left == NULL && tree->right == NULL))
        return ;
    else{

        ConvertTree(tree->left);
        ConvertTree(tree->right);

        if(tree->left != NULL)
            left_data = tree->left->data;

        if(tree->right != NULL)
            right_data = tree->right->data;

        int diff = left_data + right_data - tree->data;

        if(diff>0)
            tree->data += diff;

        else if(diff < 0){
            increment(tree,-diff);
        }
        else
            return ;
    }
}

void printInorder(struct node* node)
{
  if (node == NULL)
    return;

  printInorder(node->left);

  printf("%d ", node->data);

  printInorder(node->right);
}

node* newNode(int val){

    node *temp = new node;
    temp->data = val;
    temp->left = temp->right = NULL;

    return temp;
}

int main()
{
  struct node *root = newNode(50);
  root->left        = newNode(7);
  root->right       = newNode(2);
  root->left->left  = newNode(3);
  root->left->right = newNode(5);
  root->right->left  = newNode(1);
  root->right->right = newNode(30);

  printf("\n Inorder traversal before conversion ");
  printInorder(root);

  ConvertTree(root);

  printf("\n Inorder traversal after conversion ");
  printInorder(root);

  return 0;
}