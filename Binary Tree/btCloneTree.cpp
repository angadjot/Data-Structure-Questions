#include <iostream>
#include <map>
#include <queue>
using namespace std;

struct node{
    int data;
    node *left,*right;
    node *random;
};

node *newNode(int val){

    node *temp = new node;
    temp->data = val;
    temp->random = temp->left = temp->right = NULL;

    return temp;

}

node* copyLeftRightNode(node *tree,map<node*, node*> *map){

    if(tree == NULL)
        return NULL;

    node *cloneNode = newNode(tree->data);
    (*map)[tree] = cloneNode;
    cloneNode->left = copyLeftRightNode(tree->left,map);
    cloneNode->right = copyLeftRightNode(tree->right,map);
    return cloneNode;
}

void copyRandom(node *tree,node *cloneNode,map<node*,node*> *map){

    if(cloneNode == NULL)
        return ;

    cloneNode->random = (*map)[tree->random];
    copyRandom(tree->left,cloneNode->left,map);
    copyRandom(tree->right,cloneNode->right,map);
}

node* cloneTree(node *tree){

    if(tree == NULL)
        return NULL;

    map<node*,node*> *mymap = new map<node*,node*>;
    node *newTree = copyLeftRightNode(tree,mymap);
    copyRandom(tree,newTree,mymap);
    return newTree;
}

void printInorder(node* node)
{
    if (node == NULL)
        return;

    /* First recur on left sutree */
    printInorder(node->left);

    /* then print data of Node and its random */
    cout << "[" << node->data << " ";
    if (node->random == NULL)
        cout << "NULL], ";
    else
        cout << node->random->data << "], ";

    /* now recur on right subtree */
    printInorder(node->right);
}

int main()
{
    //Test No 1
    node *tree = newNode(1);
    tree->left = newNode(2);
    tree->right = newNode(3);
    tree->left->left = newNode(4);
    tree->left->right = newNode(5);
    tree->random = tree->left->right;
    tree->left->left->random = tree;
    tree->left->right->random = tree->right;

    //  Test No 2
    //    tree = NULL;

    //  Test No 3
    //    tree = newNode(1);

    //  Test No 4
    /*    tree = newNode(1);
        tree->left = newNode(2);
        tree->right = newNode(3);
        tree->random = tree->right;
        tree->left->random = tree;
    */

    cout << "Inorder traversal of original binary tree is: \n";
    printInorder(tree);

    node *clone = cloneTree(tree);

    cout << "\n\nInorder traversal of cloned binary tree is: \n";
    printInorder(clone);

    return 0;
}