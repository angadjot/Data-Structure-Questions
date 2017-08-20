#include <iostream>
#include <map>
using namespace std;

typedef map< int, pair<int,int> > mymap;

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

void topViewAux(node *root,mymap &m,int level,int hd){

    if(root == NULL)
        return ;

    if(m.find(hd) == m.end() || level < m[hd].first){
        m[hd] = make_pair(level,root->data);
    }

    topViewAux(root->left,m,level+1,hd-1);
    topViewAux(root->right,m,level+1,hd+1);

}

void topView(node *root){

    mymap m;
    int level = 1;
    int hd = 0;
    topViewAux(root,m,level,hd);

    mymap::iterator it;
    for(it=m.begin(); it != m.end(); it++)
        cout<<(it->second).second<<" ";

}

int main()
{
    node *root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(5);
    root->left->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(25);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    cout << "Top view of the given binary tree :\n";
    topView(root);
    return 0;
}