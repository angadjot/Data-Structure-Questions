/*input
15
10
5
20
3
2
-1
*/
#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

node *createNode(int val);
void insert(node **headRef,int val);
void MergeSort(node **headRef);
node* SortedMerge(node *a,node *b);
void FrontBackSplit(node *source,node **frontRef,node **backRef);
void traverse(node **headRef);

int main(){

    node *head = NULL;
    int value;

    while(true) {
        cout<<"Press -1 to exit insert"<<endl;
        cin>>value;
        if(value == -1) {
            break;
        }
        insert(&head,value);
    }
    cout<<"Linked List : ";
    traverse(&head);

    MergeSort(&head);

    cout<<"After SortedMerge : Linked List : ";
    traverse(&head);

    return 0;
}

void traverse(node **headRef){

    if(*headRef == NULL) {
        return ;
    }

    node *current = *headRef;
    while(current != NULL) {
        cout<<current->data<<" ";
        current = current->next;
    }
    cout<<endl;

}


node *createNode(int val){

    node *temp = new node;
    temp->data = val;
    temp->next = NULL;

    return temp;
}

void insert(node **headRef,int val){

    if(*headRef == NULL){
        *headRef = createNode(val);
        return;
    }

    node *temp = createNode(val);
    temp->next = *headRef;
    *headRef = temp;

}

void MergeSort(node **headRef){

    node *head = *headRef;
    node *a;
    node *b;

    if(head == NULL || head->next == NULL)
        return ;

    FrontBackSplit(head,&a,&b);

    MergeSort(&a);
    MergeSort(&b);

    *headRef = SortedMerge(a,b);

}

node* SortedMerge(node *a,node *b){

    node *result = NULL;

    if(a == NULL)
        return b;

    if(b == NULL)
        return a;

    if(a->data <= b->data) {
        result = a;
        result->next = SortedMerge(a->next,b);
    }
    else{
        result = b;
        result->next = SortedMerge(a,b->next);
    }

    return result;
}

void FrontBackSplit(node *source,node **frontRef,node **backRef){

    node *fast;
    node *slow;

    if(source == NULL || source->next == NULL){
        *frontRef = source;
        *backRef = NULL;
    }
    else{

        slow = source;
        fast = slow->next;

        while(fast != NULL) {
            fast = fast->next;

            if(fast != NULL) {
                fast = fast->next;
                slow = slow->next;
            }
        }

        *frontRef = source;
        *backRef = slow->next;
        slow->next = NULL;
    }

}