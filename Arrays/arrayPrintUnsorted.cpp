//Find the Minimum length Unsorted Subarray, sorting which makes the complete array sorted
#include <iostream>
using namespace std;

void printUnsorted(int arr[],int n){

    int s=0,e=n-1,min,max;

    for(s=0;s<n;s++)
        if(arr[s] > arr[s+1])
            break;

    if(s == n-1){
        cout<<"The complete array is sorted"<<endl;
        return ;
    }

    for(e=n-1;e>=0;e--){
        if(arr[e] < arr[e-1])
            break;
    }

    max = arr[s];
    min = arr[s];

    for(int i=s;i<=e;i++){
        if(arr[i] > max)
            max = arr[i];

        if(arr[i] < min)
            min = arr[i];
    }

    for(int i=0;i<s;i++)
        if(arr[i] > min)
            s = i;

    for(int i=n-1;i>=e+1;i--){
        if(arr[i] < max)
            e = i;
    }

    cout<<"The unsorted subarray which makes the given array soreted lies between indicexs "<<s<<","<<e<<endl;

    return;

}

int main()
{
  int arr[] = {10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
  int arr_size = sizeof(arr)/sizeof(arr[0]);
  printUnsorted(arr, arr_size);
  return 0;
}