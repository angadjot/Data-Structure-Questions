#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

node *newNode(int val);
void insert(node **headRef,int val);
void findMaxSumList(node *a,node *b,node **result);
void traverse(node *head);

int main(){

    node *head1 = NULL, *head2 = NULL, *result = NULL;

    insert(&head1, 120);
    insert(&head1, 110);
    insert(&head1, 90);
    insert(&head1, 30);
    insert(&head1, 3);
    insert(&head1, 1);
    cout<<"List 1 : ";
    traverse(head1);

    insert(&head2, 130);
    insert(&head2, 120);
    insert(&head2, 100);
    insert(&head2, 90);
    insert(&head2, 32);
    insert(&head2, 12);
    insert(&head2, 3);
    insert(&head2, 0);
    cout<<"List 2 : ";
    traverse(head2);

    findMaxSumList(head1,head2,&result);

    cout<<"Max Sum List : ";
    traverse(result);

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

void findMaxSumList(node *a,node *b,node **result){

    node *pre1 = a, *curr1 = a;
    node *pre2 = b, *curr2 = b;

    while(curr1 != NULL && curr2 != NULL){

        int sum1 = 0, sum2 = 0;

        while(curr1 != NULL && curr2 != NULL && curr1->data != curr2->data){

            if(curr1->data < curr2->data){
                sum1 += curr1->data;
                curr1 = curr1->next;
            }
            else{
                sum2 += curr2->data;
                curr2 = curr2->next;
            }

        }

        if(curr1 == NULL){
            while(curr2 != NULL){
                sum2 += curr2->data;
                curr2 = curr2->next;
            }
        }

        if(curr2 == NULL){
            while(curr1 != NULL){
                sum1 += curr1->data;
                curr1 = curr1->next;
            }
        }

        if(pre1 == a && pre2 == b)
            (*result) = ( sum1 > sum2 ) ? pre1 : pre2;

        else{

            if(sum1>sum2){
                pre2->next = pre1->next;
            }
            else{
                pre1->next = pre2->next;
            }
        }

        pre1 = curr1;
        pre2 = curr2;

        if(curr1)
            curr1=curr1->next;

        if(curr2)
            curr2=curr2->next;
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