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

bool areIdentical(node *tree1, node *tree2){

  if(tree1 == NULL && tree2 == NULL)
    return true;

  if(tree1 == NULL || tree2 == NULL)
    return false;

  if(tree1->data == tree2->data && areIdentical(tree1->left,tree2->left) && areIdentical(tree1->right,tree2->right))
    return true;

  return false;

}

bool isSubTree(node *T,node *S){

  if(S == NULL)
    return true;

  if(T == NULL)
    return false;

  if(areIdentical(T,S))
    return true;

  return isSubTree(T->left,S) || isSubTree(T->right,S);

}

int main()
{
    // TREE 1
    /* Construct the following tree
              26
            /   \
          10     3
        /    \     \
      4      6      3
       \
        30
    */
    struct node *T        = newNode(26);
    T->right              = newNode(3);
    T->right->right       = newNode(3);
    T->left               = newNode(10);
    T->left->left         = newNode(4);
    T->left->left->right  = newNode(30);
    T->left->right        = newNode(6);

    // TREE 2
    /* Construct the following tree
          10
        /    \
      4      6
       \
        30
    */
    struct node *S    = newNode(10);
    S->right          = newNode(6);
    S->left           = newNode(4);
    S->left->right    = newNode(30);


    if (isSubTree(T, S))
        printf("Tree 2 is subtree of Tree 1");
    else
        printf("Tree 2 is not a subtree of Tree 1");

    return 0;
}