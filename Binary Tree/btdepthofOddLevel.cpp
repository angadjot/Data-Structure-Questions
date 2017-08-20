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

int depthOfOddLeafUtil(node *tree,int level){

    if(tree == NULL)
        return 0;

    if(tree->left == NULL && tree->right == NULL && level&1)
        return level;

    return max(depthOfOddLeafUtil(tree->left,level+1),depthOfOddLeafUtil(tree->right,level+1));

}

int depthOfOddLeaf(node *tree){

    return depthOfOddLeafUtil(tree,1);

}

int main()
{
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->right->left->right = newNode(7);
    root->right->right->right = newNode(8);
    root->right->left->right->left = newNode(9);
    root->right->right->right->right = newNode(10);
    root->right->right->right->right->left = newNode(11);

    printf("%d is the required depth\n", depthOfOddLeaf(root));
    return 0;
}


