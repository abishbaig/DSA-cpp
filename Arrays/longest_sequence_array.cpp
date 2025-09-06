#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_set>
using namespace std;

// My Approach: Single Traversel + Sorting: T.C = O(nlogn) - S.C = O(1)
int longestSequence1(vector<int>& arr){
    // Sorted Array
    sort(arr.begin(),arr.end());

    // Let LastSmallest to be -infinity as starting with Global minma to obtain Global Maxima
    int lastSmallest = INT_MIN;
    // Initializing vars
    int longSeq = 0;
    int cnt = 0;

    /*
    If ith Element - 1 = lastSmallest ELement then update count and lastSmallest
    Else if ith Element != Last Smallest Element also... then it means consectives is broken and have to restart count
    */
    for(int i = 0;i<arr.size();i++){
        if(arr[i] - 1 == lastSmallest){
            cnt++;
            lastSmallest = arr[i];
        }
        else if(arr[i] != lastSmallest){
            cnt = 1;
            lastSmallest = arr[i];
        }
        longSeq = max(longSeq,cnt);
    }

   return longSeq;
}


// Optimal Approach: Set DS: T.C = O(N) and worst case O(n^2) and set case = O(nlogn) - S.C = O(n) as and unordered_set takes O(1) to complete its Operations while set takes O(logn)
int longestSequence2(vector<int>& arr){
    // If Array is empty
    if(arr.size() == 0) return 0;
    // Unordered Set for O(1) Operations Time
    unordered_set<int> set;
    int longSeq = 1;
    
    // Inserting all array elements into set
    for(auto x: arr){
        set.insert(x);
    }

    // Finding Long Sequence from starting number (whose x-1 doesnot exist)
    for(auto it: set){
        // Starting Number of Any Sequence found 
        if(set.find(it-1) == set.end()){
            int cnt = 1;
            int x = it;
            // Now Finding x+1, x+2, x+3 ...
            while(set.find(x+1) != set.end()){
                x = x+1;
                cnt = cnt + 1;
            }
            // Updating Count
            longSeq = max(cnt,longSeq);
        }
    }

    return longSeq;
}

int main(){
    // Recording the starting time
    auto start = chrono::high_resolution_clock::now();

    // Actual Code Logic
    vector<int> arr = {3,5,6,7,8};  // 3,5,6,7,8
    cout<<longestSequence2(arr)<<endl;

    // Recording the ending time
    auto end = chrono::high_resolution_clock::now();
    // Calculating the duration
    chrono::duration<double> duration = end - start;
    // Printing the execution time
    cout << "\nExecution time: " << duration.count() << " seconds" << std::endl;

    return 0;
}