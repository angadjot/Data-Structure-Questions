#include <iostream>
using namespace std;

struct node{
    int data;
    node *left,*right;
};

void rightViewUtil(node *root,int level,int *max_level){

    if(root == NULL)
        return;

    if(*max_level < level){
        *max_level = level;
        cout<<root->data<<" ";
    }

    rightViewUtil(root->right,level+1,max_level);
    rightViewUtil(root->left,level+1,max_level);

}

void rightView(node *root){

    int level = 1,max_level = 0;

    rightViewUtil(root,level,&max_level);
}