#include <iostream>
#include <chrono>
#include <vector>
using namespace std;

// My Approach: 2 Pointer : T.C = O(n) - S.C = O(1)
int findMaxConsecutiveOnes1(vector<int>& nums) {
    // Initialzing MaxCount and both Pointers with '0'
    int maxCount = 0;
    int p1 = 0, p2 = 0;

    // Iterating while pointer 2 which is fast pointer < size of array
    while(p2<nums.size()){
        /* If both pointers point to 1 in array then checking previous MaxCount value
        and reassigning if it is less than distance of both pointers*/
        if(nums[p1] == 1 && nums[p2] == 1){
            maxCount = max(maxCount,((p2-p1)+1));
            p2++;
        }
        // Else simply incrementing both pointers values
        else{
            p2++;
            p1 = p2;
        }
    }
    return maxCount;
}

// Another Approach: Simple: T.C = O(n) - S.C = O(1)
int findMaxConsecutiveOnes2(vector < int > & nums) {
    int cnt = 0;
    int maxi = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 1) {
        cnt++;
      } else {
        cnt = 0;
      }
      maxi = max(maxi, cnt);
    }
    return maxi;
}



int main(){
    // Recording the starting time
    auto start = chrono::high_resolution_clock::now();

    // Actual Code Logic
    vector<int> arr = {1, 1, 0, 1, 1, 1};
    cout<<findMaxConsecutiveOnes1(arr)<<endl;

    // Recording the ending time
    auto end = chrono::high_resolution_clock::now();
    // Calculating the duration
    chrono::duration<double> duration = end - start;
    // Printing the execution time
    cout << "\nExecution time: " << duration.count() << " seconds" << std::endl;

    return 0;
}