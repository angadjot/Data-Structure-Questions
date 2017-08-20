#include <iostream>
#include <vector>
#include <map>
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

void diagonalSumUtil(node *root,int d,map<int,int> &diaSum){

    if(root == NULL)
        return ;

    diaSum[d] += root->data;

    diagonalSumUtil(root->left,d+1,diaSum);
    diagonalSumUtil(root->right,d,diaSum);
}

void diagonalSum(node *root){

    map<int,int> diaSum;
    diagonalSumUtil(root,0,diaSum);

    cout<<"Diagonal Sum of Binary Tree : "<<endl;

    map<int,int>::iterator it;

    for(it = diaSum.begin(); it != diaSum.end(); it++){
        cout<<it->second<<" ";
    }
    cout<<endl;


}

int main()
{
    /* node* root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);
    */
      node* root = newNode(1);
        root->left = newNode(2);
        root->right = newNode(3);
        root->left->left = newNode(9);
        root->left->right = newNode(6);
        root->right->left = newNode(4);
        root->right->right = newNode(5);
        root->right->left->right = newNode(7);
        root->right->left->left = newNode(12);
        root->left->right->left = newNode(11);
        root->left->left->right = newNode(10);

    diagonalSum(root);

    return 0;
}