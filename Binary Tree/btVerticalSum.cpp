#include <iostream>
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

void VerSumAux(node *root,int level, std::map<int, int> &vsum){

  if(root == NULL)
    return;

  vsum[level] += root->data;

  VerSumAux(root->left,level-1,vsum);
  VerSumAux(root->right,level+1,vsum);

}

void VerSum(node *root){

  if(root == NULL)
    return;

  map<int,int> vsum;

  VerSumAux(root,0,vsum);

  map<int,int>::iterator it;
  for(it = vsum.begin();it != vsum.end();it++)
    cout<<it->second<<endl;

}

int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    VerSum(root);

    return 0;
}