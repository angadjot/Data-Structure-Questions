#include <iostream>
#include <map>
#include <queue>
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

void bottomView(node *root){

    if(root == NULL)
        return;

    map<int,int> m;

    queue< pair<node*,int> > Q;
    Q.push( make_pair(root,0) );

    while(!Q.empty()){

        pair<node*,int> t = Q.front();
        node *temp = t.first;
        int level = t.second;
        Q.pop();

        m[level] = temp->data;

        if(temp->left)
            Q.push( make_pair(temp->left,level-1) );

        if(temp->right)
            Q.push( make_pair(temp->right,level+1) );

    }

    map<int,int>::iterator it;
    for(it=m.begin();it!=m.end();it++){
        cout<<it->second<<" ";
    }
}

int main()
{
    node *root = newNode(20);
    root->left = newNode(8);
    root->right =newNode(22);
    root->left->left = newNode(5);
    root->left->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(25);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    cout << "Bottom view of the given binary tree :\n";
    bottomView(root);
    return 0;
}