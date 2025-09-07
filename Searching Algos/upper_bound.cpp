#include <iostream>
#include <chrono>
#include <vector>
using namespace std;


// Optimal Approach: Binary Search: T.C = O(logN) - S.C = O(1)
int upperBound(vector<int>& arr, int x){
    // Initializn Answer Index = SIze of Array
    int start = 0, end = arr.size()-1, ans = arr.size(), mid = 0;

    while(start<=end){
        mid = (start+end)/2;
        // Maybe Answer Index Found as arr[index] > x
        if(arr[mid] > x){
            ans = mid;
            // Searching for Smallest Index such that arr[i] > x in left part
            end = mid - 1;
        }
        else{
            // Searching in right part
            start = mid + 1;
        }
    }

    return ans;
}



int main(){
    // Recording the starting time
    auto start = chrono::high_resolution_clock::now();

    // Actual Code Logic
    vector<int> arr = {1,2,3,4,5};
    cout<<upperBound(arr,2)<<endl;

    // Recording the ending time
    auto end = chrono::high_resolution_clock::now();
    // Calculating the duration
    chrono::duration<double> duration = end - start;
    // Printing the execution time
    cout << "\nExecution time: " << duration.count() << " seconds" << std::endl;

    return 0;
}