#include <iostream>
using namespace std;

struct node{
    int data;
    node *left,*right;
};

void getTargetLeaf(node *root,int *max_sum_ref,int curr_sum,node **target_ref){

    if(root == NULL)
        return ;

    curr_sum += root->data;

    if(root->left == NULL && root->right == NULL)
        if(curr_sum > *max_sum_ref){
            *max_sum_ref = curr_sum;
            *target_ref = root;
            return ;
        }

    getTargetLeaf(root->left,max_sum_ref,curr_sum,target_ref);
    getTargetLeaf(root->right,max_sum_ref,curr_sum,target_ref);

}

bool printPath(node *root,node *target_leaf){

    if(root == NULL)
        return false;

    if(root == target_leaf || printPath(root->left,target_leaf) || printPath(root->right,target_leaf)){
        cout<<root->data<<" ";
        return true;
    }

    return false;


}

int maxSumPath(node *root){

    if(root == NULL)
        return 0;

    int max_sum = INT_MIN;

    node *target_leaf;

    getTargetLeaf(root,&max_sum,0,&target_leaf);

    printPath(root,target_leaf);

    return max_sum;

}

node* newNode(int val){

    node *temp = new node;
    temp->data = val;
    temp->left = temp->right = NULL;

    return temp;
}

int main()
{
    struct node *root = NULL;

    /* Constructing tree given in the above figure */
    root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(7);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);

    printf ("Following are the nodes on the maximum "
            "sum path \n");
    int sum = maxSumPath(root);
    printf ("\nSum of the nodes is %d ", sum);

    return 0;
}