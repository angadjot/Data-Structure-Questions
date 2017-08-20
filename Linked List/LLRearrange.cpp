#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

node *newNode(int val);
void insert(node **headRef,int val);
void rearrange(node **headRef);
void reverseList(node **headRef);
void traverse(node *head);

int main(){

    node *head = NULL;

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);
    cout<<"Linked List : ";
    traverse(head);

    rearrange(&head);
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

void rearrange(node **headRef){

    node *slow = *headRef , *fast = slow->next;

    while(fast && fast->next){
        slow = slow->next;
        fast=fast->next->next;
    }

    node *head1 = (*headRef);
    node *head2 = slow->next;;
    slow->next = NULL;

    reverseList(&head2);

    (*headRef) = newNode(0);

    node *curr = *headRef;

    while(head1 || head2){

        if(head1){
            curr->next = head1;
            curr = curr->next;
            head1 = head1->next;
        }

        if(head2) {
            curr->next = head2;
            curr=curr->next;
            head2 = head2->next;
        }

    }

    (*headRef)=(*headRef)->next;

}

void reverseList(node **headRef){

    node *curr = *headRef;
    node *prev = NULL;
    node *next = NULL;

    while(curr!=NULL) {
        next = curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }

    (*headRef) = prev;
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