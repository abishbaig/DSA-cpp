#include <iostream>
#include <chrono>
#include <vector>
using namespace std;

// Iterative Binary Search: T.C = O(logN) - S.C = O(1)
int search(vector<int>& nums, int target) {
    // Intialzing Start and End Pointers
    int start = 0, end = nums.size() - 1;
    // Finding Mid of Array
    int mid = (start+end)/2;

    // While start and end pointers donot Overlap
    while(start<=end){
        // Finding Mid in each Iteration for new Sub Sequence
        mid = (start+end)/2;
        if(target == nums[mid]) return mid;
        else if(target < nums[mid]){
            end = mid-1;
        }
        else if(target > nums[mid]){
            start = mid+1;
        }
    }

    return -1;
}


// Recursive Binary Approach: T.C = O(logN) - S.C = O(n) -> Recursive Stack Calls
int binarySearch(vector<int>& nums, int target, int start, int end){
    if(start>end) return -1;
    int mid = (start+end)/2;
    if(nums[mid] == target) return mid;
    else if(target > nums[mid]){
        binarySearch(nums,target,mid+1,end);
    }
    else if(target < nums[mid]){
        binarySearch(nums,target,start,mid-1);
    }
}

int main(){
    // Recording the starting time
    auto start = chrono::high_resolution_clock::now();

    // Actual Code Logic
    vector<int> arr = {-1,0,3,5,9,12};
    cout<<binarySearch(arr,2,0,arr.size()-1)<<endl;

    // Recording the ending time
    auto end = chrono::high_resolution_clock::now();
    // Calculating the duration
    chrono::duration<double> duration = end - start;
    // Printing the execution time
    cout << "\nExecution time: " << duration.count() << " seconds" << std::endl;

    return 0;
}