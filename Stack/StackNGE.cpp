#include <iostream>
#include <stack>
using namespace std;

void printNGE(int arr[],int n);

int main(){

    int arr[] = {11, 13, 21, 3};
    int size = sizeof(arr)/sizeof(arr[0]);

    printNGE(arr,size);

    return 0;
}

void printNGE(int arr[],int n){

    stack<int> s;
    int next,element;

    s.push(arr[0]);

    for(int i=1;i<n;i++){
        next = arr[i];

        if(!s.empty()){

            element = s.top();

            while(next > element){
                cout<<element<<" ----> "<<next<<endl;
                s.pop();

                if(s.empty())
                    break;
            }
        }
        s.push(next);
    }

    while(!s.empty()){
        element = s.top();
        s.pop();
        cout<<element<<" ----> "<<-1<<endl;
    }
}