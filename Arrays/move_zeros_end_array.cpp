#include <iostream>
#include <chrono>
#include <vector>
using namespace std;

// Function for Printing Array : T.C = O(n)
void printArr(vector<int> arr)
{
    for (auto x : arr)
    {
        cout << x << ", ";
    }
    cout << endl;
}


// My Approach: 2 Pointer : T.C = O(n) - S.C = O(1)
void moveZerosEnd(vector<int>& arr){
    if(arr.size()<=1){
        printArr(arr);
        return;
    }
    // Starting Both Pointers from 0th Index
    int nonZeroPT = 0;
    int zeroPT = 0;

    // Iterating while nonZeroPointer reaches end of array
    while(nonZeroPT<arr.size()){
        // if both pointers are zero
        if(arr[zeroPT] == 0 && arr[nonZeroPT] == 0){
            nonZeroPT++;
        }
        // if zeroPt = 0 and nonZero != 0
        else if(arr[zeroPT] == 0 && arr[nonZeroPT] != 0){
            swap(arr[zeroPT],arr[nonZeroPT]);
            zeroPT++;
        }
        // If both pointers != 0
        else{
            zeroPT++;
            nonZeroPT++;
        }
    }
    printArr(arr);
}

int main(){
    // Recording the starting time
    auto start = chrono::high_resolution_clock::now();

    // Actual Code Logic
    vector<int> arr = {1,2,0,1,0,4,0};
    moveZerosEnd(arr);

    // Recording the ending time
    auto end = chrono::high_resolution_clock::now();
    // Calculating the duration
    chrono::duration<double> duration = end - start;
    // Printing the execution time
    cout << "\nExecution time: " << duration.count() << " seconds" << std::endl;

    return 0;
}