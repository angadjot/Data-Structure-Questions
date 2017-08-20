#include <iostream>
#include <map>
using namespace std;

void printPairs(int arr[], int size,int sum){

    map<int,int> m1;
    int temp;

    for(int i=0;i<size;i++){
        temp = sum - arr[i];

        if(temp >= 0 && m1[temp] == 1)
            cout<<"Pair with given sum "<<sum<<" is ("<<arr[i]<<","<<temp<<")"<<endl;

        m1[arr[i]] = 1;
    }

}

int main(){

    int A[] = {1, 4, 45, 6, 10, 8};
    int n = 16;
    int arr_size = sizeof(A)/sizeof(A[0]);

    printPairs(A, arr_size, n);

    return 0;
}