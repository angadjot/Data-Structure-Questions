#include <iostream>
using namespace std;

struct node{
    int data;
    node *left,*right;
};

node *treeToDLLUtil(node* root,node* &rightEnd){

    if(root == NULL)
        return NULL;

    root->right = treeToDLLUtil(root->right,rightEnd);

    if(root->right == NULL)
        rightEnd = root;
    else
        root->right->left = root;

    node *left = root;

    if(root->left){
        node *leftEnd;
        left = treeToDLLUtil(root->left,leftEnd);
        leftEnd->right = root;
        root->left = leftEnd;
    }

    return left;
}

node *treeToDLL(node *root){

    node *rightEnd = NULL;
    return treeToDLLUtil(root,rightEnd);

}

node *newNode(int val){

    node *temp = new node;
    temp->data = val;
    temp->left = temp->right = NULL;

    return temp;
}

void inorder(node *root){

    if(root == NULL)
        return ;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}

void printList(node *root){

    while(root!=NULL){
        cout<<root->data<<" ";
        root = root->right;
    }
}

int main(void)
{
    // Let us create the tree shown in above diagram
    struct node *root = newNode(10);
    root->left        = newNode(12);
    root->right       = newNode(15);
    root->left->left  = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);

    cout<<"\n\t\tInorder Tree Traversal\n\n";
    inorder(root);

    struct node *head = treeToDLL(root);

    cout<<"\n\n\t\tDLL Traversal\n\n";
    printList(head);
    return 0;
}