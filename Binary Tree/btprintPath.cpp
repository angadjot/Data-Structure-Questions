#include <iostream>
using namespace std;

struct node{
    int data;
    node *left, *right;
};

node* newNode(int val){

    node *temp = new node;
    temp->data = val;
    temp->left = temp->right = NULL;

    return temp;

}

void printArray(int path[],int pathLen){

    for(int i=0;i<pathLen;i++){
        cout<<path[i]<<" ";
    }
    cout<<endl;
}

void printPathRecur(node *tree, int path[],int pathLen){

    if(tree == NULL)
        return;

    path[pathLen] = tree->data;
    pathLen++;

    if(tree->left == NULL && tree->right == NULL){
        printArray(path,pathLen);
    }
    else{
        printPathRecur(tree->left,path,pathLen);
        printPathRecur(tree->right,path,pathLen);
    }

}

void printPath(node *tree){
    int path[1000];
    printPathRecur(tree,path,0);
}

int main(){

  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);

  printPath(root);
  return 0;
}