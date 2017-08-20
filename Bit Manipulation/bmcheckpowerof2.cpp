//Determine if an integer is of power 2
#include <iostream>
using namespace std;

bool checkpower2(unsigned int v){

    return (v && !(v&(v-1)));
}

int main(){
    unsigned int n = 8;

    if(checkpower2(n))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    return 0;
}