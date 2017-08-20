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

void topView(node *root){

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

        if(m[level] == 0)
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
    /* Create following Binary Tree
             1
           /  \
          2    3
           \
            4
             \
              5
               \
                6*/

    node *root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->right=newNode(4);
    root->left->right->right=newNode(5);
    root->left->right->right->right=newNode(6);

    topView(root);
  return 0;
}