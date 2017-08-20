#include <iostream>
#include <map>
using namespace std;

struct node{
    int data;
    node *next;
    node *random;
};

node *newNode(int val);
void insert(node **headRef,int val);
node* LLclone(node *headRef);
void traverse(node *head);

int main(){

    node *head = NULL, *result = NULL;

    insert(&head, 4);
    insert(&head, 3);
    insert(&head, 2);
    insert(&head, 1);
    cout<<"Linked : ";
    traverse(head);

    head->random = head->next->next;
    head->next->random =head->next->next->next;
    head->next->next->random =head->next->next->next->next;
    head->next->next->next->random =head->next->next->next->next->next;
    head->next->next->next->next->random = head->next;

    result = LLclone(head);
    cout<<"Clone : ";
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

node* LLclone(node *headRef){

    node *origCurr = headRef, *cloneCurr = NULL;
    std::map<node*, node*> map;

    while(origCurr != NULL){
        cloneCurr = new node;
        cloneCurr->data = origCurr->data;
        cloneCurr->next = origCurr->next;
        map[origCurr] = cloneCurr;
        origCurr = origCurr->next;
        cloneCurr = cloneCurr->next;
    }

    origCurr = headRef;

    while(origCurr!=NULL) {
        cloneCurr->random = map[origCurr->random];
        origCurr = origCurr->next;
    }

    return map[headRef];

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