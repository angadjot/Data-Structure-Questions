//Given an array arr[], find the maximum j – i such that arr[j] > arr[i]
#include <iostream>
using namespace std;

int maxIndexDiff(int arr[],int n){

    int LMin[n], RMax[n];

    LMin[0]=arr[0];
    for(int i=1;i<n;i++)
        LMin[i] = min(arr[i],LMin[i-1]);

    RMax[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--)
        RMax[i] = max(arr[i],RMax[i+1]);

    int i=0,j=0,maxDiff = -1;

    while(i < n && j < n){
        if(LMin[i] < RMax[j]){
            maxDiff = max(maxDiff,j-i);
            j++;
        }
        else
            i++;
    }

    return maxDiff;

}

int main()
{
    int arr[] = {9, 2, 3, 4, 5, 6, 7, 8, 18, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    int maxDiff = maxIndexDiff(arr, n);
    printf("%d\n", maxDiff);
    return 0;
}