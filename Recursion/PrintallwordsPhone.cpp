//print all possible words from phone digits
#include<iostream>
using namespace std;

const char hashtable[10][5] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void printWordAux(int number[],char output[],int curr_digit,int n){

    if(curr_digit == n){
        cout<<output<<" ";
        return;
    }

    for(int i=0;i<strlen(hashtable[number[curr_digit]]);i++){
        output[curr_digit] = hashtable[number[curr_digit]][i];
        printWordAux(number,output,curr_digit+1,n);
        if(number[curr_digit] == 0 || number[curr_digit] == 1)
            return ;
    }

}

void printWord(int number[],int n){

    char result[n+1];
    result[n] = '\0';
    printWordAux(number,result,0,n);
}

int main(){

    int number[] = {2,4,0};
    int n = sizeof(number)/sizeof(int);
    printWord(number,n);
    return 0;
}