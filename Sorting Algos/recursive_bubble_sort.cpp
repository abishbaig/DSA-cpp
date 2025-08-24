#include <iostream>
#include <chrono>
using namespace std;

// Recursive Approach : T.C = O(n^2) - S.C = O(N)
void recursiveBubbleSort1(int arr[], int size){
    // Base case if Range == 1
    if(size == 1){
        return;
    }
    // Bubble Sort Inner Loop Logic (Swapping)
    for(int j = 0;j<size-1;j++){
        if(arr[j] > arr[j+1]){
            swap(arr[j], arr[j+1]);
        }
    }

    // Decrementing Range i.e Size
    recursiveBubbleSort1(arr,size-1);
}


// Recursive Optimized Approach : T.C = O(n^2) and in Best Case = O(n) - S.C = O(N)
void recursiveBubbleSort2(int arr[], int size){
    // Base case if Range == 1
    if(size == 1){
        return;
    }
    int didSwap = 0;
    // Bubble Sort Inner Loop Logic (Swapping)
    for(int j = 0;j<size-1;j++){
        if(arr[j] > arr[j+1]){
            swap(arr[j], arr[j+1]);
            didSwap = 1;
        }
    }

    // If No Swapping Occurs means Already Sorted Array
    if(didSwap == 0){
        return;
    }

    // Decrementing Range i.e Size
    recursiveBubbleSort2(arr,size-1);
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
    recursiveBubbleSort1(arr,5);
    printArr(arr,5);

    // Recording the ending time
    auto end = chrono::high_resolution_clock::now();
    // Calculating the duration
    chrono::duration<double> duration = end - start;
    // Printing the execution time
    cout << "\nExecution time: " << duration.count() << " seconds" << std::endl;

    return 0;
}