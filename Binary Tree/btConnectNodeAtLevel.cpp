#include <iostream>
using namespace std;

struct node{
    int data;
    node *left,*right;
    node *nextRight;
};

node *newNode(int val){

    node *temp = new node;
    temp->data = val;
    temp->left = temp->right = NULL;

    return temp;
}

node *getNextRight(node *root){

    root = root->nextRight;

    while(root != NULL){
        if(root->left)
            return root->left;
        if(root->right)
            return root->right;

        root=root->nextRight;
    }

    return NULL;
}

void ConnectRight(node *root){

    if(root == NULL)
        return;

    root->nextRight = NULL;

    node *firstAtlevel = root;

    while(firstAtlevel){
        node *iter = firstAtlevel;

        while(iter) {
            if(iter->left){
                if(iter->right){
                    iter->left->nextRight = iter->right;
                    iter->right->nextRight = getNextRight(iter);
                }
                else
                    iter->left->nextRight = getNextRight(iter);
            }
            else if(iter->right){
                iter->right->nextRight = getNextRight(iter);
            }

            iter = iter->nextRight;
        }

        if(firstAtlevel->left)
            firstAtlevel = firstAtlevel->left;
        else if(firstAtlevel->right)
            firstAtlevel = firstAtlevel->right;
        else
            firstAtlevel = getNextRight(firstAtlevel);
    }
}

int main()
{

    /* Constructed binary tree is
              10
            /   \
          8      2
        /         \
      3            90
    */
    struct node *root = newNode(10);
    root->left        = newNode(8);
    root->right       = newNode(2);
    root->left->left  = newNode(3);
    root->right->right      = newNode(90);

    // Populates nextRight pointer in all nodes
    ConnectRight(root);

    // Let us check the values of nextRight pointers
    printf("Following are populated nextRight pointers in the tree "
           "(-1 is printed if there is no nextRight) \n");
    printf("nextRight of %d is %d \n", root->data,
           root->nextRight? root->nextRight->data: -1);
    printf("nextRight of %d is %d \n", root->left->data,
           root->left->nextRight? root->left->nextRight->data: -1);
    printf("nextRight of %d is %d \n", root->right->data,
           root->right->nextRight? root->right->nextRight->data: -1);
    printf("nextRight of %d is %d \n", root->left->left->data,
           root->left->left->nextRight? root->left->left->nextRight->data: -1);
    printf("nextRight of %d is %d \n", root->right->right->data,
           root->right->right->nextRight? root->right->right->nextRight->data: -1);

    return 0;
}