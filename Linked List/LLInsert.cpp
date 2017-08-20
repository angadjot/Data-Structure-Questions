/*input
1
1
1
2
1
3
1
4
1
5
4
5
*/
#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

node *createNewNode(int val);
void insertAtBegin(node **head_ref,int val);
void insertAtEnd(node **head_ref,int val);
void insertAtPos(node **head_ref,int pos,int val);
void traverse(node **head_ref);


int main(){

    node *head = NULL;
    int option,value,position;
    while(true){

        cout<<"1. Insert At Begin"<<endl;
        cout<<"2. Insert At End"<<endl;
        cout<<"3. Insert At Position"<<endl;
        cout<<"4. Display Linked List"<<endl;
        cout<<"5. Exit"<<endl;
        cin>>option;

        switch(option){
            case 1:
                cout<<"Enter the value"<<endl;
                cin>>value;
                insertAtBegin(&head,value);
                break;

            case 2:
                cout<<"Enter the value"<<endl;
                cin>>value;
                insertAtEnd(&head,value);
                break;

            case 3:
                cout<<"Enter the Position"<<endl;
                cin>>position;
                cout<<"Enter the value"<<endl;
                cin>>value;
                insertAtPos(&head,position,value);
                break;

            case 4:
                cout<<"Linked List : ";
                traverse(&head);
                break;

            case 5:
                return 0;

        }

    }
}

node* createNewNode(int val){

    node *temp = new node;
    temp->data = val;
    temp->next = NULL;

    return temp;

}

void insertAtBegin(node **head_ref,int val){

    if(*head_ref == NULL){
        *head_ref = createNewNode(val);
        return;
    }

    node *newNode =  createNewNode(val);
    newNode->next = *head_ref;
    *head_ref = newNode;

}

void insertAtEnd(node **head_ref,int val){

    if(*head_ref == NULL){
        *head_ref = createNewNode(val);
        return;
    }

    node *ptr = *head_ref;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }

    ptr->next = createNewNode(val);
}

void insertAtPos(node **head_ref,int pos,int val){

    if(*head_ref == NULL){
        *head_ref = createNewNode(val);
        return;
    }

    node *ptr = *head_ref;
    for (int i = 0; i < pos; ++i){
        ptr = ptr->next;
        if(ptr == NULL)
            return;
    }

    node *temp = createNewNode(val);

    temp = ptr->next;
    ptr = temp;

}

void traverse(node **head_ref){

    if (*head_ref==NULL){
        return;
    }

    node *ptr = *head_ref;
    while(ptr != NULL){
        cout<<ptr->data<<"\t";
        ptr = ptr->next;
    }

    cout<<endl;

}