//Sort an array of 0s, 1s and 2s
#include <iostream>
using namespace std;

void swap(int *a,int *b){

    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort012(int a[],int n){

    int lo = 0, mid = 0, hi = n-1;

    while(mid <= hi){
        switch(a[mid]){
            case 0:
                swap(&a[mid++],&a[lo++]);
                break;

            case 1:
                mid++;
                break;

            case 2:
                swap(&a[mid],&a[hi--]);
                break;
        }
    }

}

void printArray(int a[],int n){

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

    cout<<endl;
}

int main()
{
    int arr[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    int i;

    sort012(arr, arr_size);

    printf("array after segregation ");
    printArray(arr, arr_size);

    return 0;
}