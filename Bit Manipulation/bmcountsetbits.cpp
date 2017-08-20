//Counting Number of set bits
#include <iostream>
using namespace std;

int BitSetTable256[256];

void createTable(){

    for(int i=0;i<256;i++)
        BitSetTable256[i] = (i&1) + BitSetTable256[i/2];
}

int countBitSet(unsigned int n){

    unsigned int c = 0;

    unsigned char *p = (unsigned char *)&n;

    c = BitSetTable256[p[0]] + BitSetTable256[p[1]] + BitSetTable256[p[2]] + BitSetTable256[p[3]];

    return c;

}

int main(){

    unsigned int n = 10;

    createTable();
    cout<<countBitSet(n)<<endl;
    return 0;
}