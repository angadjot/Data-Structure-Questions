#include <iostream>
using namespace std;
#define MAX_SIZE 100

void printParanthesisAux(int pos,int n,int open,int close){

    static char str[MAX_SIZE];

    if(close == n){
        cout<<str<<endl;
        return ;
    }

    if(open > close){
        str[pos] = '}';
        printParanthesisAux(pos+1,n,open,close+1);
    }

    if(open < n){
        str[pos] = '{';
        printParanthesisAux(pos+1,n,open+1,close);
    }
}

void printParanthesis(int n){

    if(n>0)
        printParanthesisAux(0,n,0,0);

    return ;
}

int main(){

    int n = 3;
    printParanthesis(n);

    return 0;

}