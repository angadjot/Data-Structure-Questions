//Find subarray with given sum | Set 1 (Nonnegative Numbers)
#include <iostream>
using namespace std;

void subArraySum(int arr[],int n,int sum){

    int curr_sum = arr[0];
    int start = 0;

    for(int i=1;i<n;i++){

        while(curr_sum > sum && start < i-1){
            curr_sum -= arr[start];
            start++;
        }

        if(curr_sum == sum){
            cout<<"Sum found between indexes "<<start<<","<<i-1<<endl;
            return ;
        }

        if(i<n)
            curr_sum += arr[i];

    }

    cout<<"No Sub Array Found"<<endl;
    return ;
}

int main()
{
    int arr[] = {15, 2, 4, 8, 9, 5, 10, 23};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 23;
    subArraySum(arr, n, sum);
    return 0;
}