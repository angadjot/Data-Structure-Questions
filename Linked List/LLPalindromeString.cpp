#include <iostream>
#include <string>
using namespace std;

struct node{
    string data;
    node *next;
};

node* newNode(string str);
bool isPalindrome(node *head);
bool isPalindromeUtil(string str);
void traverse(node *head);


int main(){

    node *head = newNode("a");
    head->next = newNode("bc");
    head->next->next = newNode("d");
    head->next->next->next = newNode("dcb");
    head->next->next->next->next = newNode("a");

    isPalindrome(head)? printf("true\n"):printf("false\n");

    return 0;
}


node* newNode(string str){

    node *temp = new node;
    temp->data = str;
    temp->next = NULL;

    return temp;
}

bool isPalindrome(node *head){

    string str = "";

    node *ptr = head;
    while(ptr!=NULL){
        str.append(ptr->data);
        ptr=ptr->next;
    }

    return isPalindromeUtil(str);

}

bool isPalindromeUtil(string str){

    int length = str.length();
    for(int i = 0; i < length; ++i) {
        if(str[i] != str[length-i-1]){
            return false;
        }
    }

    return true;
}

void traverse(node *head){

    node *ptr = head;
    while(ptr!=NULL) {
        cout<<ptr->data;
        ptr = ptr->next;
    }
    cout<<endl;
}