#include <iostream>
#include <chrono>
using namespace std;


// Recursive Approach : T.C = O(n^2) and in Best Case = O(n) - S.C = O(N)
void recursiveInsertionSort(int arr[], int curr, int size){
    // Base Case if curr == size
    if(curr == size){
        return;
    }
    
    // Insertion Sort Logic
    int prev = curr;
    while(prev>0 && arr[prev-1]>arr[prev]){
        swap(arr[prev-1],arr[prev]);
        prev--;
    }

    // Recursive Call
    recursiveInsertionSort(arr,curr+1,size);

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
    recursiveInsertionSort(arr,0,5);
    printArr(arr,5);

    // Recording the ending time
    auto end = chrono::high_resolution_clock::now();
    // Calculating the duration
    chrono::duration<double> duration = end - start;
    // Printing the execution time
    cout << "\nExecution time: " << duration.count() << " seconds" << std::endl;

    return 0;
}