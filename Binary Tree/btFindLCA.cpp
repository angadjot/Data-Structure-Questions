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

bool find(node *root,int k){

    if(root == NULL)
        return false;

    if(root->data == k || find(root->left,k) || find(root->right,k))
        return true;

    return false;
}

node *findLCAUtil(node *root,int n1,int n2,bool &v1,bool &v2){

    if(root == NULL)
        return NULL;

    if(root->data == n1){
        v1 = true;
        return root;
    }

    if(root->data == n2){
        v2 = true;
        return root;
    }

    node *left_lca = findLCAUtil(root->left,n1,n2,v1,v2);
    node *right_lca = findLCAUtil(root->right,n1,n2,v1,v2);

    if(left_lca && right_lca)
        return root;

    return (left_lca != NULL) ? left_lca : right_lca;
}

node* findLCA(node *root,int n1,int n2){

    bool v1 = false, v2 = false;

    node *lca = findLCAUtil(root,n1,n2,v1,v2);

    if((v1 && v2) || (v1 && find(lca,n2)) || (v2 && find(lca,n1)))
        return lca;

    return NULL;
}

int main()
{
    // Let us create binary tree given in the above example
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    node *lca =  findLCA(root,4,5);
    if (lca != NULL)
       cout << "LCA(4, 5) = " << lca->data;
    else
       cout << "Keys are not present ";

    lca =  findLCA(root, 4, 10);
    if (lca != NULL)
       cout << "\nLCA(4, 10) = " << lca->data;
    else
       cout << "\nKeys are not present ";

    return 0;
}