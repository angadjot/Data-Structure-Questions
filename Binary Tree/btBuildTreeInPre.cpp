#include <iostream>
using namespace std;

struct node{
    char data;
    node *left,*right;
};

int search(char in[],int inStart,int inEnd,char key);

node *newNode(char val){

    node *temp = new node;
    temp->data = val;
    temp->left = temp->right = NULL;

    return temp;
}

node* buildTree(char in[], char pre[], int inStart, int inEnd){

    static int preIndex = 0;

    if(inStart > inEnd)
        return NULL;

    node *tnode = newNode(pre[preIndex++]);

    if(inStart == inEnd)
        return tnode;

    int inIndex = search(in,inStart,inEnd,tnode->data);

    tnode->left = buildTree(in,pre,inStart,inIndex-1);
    tnode->right = buildTree(in,pre,inIndex+1,inEnd);

    return tnode;

}

int search(char in[],int inStart,int inEnd,char key){

    for(int i=inStart;i<=inEnd;i++){
        if(in[i] == key){
            return i;
        }
    }

    return 0;
}

void inorder(node *tree){

    if(tree == NULL)
        return;

    inorder(tree->left);
    cout<<tree->data<<" ";
    inorder(tree->right);
}

int main()
{
  char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
  char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
  int len = sizeof(in)/sizeof(in[0]);
  struct node *root = buildTree(in, pre, 0, len - 1);

  /* Let us test the built tree by printing Insorder traversal */
  printf("Inorder traversal of the constructed tree is \n");
  inorder(root);

  return 0;
}