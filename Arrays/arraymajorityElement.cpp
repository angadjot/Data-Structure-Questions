#include <iostream>
#include <map>
using namespace std;

bool printMajority(int a[],int size){

    map<int,int> m1;

    for(int i=0;i<size;i++){
        if(m1[a[i]] == 0)
            m1[a[i]] = 1;
        else
            m1[a[i]]++;
    }

    for(map<int,int>::iterator it = m1.begin(); it != m1.end(); it++){
        if(it->second > size/2){
            cout<<it->first<<endl;
            return true;
        }
    }

    return false;
}


int main(){

    int a[] = {1, 3, 3, 1, 2};
    int size = (sizeof(a))/sizeof(a[0]);
    if(!printMajority(a, size))
        cout<<"No Majority Element"<<endl;
    return 0;
}