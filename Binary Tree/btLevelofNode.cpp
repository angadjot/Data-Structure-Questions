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

int getLevelUtil(node *tree,int key,int level){

  if(tree == NULL)
    return 0;

  if(tree->data == key)
    return level;

  int downLevel = getLevelUtil(tree->left,key,level+1);

  if(downLevel != 0)
    return downLevel;

  downLevel = getLevelUtil(tree->right,key,level+1);

  return downLevel;

}

int getLevel(node *tree,int data){
  return getLevelUtil(tree,data,1);
}

int main()
{
    struct node *root = new struct node;
    int x;

    /* Constructing tree given in the above figure */
    root = newNode(3);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(1);
    root->left->right = newNode(4);

    for (x = 1; x <=5; x++)
    {
      int level = getLevel(root, x);
      if (level)
        printf(" Level of %d is %d\n", x, level);
      else
        printf(" %d is not present in tree \n", x);

    }

    return 0;
}