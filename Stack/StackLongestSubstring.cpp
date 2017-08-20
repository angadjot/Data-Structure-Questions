#include <iostream>
#include <stack>
using namespace std;

int findMaxLen(string str){

    int n = str.length();
    stack<int> s;
    s.push(-1);

    int result = 0;

    for(int i=0;i<n;i++){

        if(str[i]=='(')
            s.push(i);
        else{

            s.pop();

            if(!s.empty())
                result = max(result,i-s.top());
            else
                s.push(i);
        }
    }

    return result;
}

int main(){

    string str = "((()()";
    cout << findMaxLen(str) << endl;

    str = "()(()))))";
    cout << findMaxLen(str) << endl ;

    return 0;
}

