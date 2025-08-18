#include <iostream>
#include <chrono>
#include <unordered_map>
#include <vector>
using namespace std;

// Brute Force : T.C = O(N^2) - S.C = O(N)
void countFreq(int arr[], int n)
{
    vector<bool> visited(n, false);
 
    for (int i = 0; i < n; i++) {
        // Skip this element if already processed
        if (visited[i] == true)
            continue;
 
        // Count frequency
        int count = 1;
        // Starting from i+1 becoz initial count = 1 already
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                visited[j] = true;
                count++;
            }
        }
        cout << arr[i] << " " << count << endl;
    }
}

// Optimal Approach - Maps : T.C = O(N) - S.C = O(N)
void frequency(int arr[], int size){
    // Initializing an Map
    unordered_map<int,int> frqs;
    // Precomputing Step
    for(int i = 0;i<size;i++){
        frqs[arr[i]]++;
    }

    // Displaying Frequencies
    for(auto x: frqs){
        cout<<x.first<<" : "<<x.second<<endl;
    }
}

int main(){
    // Recording the starting time
    auto start = chrono::high_resolution_clock::now();

    // Actual Code Logic
    int arr[5] = {1,2,1,3,4};
    int size = sizeof(arr)/sizeof(arr[0]);
    frequency(arr,size);

    // Recording the ending time
    auto end = chrono::high_resolution_clock::now();
    // Calculating the duration
    chrono::duration<double> duration = end - start;
    // Printing the execution time
    cout << "\nExecution time: " << duration.count() << " seconds" << std::endl;

    return 0;
}