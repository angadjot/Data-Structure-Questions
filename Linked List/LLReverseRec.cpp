/*input
1
2
3
4
5
-1
*/

#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

node* createNode(int val);
void insert(node **head_ref,int val);
void traverse(node **head_ref);
void reverse(node **head_ref);

int main(){

    node *head = NULL;
    int val;

    while(true){
        cout<<"Press -1 to exit insertion"<<endl;
        cin>>val;
        if(val == -1)
            break;
        insert(&head,val);
    }

    cout<<"Linked List : ";
    traverse(&head);
    reverse(&head);
    cout<<"Linked List : ";
    traverse(&head);

    return 0;
}

node *createNode(int val){

    node *temp = new node;
    temp->data = val;
    temp->next = NULL;

    return temp;
}

void insert(node **head_ref,int val){

    if(*head_ref == NULL){
        *head_ref = createNode(val);
        return ;
    }

    node *temp = createNode(val);
    temp->next = *head_ref;
    *head_ref = temp;

}

void reverse(node **head_ref){

    node *first;
    node *rest;

    if(*head_ref == NULL)
        return;

    first = *head_ref;
    rest = first->next;

    if(rest == NULL)
        return ;

    reverse(&rest);

    first->next->next = first;
    first->next = NULL;

    *head_ref = rest;

}

void traverse(node **head_ref){

    if(*head_ref == NULL)
        return;

    node *ptr = *head_ref;

    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }

    cout<<endl;

}