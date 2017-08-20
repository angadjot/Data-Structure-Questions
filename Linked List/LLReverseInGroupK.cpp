/*input
9
8
7
6
5
4
3
2
1
-1
3
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
node* reverse(node *head_ref,int k);

int main(){

    node *head = NULL;
    int val;
    int k;

    while(true){
        cout<<"Press -1 to exit insertion"<<endl;
        cin>>val;
        if(val == -1)
            break;
        insert(&head,val);
    }
    cin>>k;

    cout<<"Linked List : ";
    traverse(&head);
    head = reverse(head,k);
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

node* reverse(node *head_ref,int k){

    node *current = head_ref;
    node *prev = NULL;
    node *next = NULL;
    int count = 0;

    while(current != NULL && count != k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    if(next != NULL) {
        (head_ref)->next = reverse(next,k);
    }

    return prev;

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