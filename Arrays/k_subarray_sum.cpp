#include <iostream>
#include <chrono>
#include <vector>
#include <unordered_map>
using namespace std;

// Better Approach: T.C = O(N^2) - S.C = O(1)
int k_SubArraySum1(vector<int>& arr, int k){
    if(arr.size() == 0) return 0;
    // Intialzing Counter var
    int count = 0;
    int sum = 0;
    for(int i = 0;i<arr.size();i++){
        sum = 0;
        for(int j = i;j<arr.size();j++){
            // Current Sum = Sum of Previous Subarray
            sum += arr[j];
            // If Sum of an Subarray == k then count++
            count += 1?sum == k:count;
        }
    }
    return count;
}

// Optimal Approach: T.C = O() - S.C = O()
int k_SubArraySum2(vector<int>& arr, int k){
    if(arr.size() == 0) return 0;

    unordered_map<int,int> map;
    map[0] = 1;
    int prefixSum = 0, cnt = 0;
    for(int i = 0;i<arr.size();i++){
        prefixSum += arr[i];
        int remove = prefixSum - k;
        cnt += map[remove];
        map[prefixSum] += 1;
    }
    return cnt;
}

int main(){
    // Recording the starting time
    auto start = chrono::high_resolution_clock::now();

    // Actual Code Logic
    vector<int> arr = {1,1,1};
    cout<<k_SubArraySum2(arr,2)<<endl;

    // Recording the ending time
    auto end = chrono::high_resolution_clock::now();
    // Calculating the duration
    chrono::duration<double> duration = end - start;
    // Printing the execution time
    cout << "\nExecution time: " << duration.count() << " seconds" << std::endl;

    return 0;
}