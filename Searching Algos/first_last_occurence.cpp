#include <iostream>
#include <chrono>
#include <vector>
#include <climits>
using namespace std;


// Approach
vector<int> searchRange(vector<int>& nums, int target) {
    int start = 0, end = nums.size()-1;
    int first = INT_MAX, last = INT_MIN;

    // Logic to Find First Occurence
    // Same Logic as for Lower Bound Except we are Exact Matching the Target
    while(start<=end){
        int mid = (start+end)/2;
        if(nums[mid] == target){
            first = first>=mid?mid:first;
            end = mid - 1; // For Finding 1st Smallest Target Element Index
        }
        else if(nums[mid] > target){
            // Left Half Traversel
            end = mid-1; // Used from Binary Search Logic
        }
        else{
            // Right Half Traversel
            start = mid+1;
        }
    }
    
    // Logic to Find Last Occurence
    // Same Logic as for First Occurence Except upon matching we have to Update Start -> mid + 1 to Traverse and Find Most Last Occurence Index
    start = 0, end = nums.size()-1;
    while(start<=end){
        int mid = (start+end)/2;
        if(nums[mid] == target){
            last = last<mid?mid:last;
            start = mid + 1;
        }
        else if(nums[mid] > target){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    // Returining Element's Indexes if present otherwise -1, -1
    return {first!=INT_MAX?first:-1,last!=INT_MIN?last:-1};
}


int main(){
    // Recording the starting time
    auto start = chrono::high_resolution_clock::now();

    // Actual Code Logic
    vector<int> arr = {1,2,3};
    cout<<searchRange(arr,1)[0]<<", "<<searchRange(arr,1)[1]<<endl;

    // Recording the ending time
    auto end = chrono::high_resolution_clock::now();
    // Calculating the duration
    chrono::duration<double> duration = end - start;
    // Printing the execution time
    cout << "\nExecution time: " << duration.count() << " seconds" << std::endl;

    return 0;
}