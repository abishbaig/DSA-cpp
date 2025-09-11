#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


// Brute Force Approach: Linear Search: T.C = O(max(Arr[])*n) - S.C = O(1)
int smallestDivisor1(vector<int>& arr, int limit){
    int n = arr.size();
    // Function to Get Max out of the Whole Array
    int maxArr = *max_element(arr.begin(),arr.end()); // O(n)

    // Traversing from 1 - max(arr[]) and finding a Divisor whose sum <= limit
    for(int div = 1;div<=maxArr;div++){
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum += ceil((double)(arr[i])/(double)(div));
        }
        if(sum<=limit){
            return div;        
        }
    }
    return -1;
}

// Helper Function to Find Sum
int sumByDiv(vector<int>& arr, int div){
    int n = arr.size();
    int sum = 0;
    for(int i = 0;i<n;i++){
        sum += ceil((double)(arr[i])/(double)(div));
    }
    return sum;
}

// Optimal Approach: Binary Search: T.C = O(nlogn) - S.C = O(1)
int smallestDivisor2(vector<int>& arr, int limit){
    int n = arr.size();
    if(n>limit) return -1;
    // Function to Get Max out of the Whole Array
    int high = *max_element(arr.begin(),arr.end()); // O(n)
    int low = 1;
    // Using Lower Bound Logic
    while(low<=high){
        int mid = (low+high)/2;
        if(sumByDiv(arr,mid) <= limit){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return low;
}

int main(){
    // Recording the starting time
    auto start = chrono::high_resolution_clock::now();

    // Actual Code Logic
    vector<int> arr = {1,2,5,9};
    cout<<smallestDivisor2(arr,6)<<endl;

    // Recording the ending time
    auto end = chrono::high_resolution_clock::now();
    // Calculating the duration
    chrono::duration<double> duration = end - start;
    // Printing the execution time
    cout << "\nExecution time: " << duration.count() << " seconds" << std::endl;

    return 0;
}