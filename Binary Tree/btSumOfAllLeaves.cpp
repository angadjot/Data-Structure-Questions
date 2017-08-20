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

void leftLeavesSumRec(node *root,bool isLeft,int *sum){

    if(root == NULL)
        return ;

    if(root->left == NULL && root->right == NULL && isLeft)
        *sum += root->data;

    leftLeavesSumRec(root->left,1,sum);
    leftLeavesSumRec(root->right,0,sum);
}

int leftLeavesSum(node *root){

    int sum = 0;
    leftLeavesSumRec(root,0,&sum);
    return sum;
}


int main()
{
    // Let us construct the Binary Tree shown in the
    // above figure
    int sum = 0;
    struct node *root         = newNode(20);
    root->left                = newNode(9);
    root->right               = newNode(49);
    root->right->left         = newNode(23);
    root->right->right        = newNode(52);
    root->right->right->left  = newNode(50);
    root->left->left          = newNode(5);
    root->left->right         = newNode(12);
    root->left->right->right  = newNode(12);

    cout << "Sum of left leaves is " << leftLeavesSum(root) << endl;
    return 0;
}