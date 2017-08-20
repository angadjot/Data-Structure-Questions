#include <iostream>
using namespace std;

struct node{
    int data;
    node *next,*random;
};

node *newNode(int val){

    node *temp = new node;
    temp->data = val;
    temp->next = temp->random = NULL;

    return temp;
}

node *cloneRandom(node *start){

    node *curr = start, *temp;

    while(curr){
        temp = curr->next;
        curr->next = newNode(curr->data);
        curr->next->next = temp;
        curr = temp;
    }

    curr = start;

    while(curr){

        curr->next->random = curr->random->next;

        curr = curr->next ? curr->next->next : curr->next;
    }

    node *original = start, *copy = start->next;

    temp = copy;

    while(original && copy){

        original->next = (original->next) ? original->next->next : original->next;
        copy->next = (copy->next) ? copy->next->next : copy->next;

        original = original->next;
        copy = copy->next;
    }

    return temp;

}

void print(node *start)
{
    node *ptr = start;
    while (ptr)
    {
        cout << "Data = " << ptr->data << ", Random  = "
             << ptr->random->data << endl;
        ptr = ptr->next;
    }
}

int main()
{
    node* start = newNode(1);
    start->next = newNode(2);
    start->next->next = newNode(3);
    start->next->next->next = newNode(4);
    start->next->next->next->next = newNode(5);

    // 1's random points to 3
    start->random = start->next->next;

    // 2's random points to 1
    start->next->random = start;

    // 3's and 4's random points to 5
    start->next->next->random =
                    start->next->next->next->next;
    start->next->next->next->random =
                    start->next->next->next->next;

    // 5's random points to 2
    start->next->next->next->next->random =
                                      start->next;

    cout << "Original list : \n";
    print(start);

    cout << "\nCloned list : \n";
    node *cloned_list = cloneRandom(start);
    print(cloned_list);

    return 0;
}