#include <iostream>
#include <chrono>
using namespace std;

// Brute Force : T.C = O(n^2) - S.C = O(1)
void bubbleSort1(int arr[],int size){
    for(int i = 0;i<size;i++){
        for(int j = 0;j<size-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

// Optimized Approach : T.C = O(n^2) & Best Case = O(n) {Array Sorted Already} - S.C = O(1)
void bubbleSort2(int arr[], int size){
    for(int i = 0;i<size;i++){
        int didSwap = 0;
        for(int j = 0;j<size-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                didSwap = 1;
            }
        }
        if(didSwap == 0){
            break;
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
    bubbleSort2(arr,5);
    printArr(arr,5);

    // Recording the ending time
    auto end = chrono::high_resolution_clock::now();
    // Calculating the duration
    chrono::duration<double> duration = end - start;
    // Printing the execution time
    cout << "\nExecution time: " << duration.count() << " seconds" << std::endl;

    return 0;
}