#include <iostream>
#include <chrono>
using namespace std;

// Count Sort - Optimal Sort = T.C O(n + range) - S.C = O(n)
void countSort(int arr[], int size){
    // Finding Maximum and Minimum Element of Array
    int maxEl = 0, minEl = 0;

    for(int i = 0;i<size;i++){
        maxEl = max(maxEl, arr[i]);
        minEl = min(minEl,arr[i]);
    }

    // Auxilary Array
    int* auxArr = new int[maxEl+1]{0};
    
    // Precomputing the Frequencies in sorted Order
    for(int i = 0;i<size;i++){
        auxArr[arr[i]]++;
    }

    // Sorting Array based on AuxArray
    for(int i = minEl,j=0;i<=maxEl;i++){
        while(auxArr[i]>0){
            arr[j++] = i;
            auxArr[i]--;
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
    countSort(arr,5);
    printArr(arr,5);

    // Recording the ending time
    auto end = chrono::high_resolution_clock::now();
    // Calculating the duration
    chrono::duration<double> duration = end - start;
    // Printing the execution time
    cout << "\nExecution time: " << duration.count() << " seconds" << std::endl;

    return 0;
}