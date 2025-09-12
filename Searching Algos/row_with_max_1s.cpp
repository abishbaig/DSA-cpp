#include <iostream>
#include <chrono>
#include <vector>
#include <climits>
using namespace std;


// My Approach: Brute Force Approach : T.C = O(n) - S.C = O(1)
int rowWithMax1s_1(vector<vector<int>>& arr){
    int rowIndex = INT_MAX;
    int globalCount = INT_MIN;
    int prevCount = 0;

    for(int i = 0;i<arr.size();i++){
        // Finding Number of 1s in each row
        int count1 = 0;
        for(int j = 0;j<arr[i].size();j++){
            if(arr[i][j] == 1){
                count1++;
            }
        }
        // Updating Global 1s Count
        globalCount = max(count1,globalCount);
        
        // Finding Row Index
        // If Both Counts same then finding the Min Row Index by Maintaining an PrevCount
        if(globalCount >= count1 && globalCount > prevCount){
            rowIndex = i;
            prevCount = globalCount;
        }

    }
    // If 1s Row Found Returning it else
    return (rowIndex!=INT_MAX?rowIndex:-1);
}

// Better Brute Force: T.C = O(n) - S.C = O(1)
int rowWithMax1s_2(vector<vector<int>>& arr){
    int countMax = 0, index = -1;
    for(int i = 0;i<arr.size();i++){
        // Finding Local Count in Each Row
        int countOne = 0;
        for(int j = 0;j<arr[i].size();j++){
            countOne += arr[i][j];
        }
        // If Local Count > Max Count then update Index and Max Count
        if(countOne > countMax){
            countMax = countOne;
            index = i;
        }
    }
    return index;
}

// My Optimal Approach : T.C = O(nlogn) - S.C = O(1)
int rowWithMax1s_3(vector<vector<int>>& arr){
    int countMax = 0, index = -1;
    
    for(int i = 0;i<arr.size();i++){
        int low = 0, high = arr[i].size()-1;
        int countOne = 0;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[i][mid] >= 1){
                countOne++;
                low = mid + 1;
            }
            else{
                low = mid + 1;
            }
        }
        if(countOne > countMax){
            countMax = countOne;
            index = i;
        }
    }


    return index;
}


// Best Optimal Approach: T.C = O(nlogn) - S.C = O(1)
int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    int cnt_max = 0;
    int index = -1;

    //traverse the rows:
    for (int i = 0; i < n; i++) {
        // get the number of 1's:
        int cnt_ones = m - lowerBound(matrix[i], m, 1);
        if (cnt_ones > cnt_max) {
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index;
}

int main(){
    // Recording the starting time
    auto start = chrono::high_resolution_clock::now();

    // Actual Code Logic
    vector<vector<int>> arr = {
        {0,1,1},
        {0,1,1},
        {1,1,1}
    };

    cout<<rowWithMax1s(arr,3,3)<<endl;

    // Recording the ending time
    auto end = chrono::high_resolution_clock::now();
    // Calculating the duration
    chrono::duration<double> duration = end - start;
    // Printing the execution time
    cout << "\nExecution time: " << duration.count() << " seconds" << std::endl;

    return 0;
}