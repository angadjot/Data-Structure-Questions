#include <iostream>
#include <stack>
using namespace std;

#define N 8

// Person with 2 is celebrity
bool  MATRIX[N][N] = {{0, 0, 1, 0},
                      {0, 0, 1, 0},
                      {0, 0, 0, 0},
                      {0, 0, 1, 0}};

bool know(int a, int b)
{
    return MATRIX[a][b];
}

int findCelebrity(int n){

    stack<int> s;

    for(int i=0;i<n;i++)
        s.push(i);

    int C;

    int A=s.top();
    s.pop();
    int B = s.top();
    s.pop();

    while(s.size()>1){
        if(know(A,B)){
            A=s.top();
            s.pop();
        }
        else{
            B=s.top();
            s.pop();
        }
    }

    C = s.top();
    s.pop();

    if(know(C,A))
        C=A;
    if(know(C,B))
        C=B;

    for(int i=0;i<n;i++)
        if( i!=C && (know(C,i) || !know(i,C)))
            return -1;

    return C;

}

int main()
{
    int n = 4;
    int id = findCelebrity(n);
    id == -1 ? cout << "No celebrity" :
               cout << "Celebrity ID " << id;
    return 0;
}