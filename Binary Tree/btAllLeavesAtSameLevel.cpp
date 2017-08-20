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

bool checkUtil(node *root,int level, int *leafLevel){

    if(root == NULL)
        return true;

    if(root->left == NULL && root->right == NULL){
        if(*leafLevel == 0){
            *leafLevel = level;
            return true;
        }

        return (level == *leafLevel);
    }

    return checkUtil(root->left,level+1,leafLevel) && checkUtil(root->right,level+1,leafLevel);
}

bool check(node *root){
    int level = 0, leafLevel = 0;
    return checkUtil(root,level,&leafLevel);
}

int main()
{
    // Let us create tree shown in thirdt example
    struct node *root = newNode(12);
    root->left = newNode(5);
    root->left->left = newNode(3);
    root->left->right = newNode(9);
    root->left->left->left = newNode(1);
    root->left->right->left = newNode(1);
    if (check(root))
        printf("Leaves are at same level\n");
    else
        printf("Leaves are not at same level\n");
    return 0;
}


