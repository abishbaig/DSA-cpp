#include <iostream>
#include <chrono>
#include <vector>
#include <climits>
using namespace std;

// Optimal Approach: Single Traversel -> Greedy : T.C = O(n) - S.C = O(1)
int maxProfit(vector<int>& arr){

    int maxProfit = 0, minPrice = INT_MAX;

    // Min Price Start from Global Maxima and Tries to Obtain Global Minima
    // While MaxProfit is Computing Current Element - MinPrice as ith Index should give max. only when arr[i] > arr[minPriceElement]
    for(int i = 0;i<arr.size();i++){
        minPrice = min(minPrice,arr[i]);
        maxProfit = max(maxProfit,arr[i]-minPrice);
    }

    return maxProfit;
}


int main(){
    // Recording the starting time
    auto start = chrono::high_resolution_clock::now();

    // Actual Code Logic
    vector<int> arr = {7,1,5,3,6,4};
    cout<<maxProfit(arr)<<endl;

    // Recording the ending time
    auto end = chrono::high_resolution_clock::now();
    // Calculating the duration
    chrono::duration<double> duration = end - start;
    // Printing the execution time
    cout << "\nExecution time: " << duration.count() << " seconds" << std::endl;

    return 0;
}