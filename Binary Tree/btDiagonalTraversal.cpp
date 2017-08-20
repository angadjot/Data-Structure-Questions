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

void diagonalPrintUtil(node *root,int d,map<int, vector<int> > &diaPrint){

    if(root == NULL)
        return ;

    diaPrint[d].push_back(root->data);

    diagonalPrintUtil(root->left,d+1,diaPrint);
    diagonalPrintUtil(root->right,d,diaPrint);
}

void diagonalPrint(node *root){

    map<int, vector<int> > diaPrint;
    diagonalPrintUtil(root,0,diaPrint);

    cout<<"Diagonal Traversal of Binary Tree : "<<endl;

    map<int, vector<int> >::iterator it;
    vector<int>::iterator itr;

    for(it = diaPrint.begin(); it != diaPrint.end(); it++){
        for(itr = it->second.begin(); itr != it->second.end(); itr++){
            cout<<*itr<<" ";
        }
        cout<<endl;
    }


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

    diagonalPrint(root);

    return 0;
}