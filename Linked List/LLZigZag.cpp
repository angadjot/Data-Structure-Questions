#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

node *newNode(int val);
void insert(node **headRef,int val);
void ZigZag(node **headRef);
void traverse(node *head);

int main(){

    node *head = NULL;

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 6);
    insert(&head, 8);
    insert(&head, 7);
    insert(&head, 3);
    insert(&head, 4);
    cout<<"Linked List : ";
    traverse(head);

    ZigZag(&head);
    cout<<"Rearrange List : ";
    traverse(head);

    return 0;

}

node *newNode(int val){

    node *temp = new node;
    temp->data = val;
    temp->next = NULL;
    return temp;
}

void insert(node **headRef,int val){

    if((*headRef) == NULL){
        (*headRef) = newNode(val);
        return;
    }

    node *ptr = newNode(val);
    ptr->next = (*headRef);
    (*headRef) = ptr;

}

void ZigZag(node **headRef){

    node *current = *headRef;

    bool flag = true;

    while(current->next != NULL){

        if(flag) {
            if(current->data > current->next->data)
                swap(current->data,current->next->data);
        }
        else{
            if(current->data < current->next->data)
                swap(current->data,current->next->data);
        }

        current = current->next;
        flag =!flag;
    }

}

void traverse(node *head){

    if(head == NULL)
        return;

    node *ptr = head;
    while(ptr!= NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}