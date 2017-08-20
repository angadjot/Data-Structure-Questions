#include<iostream>
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

int diameter(node *tree,int *height){

    int lh=0,rh=0;

    int ldiameter = 0,rdiameter = 0;

    if(tree==NULL){
        *height = 0;
        return 0;
    }

    ldiameter = diameter(tree->left,&lh);
    rdiameter = diameter(tree->right,&rh);

    *height = max(lh,rh)+1;

    return max(lh+rh+1, max(ldiameter,rdiameter));

}

int main(){

    struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);

  int height = 0;
  printf("Diameter of the given binary tree is %d\n", diameter(root,&height));

    return 0;
}