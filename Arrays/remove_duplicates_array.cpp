#include <iostream>
#include <chrono>
#include <vector>
#include <set>
using namespace std;


// Brute Force: T.C = O(nlogn) - S.C = O(n) -> Hash Set
int removeDuplicates1(vector<int>& arr){
    // Initialize Set DS to store Unique Elements only
    set<int> sets;
    // Iterating thorough whole array and storing elements
    for(int i = 0;i<arr.size();i++){
        sets.insert(arr[i]);
    }
    // Finding k
    int k = sets.size();
    int j = 0;
    // Inserting back to Original Array
    for(int x: sets){
        arr[j++] = x;
    }

    return k;
}

// Optimal Approach: 2 Pointers (Mine Approach) : T.C = O(n) - S.C = O(1) 
int removeDuplicates2(vector<int>& arr){
    // Starting Index Pointer
    int prev = 0;
    
    // Iterating through whole array and Moving Unique Elements at start
    for(int curr = 1;curr<arr.size();curr++){
        if(arr[prev]!=arr[curr]){
            prev++;
            arr[prev] = arr[curr];
        }
    }

    int k = prev+1;
    return k;
}

int main(){
    // Recording the starting time
    auto start = chrono::high_resolution_clock::now();

    // Actual Code Logic
    vector<int> arr = {1,2,3};

    cout<<removeDuplicates2(arr)<<endl;
    

    // Recording the ending time
    auto end = chrono::high_resolution_clock::now();
    // Calculating the duration
    chrono::duration<double> duration = end - start;
    // Printing the execution time
    cout << "\nExecution time: " << duration.count() << " seconds" << std::endl;

    return 0;
}