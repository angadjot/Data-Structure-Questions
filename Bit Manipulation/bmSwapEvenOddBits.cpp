//Bit Manipulation
//swap even and odd bits of an integer
#include <iostream>
using namespace std;

int swapbits(int x){

    unsigned int even_bits = x & 0xAAAAAAAA;

    // Get all odd bits of x
    unsigned int odd_bits  = x & 0x55555555;

    even_bits >>= 1;  // Right shift even bits
    odd_bits <<= 1;   // Left shift odd bits

    return (even_bits | odd_bits); // Combine even and odd bits

}

int main(){

    unsigned int n;
    cout<<"Enter the integer to swap bits"<<endl;
    //cin>>n;
    n = 10;
    cout<<swapbits(n)<<endl;
    return 0;

}