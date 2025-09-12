#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
using namespace std;


// My Approach: Hashing : T.C = O(n) - S.C = O(n)
int kthMissingInt1(vector<int>& arr, int k){
    int maxElement = *max_element(arr.begin(),arr.end());
    vector<int> tempMiss(maxElement+1);

    // Precomputing
    for(int i = 0;i<arr.size();i++){
        tempMiss[arr[i]]++;
    }

    // Decremeting k when a missing value is found and returing the last missing value
    int missVal = 0;
    for(int i = 1;i<tempMiss.size();i++){
        if(k<=0){
            break;
        }
        else if(tempMiss[i] <= 0){
            missVal = i;
            k--;
        }
    }
    return missVal;
}

// Brute Force: Linear Traverse : T.C = O(n) - S.C = O(1)
int kthMissingInt2(vector<int>& arr, int k){
    // If Current Element is <= k increment k else break the loop
    for(int i = 0;i<arr.size();i++){
        if(arr[i]<=k) k++;
        else break;
    }
    return k;
}

// Optimal Approach: Binary Search: T.C = O(logN) - S.C = O(1)
int kthMissingInt3(vector<int>& arr, int k){
    int low = 0, high = arr.size()-1;
    while(low<=high){
        int mid = (low+high)/2;
        // Finding Missing Value
        int missingVal = arr[mid] - (mid+1);
        if(missingVal<k){
            // Right Half
            low = mid + 1;
        }
        else{
            // Left Half
            high = mid - 1;
        }
    }
    // Returning Current Index of High + 1 + k's value
    return k + 1 + high;
}


int main(){
    // Recording the starting time
    auto start = chrono::high_resolution_clock::now();

    // Actual Code Logic
    vector<int> arr = {2,3,4,7,11};
    cout<<kthMissingInt3(arr,5)<<endl;
    

    // Recording the ending time
    auto end = chrono::high_resolution_clock::now();
    // Calculating the duration
    chrono::duration<double> duration = end - start;
    // Printing the execution time
    cout << "\nExecution time: " << duration.count() << " seconds" << std::endl;

    return 0;
}