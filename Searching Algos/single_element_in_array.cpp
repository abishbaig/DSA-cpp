#include <iostream>
#include <chrono>
#include <vector>
using namespace std;

// Linear Search
// Brute Force Approach: T.C = O(n) - S.C = O(1)
int singleElement1(vector<int>& arr){
    // Traverse Through Whole Array and Find if an Element is != to its left or right indexed element it means it is an Single Element in Sorted Array
    for(int i = 0;i<arr.size();i++){
        if(arr[i] != arr[i+1] && arr[i] != arr[i-1]){
            return arr[i];
        }
    }
    return -1;
}

// XOR Approach: T.C = O(n) - S.C = O(1)
// XOR Property : a^0 = a && a^a = 0
int singleElement2(vector<int>& arr){
    int ans = 0;
    for(int i = 0;i<arr.size();i++){
        ans ^= arr[i];
    }
    return ans;
}


int main(){
    // Recording the starting time
    auto start = chrono::high_resolution_clock::now();

    // Actual Code Logic
    vector<int> arr = {1,1,2,3,3};
    cout<<singleElement2(arr)<<endl;

    // Recording the ending time
    auto end = chrono::high_resolution_clock::now();
    // Calculating the duration
    chrono::duration<double> duration = end - start;
    // Printing the execution time
    cout << "\nExecution time: " << duration.count() << " seconds" << std::endl;

    return 0;
}