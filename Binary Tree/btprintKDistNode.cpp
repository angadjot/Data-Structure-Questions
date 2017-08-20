#include <iostream>
using namespace std;

struct node{
    int data;
    node *left,*right;
};

node *newnode(int val){

    node *temp = new node;
    temp->data = val;
    temp->left = temp->right = NULL;

    return temp;

}

int findLevel(node *root,int k,int level){

    if(root == NULL)
        return 0;

    if(root->data == k)
        return level;

    int l = findLevel(root->right,k,level+1);

    return (l != -1) ? l : findLevel(root->right,k,level+1);
}

void printKDistanceNodeDown(node *root,int k){

    if(root == NULL)
        return;

    if(k == 0){
        cout<<root->data<<endl;
        return ;
    }

    printKDistanceNodeDown(root->left,k-1);
    printKDistanceNodeDown(root->right,k-1);
}

int printKDistanceNode(node *root,node *target,int k){

    if(root == NULL)
        return -1;

    if(root == target){
        printKDistanceNodeDown(root,k);
        return 0;
    }

    int dl = printKDistanceNode(root->left,target,k);

    if(dl != -1){

        if(dl + 1 == k)
            cout<<root->data<<endl;
        else
            printKDistanceNodeDown(root->right,k-dl-2);

        return 1+dl;
    }

    int dr = printKDistanceNode(root->right,target,k);

    if(dr != -1){

        if(dr + 1 == k)
            cout<<root->data<<endl;
        else
            printKDistanceNodeDown(root->left,k-dr-2);

        return 1+dr;
    }

    return -1;
}

int main()
{
    /* Let us construct the tree shown in above diagram */
    node * root = newnode(20);
    root->left = newnode(8);
    root->right = newnode(22);
    root->left->left = newnode(4);
    root->left->right = newnode(12);
    root->left->right->left = newnode(10);
    root->left->right->right = newnode(14);
    node * target = root->left->right;
    printKDistanceNode(root, target, 2);
    return 0;
}