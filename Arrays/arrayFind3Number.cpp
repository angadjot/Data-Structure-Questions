//Find a sorted subsequence of size 3 in linear time
#include <iostream>
using namespace std;

void find3Numbers(int arr[],int n){

    int max = n-1;
    int min = 0;

    int smaller[n],greater[n];
    smaller[0] = -1;
    for(int i=1;i<n;i++){

        if(arr[i] <= arr[min]){
            min = i;
            smaller[i] = -1;
        }
        else
            smaller[i] = min;
    }

    greater[n-1] = -1;
    for(int i=n-2;i>=0;i--){
        if(arr[i] >= arr[max]){
            max = i;
            greater[i] = -1;
        }
        else
            greater[i] = max;
    }

    for(int i=0;i<n;i++){
        if(smaller[i] != -1 && greater[i] != -1){
            cout<<arr[smaller[i]]<<","<<arr[i]<<","<<arr[greater[i]]<<endl;
            return ;
        }
    }


    cout<<"No such Triplet Found"<<endl;
}

int main()
{
    int arr[] = {887,778,916,794,336,387,493,650,422,363,28,691,60,764,927,541,427,173,737,212,369,568,430,783,531,863,124,68,136,930,803,23,59,70,168,394,457,12,43,230,374,422,920,785,538,199,325,316,371,414,527,92,981,957,874,863,171,997,282,306,926,85,328,337,506,847,730,314,858,125,896,583,546,815,368,435,365,44,751,88,809,277,179,789};
    int n = sizeof(arr)/sizeof(arr[0]);
    find3Numbers(arr, n);
    return 0;
}