#include <iostream>
#include <chrono>
#include <vector>
#include <climits>
using namespace std;


// Brute Force Approach: T.C = O(n) - S.C = O(1)
// Finding Minimum Element and its Index = K-Rotations before Sorted Array
int findRotations1(vector<int>& arr){
    int ans = INT_MAX, index = -1;
    for(int i = 0;i<arr.size();i++){
        if(ans > arr[i]){
            ans = arr[i];
            index = i;
        }
    }
    cout<<ans<<endl;
    return index;
}

// Optimal Approach: Using Binary Search + Minimum Element Logic: T.C = O(logN) - S.C = O(1)
int findRotations2(vector<int>& arr){
    int start = 0, end = arr.size()-1, ans = INT_MAX, index = -1;
    // Binary Search Logic
    while(start<=end){
        int mid = (start+end)/2;
        // Array Already Sorted so 1st Element is Minimum
        if(arr[start] <= arr[end]){
            if(arr[start]<ans){
                ans = arr[start];
                index = start;
            }
            break;
        }

        // Other Than, If Left Part is Sorted so Check if Ans is > arr[start] and update and Eliminate Left Part
        if(arr[start]<=arr[mid]){
            if(arr[start]<ans){
                ans = arr[start];
                index = start;
            }
            // Elimination Step
            start = mid + 1;
        }
        // Else if Right Part is Sorted So Check is Ans > arr[mid] and update and Eliminate Right Part
        else{
            if(arr[mid] < ans){
                ans = arr[mid];
                index = mid;
            }
            // Elimination Part
            end = mid - 1;
        }
    }
    return index;
}

int main(){
    // Recording the starting time
    auto start = chrono::high_resolution_clock::now();

    // Actual Code Logic
    vector<int> arr = {5,4,3,2,1};
    cout<<findRotations2(arr)<<endl;    

    // Recording the ending time
    auto end = chrono::high_resolution_clock::now();
    // Calculating the duration
    chrono::duration<double> duration = end - start;
    // Printing the execution time
    cout << "\nExecution time: " << duration.count() << " seconds" << std::endl;

    return 0;
}