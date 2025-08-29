#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
using namespace std;


// Brute Force: T.C = O(n) - S.C = O(1)
bool isSorted1(int arr[], int size){
    // Traversing through whole array and check if the current element is smallest then the next element
    for(int i = 0; i<size-1; i++){
        if(arr[i] > arr[i+1]){
            return false;
        }
    }
    return true;
}

// Check Array Sorted After Rotation by x Positions
// Brute Force: O(n^2) - S.C = O(n)
bool sortedArrRot(vector<int>& nums){
    vector<int> orgNum = nums;
    sort(orgNum.begin(),orgNum.end());
    
    for(int x = 0;x<=nums.size();x++){
        bool sorted = true;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] != orgNum[(i+x)%orgNum.size()]){
                sorted = false;
                break;
            }
        }

        if(sorted){
            return true;
        }
    }

    return false;
}

int main(){
    // Recording the starting time
    auto start = chrono::high_resolution_clock::now();

    // Actual Code Logic
    vector<int> arr = {5,4,1};
    cout<<sortedArrRot(arr)<<endl;


    // Recording the ending time
    auto end = chrono::high_resolution_clock::now();
    // Calculating the duration
    chrono::duration<double> duration = end - start;
    // Printing the execution time
    cout << "\nExecution time: " << duration.count() << " seconds" << std::endl;

    return 0;
}