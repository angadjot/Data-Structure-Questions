#include <iostream>
using namespace std;

void printIncNumsAux(int *output,int i,int n){

    if(i==n){
        for(int j=0;j<n;j++)
            cout<<output[j];
        cout<<" ";
        return ;
    }

    for(int j = output[i-1] +1; j<10;j++){
        output[i] = j;
        printIncNumsAux(output,i+1,n);
    }

}

void printIncNums(int n){

    int output[n+1];
    output[0] = -1;
    printIncNumsAux(output+1,0,n);
}

int main(){

    int n = 3;
    printIncNums(n);

    return 0;

}