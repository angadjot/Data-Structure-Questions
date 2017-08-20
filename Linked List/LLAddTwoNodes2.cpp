#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

node *newNode(int val);
void insert(node **headRef,int val);
int getSize(node *head);
void addList(node *first,node *second,node **result);
node *addSameSize(node *first,node *second,int *carry);
void addRemaining(node *first,node *curr,int *carry,node **result);
void swapPointers(node **first,node **second);
void traverse(node *head);

int main(){

    node *first = NULL, *second = NULL, *result = NULL;

    insert(&first,9);
    insert(&first,9);
    insert(&first,9);
    cout<<"First List : ";
    traverse(first);

    insert(&second,8);
    insert(&second,1);
    cout<<"Second List : ";
    traverse(second);

    addList(first,second,&result);
    cout<<"Sum List : ";
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

    if(*headRef == NULL){
        *headRef = newNode(val);
        return;
    }

    node *ptr = newNode(val);
    ptr->next = (*headRef);
    (*headRef) = ptr;

}

int getSize(node *head){

    if(head == NULL)
        return 0;

    return 1 + getSize(head->next);

}

void addList(node *first,node *second,node **result){

    if(first == NULL){
        (*result) = second;
        return ;
    }

    if(second == NULL){
        (*result) = first;
        return ;
    }

    int size1 = getSize(first);
    int size2 = getSize(second);

    int carry = 0;

    if(size1 == size2)
        *result = addSameSize(first,second,&carry);

    else{

        int diff = abs(size1-size2);

        if(size1<size2){
            swapPointers(&first,&second);
        }

        node *curr = NULL;

        for(curr = first;diff--;curr=curr->next);

        *result = addSameSize(curr,second,&carry);


        addRemaining(first,curr,&carry,result);

    }

    if(carry)
        insert(result,carry);


}

node *addSameSize(node *first,node *second,int *carry){

    if(first == NULL)
        return NULL;

    int sum = 0;

    node *result = new node;
    result->next = addSameSize(first->next,second->next,carry);
    sum = *carry + first->data + second->data;

    *carry = sum/10;
    sum = sum%10;

    result->data = sum;

    return result;

}

void addRemaining(node *first,node *curr,int *carry,node **result){

    int sum;

    if(first != curr){

        addRemaining(first->next,curr,carry,result);

        sum = *carry + first->data;

        *carry = sum/10;
        sum = sum%10;

        insert(result,sum);

    }
}

void swapPointers(node **first,node **second){

    node *temp = *first;
    *first = *second;
    *second = temp;

}

void traverse(node *head){

    if(head == NULL)
        return ;

    node *ptr = head;

    while(ptr != NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }

    cout<<endl;

}