#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;



// My Approach: Slow - Fast Pointers : T.C = O(nlogn) - S.C = O(1)
int majorityElement1(vector<int>& arr){
    // Calculating Half Size of Array : N/2
    int halfSize = arr.size()/2;
    
    // Sorting Array
    sort(arr.begin(),arr.end());
    
    // Initializing Pointers, Current Element and Frequency of that Element in Array
    int p1 = 0, p2 = 0;
    int currElmnt = 0;
    int freqEl = 0;

    // Finding Majority Element
    while(p2<arr.size()){
        if(arr[p1] == arr[p2]){
            currElmnt = arr[p1];
            freqEl = max(freqEl,((p2-p1)+1));
            p2++;
        }
        else if(arr[p1] != arr[p2]){
            p1 = p2;
        }
        
        if(freqEl>halfSize){
            return currElmnt;
        }
    }

    // Returning -1 in case of no Findings
    return -1;
}

// Better Approach: HashMap: T.C = O(n) - S.C = O(1)
int majorityElement2(vector<int>& arr){
    // Declaring an unordered map for holding Array Elements and Their frequencies
    unordered_map<int,int> map;

    // Storing n/2
    int halfSize = arr.size()/2;

    // Precomputing
    for(int i = 0;i<arr.size();i++){
        map[arr[i]]++;
    }

    // Checking if some Elements Frequency is > n/2
    for(auto x: map){
        if(x.second > halfSize){
            return x.first;
        }
    }

    // Else -1 : Not Found
    return -1;
}


// Optimal Approach: Moore's Voting Algorithm: T.C = O(n) - S.C = O(1)
int majorityElement3(vector<int>& arr){
    // Size of Array
    int n = arr.size();
    
    // Initializing Count and ELmenent
    int count = 0;
    int element;

    /* Iterating and checking IF
     Count = 0 -> Count = 1 && Element = arr[i]
     Element == Arr[i] -> Count++
     Element != Arr[i] -> Count--*/
    for(int i =0; i<n;i++){
        if(count <= 0){
            count = 1;
            element = arr[i];
        }
        else if(element == arr[i]){
            count++;
        }
        else{
            count--;
        }
    }

    // Checking if the Element we got is the Majority element or not
    int cnt = 0;
    for(int i = 0;i<n;i++){
        if(element == arr[i]){
            cnt++;
        }
    }

    // Majority Element > n/2
    if(cnt > (n/2)){
        return element;
    }
    // Else
    return -1;
}


int main(){
    // Recording the starting time
    auto start = chrono::high_resolution_clock::now();

    // Actual Code Logic
    vector<int> arr = {3,2,3};
    cout<<majorityElement3(arr)<<endl;

    // Recording the ending time
    auto end = chrono::high_resolution_clock::now();
    // Calculating the duration
    chrono::duration<double> duration = end - start;
    // Printing the execution time
    cout << "\nExecution time: " << duration.count() << " seconds" << std::endl;

    return 0;
}