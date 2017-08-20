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

void deepestLeftLeafUtil(node *root,int level,int *maxlevel, bool isLeft,node **result){

    if(root == NULL)
        return;

    if(isLeft && root->left == NULL && root->right == NULL && *maxlevel < level){
        *result = root;
        *maxlevel = level;
        return ;
    }

    deepestLeftLeafUtil(root->left,level+1,maxlevel,true,result);
    deepestLeftLeafUtil(root->right,level+1,maxlevel,false,result);
}

node *deepestLeftLeaf(node *root){

    int maxLevel = 0;
    node *result = NULL;
    deepestLeftLeafUtil(root,0,&maxLevel,false,&result);
    return result;
}

int main()
{
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->right->left->right = newNode(7);
    root->right->right->right = newNode(8);
    root->right->left->right->left = newNode(9);
    root->right->right->right->right = newNode(10);

    node *result = deepestLeftLeaf(root);
    if (result)
        cout << "The deepest left child is " << result->data;
    else
        cout << "There is no left leaf in the given tree";

    return 0;
}