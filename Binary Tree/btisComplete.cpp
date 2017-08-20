#include <iostream>
#include <queue>
using namespace std;

struct node{
    int data;
    node *left,*right;
};

node* newNode(int val){

    node *temp = new node;
    temp->data = val;
    temp->left = temp->right = NULL;

    return temp;
}

bool isCompleteBT(node *root){

    if(root == NULL)
        return true;

    queue<node *> q;
    q.push(root);

    bool flag = false;

    while(!q.empty()){

        node *temp = q.front();
        q.pop();

        if(temp->left){

            if(flag == true)
                return false;

            q.push(temp->left);
        }
        else
            flag = true;

        if(temp->right){
            if(flag == true)
                return false;
            q.push(temp->right);
        }
        else
            flag = true;

    }

    return true;

}

int main()
{
   /* Let us construct the following Binary Tree which
      is not a complete Binary Tree
            1
          /   \
         2     3
        / \     \
       4   5     6
    */

  struct node *root  = newNode(1);
  root->left         = newNode(2);
  root->right        = newNode(3);
  root->left->left   = newNode(4);
  root->left->right  = newNode(5);
  root->right->right = newNode(6);

  if ( isCompleteBT(root) == true )
      printf ("Complete Binary Tree");
  else
      printf ("NOT Complete Binary Tree");

  return 0;
}