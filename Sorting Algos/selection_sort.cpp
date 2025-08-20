#include <iostream>
#include <chrono>
using namespace std;

// Brute Force : T.C = O(n^2) - S.C = O(1)
void selectionSort(int arr[], int size){
    // Iterating to size-1 becoz last element will be already sorted
    for(int i = 0;i<size-1;i++){
        // Considereing Unsorted Subarray ith-1st Element as Min Element
        int minElement = i;

        // Inner Loop for Searching Global Min Element in Unsorted Array after Ith Element 
        for(int j = i+1;j<size;j++){
            if(arr[j] < arr[minElement]){
                minElement = j;
            }
        }

        // Swapping Min Element with ith Element for making Sorted Part
        swap(arr[minElement],arr[i]);
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
    selectionSort(arr,5);
    printArr(arr,5);

    // Recording the ending time
    auto end = chrono::high_resolution_clock::now();
    // Calculating the duration
    chrono::duration<double> duration = end - start;
    // Printing the execution time
    cout << "\nExecution time: " << duration.count() << " seconds" << std::endl;

    return 0;
}