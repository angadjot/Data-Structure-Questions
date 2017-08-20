#include <iostream>
#include <queue>
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

int maxWidth(node *tree){

    if(tree == NULL)
        return 0;

    queue<node *> q;
    q.push(tree);

    int maxwidth = -1;

    while(!q.empty()){

        int count = q.size();

        maxwidth = max(count,maxwidth);

        while(count--){

            node *temp = q.front();
            q.pop();

            if(temp->left)
                q.push(temp->left);

            if(temp->right)
                q.push(temp->right);
        }

    }

    return maxwidth;

}

int main()
{
    struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(8);
    root->right->right->left  = newNode(6);
    root->right->right->right  = newNode(7);

    /*   Constructed Binary tree is:
                 1
               /   \
             2      3
           /  \      \
          4    5      8
                    /   \
                   6     7    */
    cout << "Maximum width is "
         << maxWidth(root) << endl;
    return 0;
}