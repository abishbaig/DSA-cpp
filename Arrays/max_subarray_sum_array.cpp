#include <iostream>
#include <chrono>
#include <vector>
#include <climits>
using namespace std;

// Brute Force: T.C = O(n^3) - S.C = O(1)
int maxSum1(vector<int>& arr){
    // SIze of Array
    int n = arr.size();

    int maxSum = INT_MIN;
    int localSum = 0;

    // Subarray Finding Logic and Calculating MaxSum in After Each Subarray Iteration upon Calculating Local Sum
    for(int i = 0;i<n;i++){
        for(int j = i;j<n;j++){
            localSum = 0;
            for(int m = i; m<=j;m++){
                localSum += arr[m];
            }
            maxSum = max(maxSum,localSum);
        }
    }

    return maxSum;
}


// Better Approach: T.C = O(n^2) - S.C = O(1)
int maxSum2(vector<int>& arr){
    // SIze of Array
    int n = arr.size();

    int maxSum = INT_MIN;
    int localSum = 0;

    // Current Subarray Sum = Previous Subarray Sum + Current Element
    for(int i = 0;i<n;i++){
        for(int j = i;j<n;j++){
            localSum += arr[j];
            maxSum = max(maxSum,localSum);
        }
        localSum = 0;
    }

   return maxSum;
}

// Optimal Approach: Kadane's Algorithm: T.C = O(n) - S.C = O(1)
int maxSum3(vector<int>& arr){  
    int n = arr.size();
    
    int maxSum = INT_MIN;
    int localSum = 0;
    
    // If Local Sum < 0 make it 0
    // Else maxSum = max(local,maxSum)
    
    for(int i = 0;i<n;i++){
        localSum += arr[i];
        
        maxSum = max(localSum,maxSum);
        
        if(localSum<0){
            localSum = 0;
        }
    }

    // An Array's Maximum Sum should be a positive integer or zero if Mentioned in Question
    // if(maxSum > 0){
    //     return maxSum;
    // }
    // else{
    //     return 0;
    // }

    return maxSum;
}

int main(){
    // Recording the starting time
    auto start = chrono::high_resolution_clock::now();

    // Actual Code Logic
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSum3(arr)<<endl;

    // Recording the ending time
    auto end = chrono::high_resolution_clock::now();
    // Calculating the duration
    chrono::duration<double> duration = end - start;
    // Printing the execution time
    cout << "\nExecution time: " << duration.count() << " seconds" << std::endl;

    return 0;
}