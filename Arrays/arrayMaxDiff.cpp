//Maximum difference between two elements such that larger element appears after the smaller number
#include <iostream>
using namespace std;

int maxDiff(int arr[],int size){

    int max_diff = arr[1] - arr[0];
    int min_element = arr[0];

    for(int i=0;i<size;i++){

        if(arr[i]-min_element > max_diff)
            max_diff = arr[i] - min_element;

        if(arr[i] < min_element)
            min_element = arr[i];
    }

    return max_diff;
}

int main()
{
  int arr[] = {1, 2, 90, 10, 110};
  printf("Maximum difference is %d",  maxDiff(arr, 5));
  return 0;
}