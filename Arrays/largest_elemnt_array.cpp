#include <iostream>
#include <chrono>
using namespace std;

// Greedy Approach: T.C = O(n) - S.C = O(1)
int largestElement1(int arr[], int size){
    int maxNum = arr[0];
    for(int i = 1;i<size;i++){
        if(maxNum<arr[i]){
            maxNum = arr[i];
        }
    }
    return maxNum;
}

// Recursive Greedy Approach - T.C = O(n) - S.C = O(n)
int largestElement2(int arr[], int n, int size, int maxNum){
    if(n>=size){
        return maxNum;
    }
    else if(maxNum<arr[n]){
        maxNum = arr[n];
    }
    return largestElement2(arr,n+1,size,maxNum);
}

int main(){
    // Recording the starting time
    auto start = chrono::high_resolution_clock::now();

    // Actual Code Logic
    int arr[5] = {1,2,3,4,5};
    cout<<largestElement2(arr,1,5,arr[0])<<endl;

    // Recording the ending time
    auto end = chrono::high_resolution_clock::now();
    // Calculating the duration
    chrono::duration<double> duration = end - start;
    // Printing the execution time
    cout << "\nExecution time: " << duration.count() << " seconds" << std::endl;

    return 0;
}