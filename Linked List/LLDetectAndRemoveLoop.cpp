/*input
50
20
15
4
10
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
void detectAndRemoveLoop(node *head_ref);
void makeLoop(node *head_ref);

int main(){

    node *head = createNode(50);
    head->next = createNode(20);
    head->next->next = createNode(15);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(10);

    cout<<"Linked List : ";
    traverse(&head);
    head->next->next->next->next->next = head->next->next;
    detectAndRemoveLoop(head);
    cout<<"After Removing Loop Linked List : ";
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

void detectAndRemoveLoop(node *head_ref){

    node *slow = head_ref;
    node *fast = head_ref->next;

    while(fast && fast->next){
        if(slow == fast) {
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }

    if(slow == fast) {
        slow = head_ref;

        while(slow != fast->next){
            slow = slow->next;
            fast = fast->next;
        }

        fast->next = NULL;
    }

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

void makeLoop(node *head){

    head->next->next->next->next->next = head->next->next;
}