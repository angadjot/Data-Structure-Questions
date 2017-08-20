#include <iostream>
using namespace std;

int binarySearch(int arr[],int low,int high,int x){

    if(high >= low){
        int mid = (low + high)/2;

        if( ( (mid == 0) || x > arr[mid-1] ) && arr[mid] == x )
            return mid;
        else if(arr[mid] < x)
            return binarySearch(arr,mid+1,high,x);
        else
            return binarySearch(arr,low,mid-1,x);
    }

    return -1;

}

bool isMajority(int arr[],int n,int x){

    int i = binarySearch(arr,0,n-1,x);

    if(i == -1)
        return false;

    if( ( (i+n/2) <= (n-1) ) && arr[i+n/2] == x)
        return true;
    else
        return false;
}

int main()
{
    int arr[] = {1, 2, 3, 3, 3, 3, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 3;
    if (isMajority(arr, n, x))
        printf("%d appears more than %d times in arr[]",
               x, n/2);
    else
        printf("%d does not appear more than %d times in arr[]",
               x, n/2);
    return 0;
}