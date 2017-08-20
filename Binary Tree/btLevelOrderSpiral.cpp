#include <iostream>
#include <stack>
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

void printSpiral(node *tree){

    stack<node *> s1;
    stack<node *> s2;

    s1.push(tree);

    while(!s1.empty() || !s2.empty()){

        while(!s1.empty()){

            node *temp = s1.top();
            s1.pop();
            cout<<temp->data<<" ";

            if(temp->right)
                s2.push(temp->right);
            if(temp->left)
                s2.push(temp->left);
        }

        while(!s2.empty()){

            node *temp = s2.top();
            s2.pop();
            cout<<temp->data<<" ";

            if(temp->left)
                s1.push(temp->left);
            if(temp->right)
                s1.push(temp->right);
        }
    }

}

int main()
{
    struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(7);
    root->left->right = newNode(6);
    root->right->left  = newNode(5);
    root->right->right = newNode(4);
    cout << "Spiral Order traversal of binary tree is \n";
    printSpiral(root);

    return 0;
}