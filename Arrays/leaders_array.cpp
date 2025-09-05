#include <iostream>
#include <chrono>
#include <vector>
using namespace std;

// Optimal Approach: T.C = O(n) - S.C = O(1)
vector<int> leaders(vector<int>& arr){
    
    vector<int> leads;
    
    // Rightmost element is always a leader
    int max = arr[arr.size()-1];
    leads.push_back(max);

    // Starting from last till start of array and checking if a element is greater than the pre-stored max element then it is a leader
    for(int i = arr.size()-2;i>=0;i--){
        if(arr[i]>max){
            leads.push_back(arr[i]);
            max = arr[i];
        }
    }
    
    return leads;
}


void printArr(vector<int> arr){
    for(int i = arr.size()-1;i>=0;i--){
        cout<<arr[i]<<", ";
    }
    cout<<endl;
}

int main(){
    // Recording the starting time
    auto start = chrono::high_resolution_clock::now();

    // Actual Code Logic
    vector<int> arr = {4,7,1,0};
    printArr(leaders(arr));

    // Recording the ending time
    auto end = chrono::high_resolution_clock::now();
    // Calculating the duration
    chrono::duration<double> duration = end - start;
    // Printing the execution time
    cout << "\nExecution time: " << duration.count() << " seconds" << std::endl;

    return 0;
}