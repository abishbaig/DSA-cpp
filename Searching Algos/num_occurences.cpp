#include <iostream>
#include <chrono>
#include <vector>
#include <climits>
using namespace std;


// My Approach: Optimal Approach: T.C = O(logN) - S.C = O(1)
int numOccurences(vector<int>& arr, int target){
    int numCount = 0, start = 0, end = arr.size()-1;
    int last = INT_MIN, first = INT_MAX;
    // First Occurence Logic
    while(start<=end){
        int mid = (start+end)/2;
        if(arr[mid] == target){
            first = first>=mid?mid:first;
            end = mid - 1;
        }
        else if(arr[mid]>target){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }

    // Last Occurence Logic
    start = 0, end = arr.size()-1;
    while(start<=end){
        int mid = (start+end)/2;
        if(arr[mid] == target){
            last = last<mid?mid:last;
            start = mid + 1;
        }
        else if(arr[mid] > target){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    // Logic: (End_Index - First_Index) + 1
    return ((first!=INT_MAX && last!=INT_MIN)?(abs(end-first)+1):0);
}


int main(){
    // Recording the starting time
    auto start = chrono::high_resolution_clock::now();

    // Actual Code Logic
    vector<int> arr = {1, 1, 2, 2, 2, 2, 2, 3};
    cout<<numOccurences(arr,2)<<endl;

    // Recording the ending time
    auto end = chrono::high_resolution_clock::now();
    // Calculating the duration
    chrono::duration<double> duration = end - start;
    // Printing the execution time
    cout << "\nExecution time: " << duration.count() << " seconds" << std::endl;

    return 0;
}