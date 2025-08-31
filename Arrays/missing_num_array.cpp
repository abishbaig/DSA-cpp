#include <iostream>
#include <chrono>
#include <vector>
using namespace std;

// My Approach: Hashing : T.C = O(n) - S.C = O(n)
int missingNum1(vector<int>& arr){
    // Initializing an Freq Array
    vector<int> freqArr(arr.size()+1);

    // Precomputing Frequencies of all elements
    for(int i = 0;i<arr.size();i++){
        freqArr[arr[i]]++;
    }

    // If any element has freqCount = 0 then it is the missing element
    for(int i = 1;i<freqArr.size();i++){
        if(freqArr[i] <= 0){
            return i;
        }
    }
}

// Summation Approach: T.C = O(N) - S.C = O(1)
int missingNum2(vector<int>& arr, int range){
    // Sum of N Natural Numbers
    int n = range;
    int sum1 = ((n*(n+1))/2);

    // Calculating Individual Elements Sum
    int sum2 = 0;
    for(int i = 0;i<arr.size();i++){
        sum2 += arr[i];
    }
    
    // Missing Number = S1 - S2
    int missingNum = sum1 - sum2;
    if(missingNum != 0){
        return missingNum;
    }
    else{
        // Indicates no missing value
        return -1;
    }
}

// XOR Approach: T.C = O(n) - S.C = O(1) => (0^a) = a && (a^a) = 0 
// Works for Whole Numbers
int missingNum3(vector<int>& arr){
    int xor1 = 0, xor2 = 0;
    // XOR1 = 1-N
    // XOR2 = arr[0] - arr[n-1]
    for(int i = 0;i<arr.size();i++){
        xor1 = xor1^(i);
        xor2 = xor2^arr[i];
    }
    // Remaining Last N ^ XOR1
    xor1 ^= arr.size();
    // Missing Number 0^missing = missing
    return xor1^xor2;
}


// XOR Approach: T.C = O(n) - S.C = O(1) => (0^a) = a && (a^a) = 0 
// Works for Natural Numbers
int missingNum4(vector<int>& arr){
    int xor1 = 0, xor2 = 0;
    // XOR1 = 1-N
    // XOR2 = arr[0] - arr[n-1]
    for(int i = 0;i<arr.size()-1;i++){
        xor1 = xor1^(i+1);
        xor2 = xor2^arr[i];
    }
    // Remaining Last N ^ XOR1
    xor1 ^= arr.size();
    // Missing Number 0^missing = missing
    return xor1^xor2;
}

int main(){
    // Recording the starting time
    auto start = chrono::high_resolution_clock::now();

    // Actual Code Logic
    vector<int> arr = {1,2,4,5};
    cout<<missingNum4(arr)<<endl;

    // Recording the ending time
    auto end = chrono::high_resolution_clock::now();
    // Calculating the duration
    chrono::duration<double> duration = end - start;
    // Printing the execution time
    cout << "\nExecution time: " << duration.count() << " seconds" << std::endl;

    return 0;
}