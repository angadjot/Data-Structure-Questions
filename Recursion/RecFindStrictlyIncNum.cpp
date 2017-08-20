#include <iostream>
using namespace std;

void findStrictlyIncreasingNum(int start, string out, int n){

    // If number becomes N-digit, print it
    if (n == 0)
    {
        cout << out << " ";
        return;
    }

    // start from (prev digit + 1) till 9
    for (int i = start; i <= 9; i++)
    {
        // append current digit to number
        string str = out + to_string(i);

        // recurse for next digit
        findStrictlyIncreasingNum(i + 1, str, n - 1);
    }
}

int main(){

    int n = 2;
    findStrictlyIncreasingNum(0,"",n);
    return 0;
}