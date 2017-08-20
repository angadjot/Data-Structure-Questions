#include <iostream>
using namespace std;

void minAbsSumPair(int arr[],int n){

    int sum, min_sum = INT_MAX;
    int l=0,r=n-1;
    int min_l=l,min_r=r;

    if(n<2){
        cout<<"Invalid Input";
        return ;
    }

    sort(arr,arr+n);

    while(l<r){
        sum = arr[l]+arr[r];

        if( abs(sum) < abs(min_sum) ){
            min_l = l;
            min_r = r;
            min_sum = sum;
        }

        if(sum < 0)
            l++;
        else
            r--;
    }

    cout<<"The two elements whose sum is minimum are "<<arr[min_l]<<","<<arr[min_r]<<endl;

}

int main(){
    int arr[] = {1, 60, -10, 70, -80, 85};
    int n = sizeof(arr)/sizeof(arr[0]);
    minAbsSumPair(arr, n);
    return 0;
}