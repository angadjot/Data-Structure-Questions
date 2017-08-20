#include <iostream>
using namespace std;

struct petrolpump{
    int petrol;
    int distance;
};

int printTour(petrolpump arr[], int n){

    int start = 0;
    int end = 1;

    int curr_petrol = arr[start].petrol - arr[start].distance;

    while(end != start || curr_petrol < 0){

        while(curr_petrol < 0 && start != end){

            curr_petrol -= arr[start].petrol - arr[start].distance;
            start = (start+1)%n;

            if(start == 0) {
                return -1;
            }

        }

        curr_petrol +=arr[end].petrol - arr[end].distance;
        end = (end+1)%n;
    }

    return start;
}

int main()
{
    struct petrolpump arr[] = {{6, 4}, {3, 6}, {7, 3}};

    int n = sizeof(arr)/sizeof(arr[0]);
    int start = printTour(arr, n);

    (start == -1)? cout<<"No solution"<<endl : cout<<"Start = "<<start<<endl;

    return 0;
}