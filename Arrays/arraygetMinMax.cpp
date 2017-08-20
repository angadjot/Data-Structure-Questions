//Maximum and minimum of an array using minimum number of comparisons
#include <iostream>
using namespace std;

struct pairMin{
    int min;
    int max;
};

struct pairMin getMinMax(int arr[],int low,int high){

    struct pairMin minmax, mml,mmr;

    if(high == low){
        minmax.min = arr[low];
        minmax.max = arr[low];

        return minmax;
    }

    if(high == low+1){

        if(arr[low] > arr[high]){
            minmax.max = arr[low];
            minmax.min = arr[high];
        }
        else{
            minmax.max = arr[high];
            minmax.min = arr[low];
        }

        return minmax;
    }

    int mid = (low+high)/2;
    mml = getMinMax(arr,low,mid);
    mmr = getMinMax(arr,mid+1,high);

    if(mml.min < mmr.min)
        minmax.min = mml.min;
    else
        minmax.min = mmr.min;

    if(mml.max > mmr.max)
        minmax.max = mml.max;
    else
        minmax.max = mmr.max;

    return minmax;
}

int main()
{
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    int arr_size = 6;
    struct pairMin minmax = getMinMax(arr, 0, arr_size-1);
    printf("\nMinimum element is %d", minmax.min);
    printf("\nMaximum element is %d", minmax.max);
    return 0;
}