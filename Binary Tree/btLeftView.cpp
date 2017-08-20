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

void leftViewUtil(node *root,int level,int *max_level){

    if(root == NULL)
        return;

    if(*max_level < level){
        *max_level = level;
        cout<<root->data<<" ";
    }

    leftViewUtil(root->left,level+1,max_level);
    leftViewUtil(root->right,level+1,max_level);

}

void leftView(node *root){

    int level = 1,max_level = 0;

    leftViewUtil(root,level,&max_level);
}

int main()
{
    struct node *root = newNode(12);
    root->left = newNode(10);
    root->right = newNode(30);
    root->right->left = newNode(25);
    root->right->right = newNode(40);

    leftView(root);

    return 0;
}