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

//dist(n1,n2) = dist(root,n1) + dist(root,n2) - 2*dist(root,lca)

int findLevel(node *root,int k,int level){

    if(root == NULL)
        return 0;

    if(root->data == k)
        return level;

    int l = findLevel(root->right,k,level+1);

    return (l != -1) ? l : findLevel(root->right,k,level+1);
}

void printKDistanceFromLeafUtil(node *root,int path[],bool visited[],int pathLen,int k){

    if(root == NULL)
        return;

    path[pathLen] = root->data;
    visited[pathLen] = false;
    pathLen++;

    if(root->left == NULL && root->right == NULL && pathLen-k-1 >= 0 && visited[pathLen-k-1] == false) {
        cout<<path[pathLen-k-1]<<" ";
        visited[pathLen-k-1] = true;
        return ;
    }

    printKDistanceFromLeafUtil(root->left,path,visited,pathLen,k);
    printKDistanceFromLeafUtil(root->right,path,visited,pathLen,k);
}

void printKDistanceFromLeaf(node *root,int k){

    int path[100];
    bool visited[100] = {false};
    printKDistanceFromLeafUtil(root,path,visited,0/*pathLen*/,k);
}

int main()
{
    // Let us create binary tree given in the above example
    node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);

    cout << "Nodes at distance 2 are: ";
    printKDistanceFromLeaf(root, 2);

    return 0;
}