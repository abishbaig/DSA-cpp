#include <iostream>
#include <chrono>
#include <vector>
using namespace std;

// Linear Search: T.C = O(n) - S.C = O(1)
int linearSearch(vector<int>& arr, int key){
    for(int i = 0;i<arr.size();i++){
        if(key == arr[i]){
            return i;
        }
    }
    // Indicates not Found
    return -1;
}

int main(){
    // Recording the starting time
    auto start = chrono::high_resolution_clock::now();

    // Actual Code Logic
    vector<int> arr = {1,2,3,4,5};
    int key = 4;
    cout<<"Key Found at Index: "<<linearSearch(arr,key)<<endl;

    // Recording the ending time
    auto end = chrono::high_resolution_clock::now();
    // Calculating the duration
    chrono::duration<double> duration = end - start;
    // Printing the execution time
    cout << "\nExecution time: " << duration.count() << " seconds" << std::endl;

    return 0;
}