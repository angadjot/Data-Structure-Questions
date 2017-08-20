#include <iostream>
using namespace std;

struct node{
  int data;
  node *next;
};

node* newNode(int val);
void insert(node **headRef, int val);
node *addTwoNodes(node *first,node *second);
void traverse(node *head);

int main(){

    node *first = NULL, *second = NULL, *result= NULL;

    insert(&first,6);
    insert(&first,4);
    insert(&first,9);
    insert(&first,5);
    insert(&first,7);
    cout<<"First Linked List : ";
    traverse(first);

    insert(&second,4);
    insert(&second,8);
    cout<<"Second Linked List : ";
    traverse(second);

    result = addTwoNodes(first,second);
    cout<<"Sum List : ";
    traverse(result);

    return 0;
}


node* newNode(int val){

    node *temp = new node;
    temp->data = val;
    temp->next = NULL;

    return temp;
}

void insert(node **headRef, int val){

    if(*headRef == NULL){
        *headRef = newNode(val);
        return ;
    }

    node *current = newNode(val);
    current->next = (*headRef);
    (*headRef) = current;

}

node *addTwoNodes(node *first,node *second){

    node *result = NULL;
    node *temp, *prev = NULL;

    int carry = 0, sum;

    while(first != NULL || second != NULL){

        sum = carry + (first ? first->data : 0) + (second ? second->data : 0);

        carry = ( sum >= 10 ? 1 : 0);

        sum = sum%10;

        temp = newNode(sum);

        if(result == NULL)
            result = temp;
        else
            prev->next = temp;

        prev = temp;

        if(first != NULL)
            first = first->next;

        if(second != NULL)
            second = second->next;

    }

    if(carry > 0)
        temp->next = newNode(carry);

    return result;

}

void traverse(node *head){

    if(head == NULL)
        return ;

    node *ptr = head;

    while(ptr!= NULL){
        cout<<ptr->data<<"->";
        ptr=ptr->next;
    }

    cout<<endl;

}