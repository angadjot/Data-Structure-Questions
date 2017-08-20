#include <iostream>
using namespace std;

struct node{
    int data;
    node *left,*right;
};

node* newNode(int val);
node* minNode(node *tree);
node* insert(node *tree,int val);
node* deleteNode(node *tree,int val);
void inorder(node *tree);

int main(){
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder traversal of the given tree \n");
    inorder(root);

    printf("\nDelete 20\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    printf("\nDelete 30\n");
    root = deleteNode(root, 30);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    printf("\nDelete 50\n");
    root = deleteNode(root, 50);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    return 0;
}

node* newNode(int val){

    node *temp = new node;
    temp->data = val;
    temp->left = temp->right = NULL;

    return temp;
}

node* minNode(node *tree){

    if(tree == NULL)
        return 0;

    if(tree->left == NULL)
        return tree;

    return minNode(tree->left);
}

node* insert(node *tree,int val){

    if(tree == NULL)
        return newNode(val);

    if(tree->data > val)
        tree->left = insert(tree->left,val);

    if(tree->data < val)
        tree->right = insert(tree->right,val);

    return tree;
}

node* deleteNode(node *tree,int val){

    if(tree == NULL)
        return tree;

    if(tree->data > val)
        tree->left = deleteNode(tree->left,val);

    else if(tree->data < val )
        tree->right = deleteNode(tree->right,val);
    else{

        if(tree->left == NULL){
            node *temp = tree->right;
            free(tree);
            return temp;
        }

        else if(tree->right == NULL){
            node *temp = tree->left;
            free(tree);
            return temp;
        }


        node *temp = minNode(tree->right);
        tree->data = temp->data;
        tree->right = deleteNode(tree->right,temp->data);

    }

    return tree;
}

void inorder(node *tree){

    if(tree == NULL)
        return ;

    inorder(tree->left);
    cout<<tree->data<<" ";
    inorder(tree->right);
}