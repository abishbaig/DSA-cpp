#include <iostream>
#include <chrono>
#include <vector>
using namespace std;

// Function for Printing Array : T.C = O(n)
void printArr(vector<int> arr){
    for(auto x: arr){
        cout<<x<<", ";
    }
    cout<<endl;
}

// My Approach : T.C = O(N) - S.C = O(1) 
void leftRotate1(vector<int>& arr){
    for(int i = 0;i<arr.size()-1;i++){
        swap(arr[i],arr[i+1]);
    }

    printArr(arr);
}

// Optimal Approach: T.C = O(n) - S.C = O(1)
void leftRotate2(vector<int>& arr){
    // Storing 1st Index
    int temp = arr[0];
    // Assigning Each Index to its Left Corespondence
    for(int i = 0;i<arr.size()-1;i++){
        arr[i] = arr[i+1];
    }
    // Assigning Last Index as 1st Index Stored Value
    arr[arr.size()-1] = temp;
    printArr(arr);
}

int main(){
    // Recording the starting time
    auto start = chrono::high_resolution_clock::now();

    // Actual Code Logic
    vector<int> arr = {1,2,3,4,5};
    leftRotate2(arr);

    // Recording the ending time
    auto end = chrono::high_resolution_clock::now();
    // Calculating the duration
    chrono::duration<double> duration = end - start;
    // Printing the execution time
    cout << "\nExecution time: " << duration.count() << " seconds" << std::endl;

    return 0;
}