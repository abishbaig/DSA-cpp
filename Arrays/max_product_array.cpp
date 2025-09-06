#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


// My Approach: 2 Traversels:  T.C = O(N^2) - S.C = O(1)
int maxProduct1(vector<int>& arr){
    int maxProd = 1;
    int localProd = 1;
    int n = arr.size();
    for(int i = 0;i<n;i++){
        localProd = 1;
        for(int j = i;j<n;j++){
            localProd *= arr[j];
            maxProd = max(maxProd,localProd);
        }
    }
    return maxProd;
}

// Optimal Approach 2 using Kadane's Algorithm: T.C = O(n) - S.C = O(1) 
int maxProduct2(vector<int>& arr){
    // Initialzing with 1st Element
    int n = arr.size();
    int prod1 = arr[0];
    int prod2 = arr[0];
    int result = arr[0];

    // Prod1 = Maximum of all Products and Current Element
    // Prod2 = Minimum of all Products and Current Element
    for(int i = 1;i<n;i++){
        int temp = max({arr[i],prod1*arr[i],prod2*arr[i]});
        prod2 = min({arr[i],prod1*arr[i],prod2*arr[i]});
        prod1 = temp;

        result = max(prod1,result);
    }

    return result;
}

// Optimal Approach using Prefix and Suffix Subarrays Computation of Product: T.C = O(n) - S.C = O(1)
int maxProduct3(vector<int>& arr){
    // Initializng Prefix and Suffix Subarray's Product = 1
    int n = arr.size();
    int pre = 1, suff = 1;

    int result = INT_MIN;

    // If prefix or suffix subarrays on computation result in 0, we will restart the subarray product calculation by initialzing them with 1
    for(int i = 0;i<n;i++){
        if(pre == 0) pre = 1;
        if(suff == 0) suff = 1;
        pre *= arr[i]; // From Start
        suff *= arr[n-i-1]; // From End
        
        result = max({result,pre,suff});        
    }
    return result;
}

int main(){
    // Recording the starting time
    auto start = chrono::high_resolution_clock::now();

    // Actual Code Logic
    vector<int> arr = {-3,-1,-1};
    cout<<maxProduct3(arr)<<endl;

    // Recording the ending time
    auto end = chrono::high_resolution_clock::now();
    // Calculating the duration
    chrono::duration<double> duration = end - start;
    // Printing the execution time
    cout << "\nExecution time: " << duration.count() << " seconds" << std::endl;

    return 0;
}