#include <iostream>
#include <chrono>
#include <vector>
using namespace std;


// Brute Force: Linear Search: T.C = O(n) - S.C = O(1)
int lowerBoundIndex1(vector<int>& arr, int x){
    // Traversing Whole Array to Find index such that : arr[index] >= x
    for(int i = 0;i<arr.size();i++){
        if(arr[i] >= x){
            return i;
        }
    }
    // If No Index Found Returns Size of Array
    return arr.size();
}

// Optimal Approach: Binary Search Algo Usage: Works on Already Sorted Array : T.C = O(logN) - S.C = O(1)
int lowerBoundIndex2(vector<int>& arr, int x){
    // Initializing Answer Index with n
    int start = 0, end = arr.size()-1, mid = 0, ans = arr.size();
    // Finding Index if it is >= x other wise searching in next part of the array i.e mid + 1 or if it is found searching if in lower part of array is present an index whose value is also same
    while(start<=end){
        mid = (start+end)/2;
        if(arr[mid]>=x){
            // Maybe an Answer
            ans = mid;
            // Looking for arr[i] >= x in Left Part if array contains all big numbers than x
            end = mid - 1;
        }
        else{
            // Looking for in the right part
            start = mid + 1;
        }
    }
    // If No Index Found Returns Size of Array
    return ans;
}


int main(){
    // Recording the starting time
    auto start = chrono::high_resolution_clock::now();

    // Actual Code Logic
    vector<int> arr = {10,20,30,40,50,60};
    cout<<lowerBoundIndex2(arr,2)<<endl;
    


    // Recording the ending time
    auto end = chrono::high_resolution_clock::now();
    // Calculating the duration
    chrono::duration<double> duration = end - start;
    // Printing the execution time
    cout << "\nExecution time: " << duration.count() << " seconds" << std::endl;

    return 0;
}