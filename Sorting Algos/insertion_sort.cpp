#include <iostream>
#include <chrono>
using namespace std;

// Brute Force : T.C = O(n^2) && Best Case = O(n) - S.C = O(1)
void insertionSort(int arr[], int size){
    for(int curr = 0;curr<size;curr++){
        int prev = curr;
        while(prev>0 && arr[prev-1]>arr[prev]){
            swap(arr[prev-1],arr[prev]);
            prev--;
        }
    }
}

// Function for Printing Array : T.C = O(n)
void printArr(int arr[], int size){
    for(int x = 0;x<size;x++){
        cout<<arr[x]<<", ";
    }
    cout<<endl;
}


int main(){
    // Recording the starting time
    auto start = chrono::high_resolution_clock::now();

    // Actual Code Logic
    int arr[5] = {5,4,3,2,1};
    insertionSort(arr,5);
    printArr(arr,5);

    // Recording the ending time
    auto end = chrono::high_resolution_clock::now();
    // Calculating the duration
    chrono::duration<double> duration = end - start;
    // Printing the execution time
    cout << "\nExecution time: " << duration.count() << " seconds" << std::endl;

    return 0;
}