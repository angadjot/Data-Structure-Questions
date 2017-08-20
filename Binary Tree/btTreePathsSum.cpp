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

int treePathsSumUtil(node *root,int val){

    if(root == NULL)
        return 0;

    val = val*10 + root->data;

    if(root->left == NULL && root->right == NULL)
        return val;

    return treePathsSumUtil(root->left,val) + treePathsSumUtil(root->right,val);
}

int treePathsSum(node *root){
    return treePathsSumUtil(root,0);
}

int main()
{
    struct node *root = newNode(6);
    root->left        = newNode(3);
    root->right       = newNode(5);
    root->left->left  = newNode(2);
    root->left->right = newNode(5);
    root->right->right = newNode(4);
    root->left->right->left = newNode(7);
    root->left->right->right = newNode(4);
    printf("Sum of all paths is %d", treePathsSum(root));
    return 0;
}