#include <iostream>
#include <queue>
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

void printLevelOrder(node *tree){

    queue<node *> q;

    q.push(tree);

    while(1){

        int nodeCount = q.size();
        if(nodeCount == 0)
            break;

        while(nodeCount > 0){

            node *temp = q.front();
            cout<<temp->data<<" ";
            q.pop();

            if(temp->left != NULL)
                q.push(temp->left);

            if(temp->right != NULL)
                q.push(temp->right);
            nodeCount--;
        }
        cout<<endl;
    }
}

int main()
{

    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    printLevelOrder(root);
    return 0;
}