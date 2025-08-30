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

// Reversing Array: T.C = O(n) - S.C = O(1) -> 2 Pointer Approach
void reverseArr(vector<int>& arr, int start, int end){
    while(start<end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}


// Optimal Approach : Reversal Algo. : T.C = O(n) - S.C = O(1)
void rotateArr(vector<int> &arr, int k_places, char pos)
{
    // Checking if Rotations # are less than actual size
    k_places = k_places%arr.size();
    if(k_places>arr.size() || arr.size()<=1){
        printArr(arr);
        return;
    }
    else if (pos == 'R')
    {
        // Right Rotate Logic
        // Reversing first n-k elements
        reverseArr(arr,0,arr.size()-k_places-1);

        // Reversing last k elements
        reverseArr(arr,arr.size()-k_places,arr.size()-1);

        // Revsersing Whole Array
        reverseArr(arr,0,arr.size()-1);
    }
    else
    {
        // Left Rotate Logic
        // Reversing first k-1 elements
        reverseArr(arr,0,k_places-1);

        // Reversing last n-k elements
        reverseArr(arr,k_places,arr.size()-1);

        // Revsersing Whole Array
        reverseArr(arr,0,arr.size()-1);
    }
    printArr(arr);
}

int main()
{
    // Recording the starting time
    auto start = chrono::high_resolution_clock::now();

    // Actual Code Logic
    vector<int> arr = {-1,-100,3,99};
    rotateArr(arr, 2, 'R');

    // Recording the ending time
    auto end = chrono::high_resolution_clock::now();
    // Calculating the duration
    chrono::duration<double> duration = end - start;
    // Printing the execution time
    cout << "\nExecution time: " << duration.count() << " seconds" << std::endl;

    return 0;
}