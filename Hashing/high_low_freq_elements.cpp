#include <iostream>
#include <chrono>
#include <unordered_map>
#include <vector>
using namespace std;


// Brute Force Approach: T.C = O(n^2) - S.C = O(n)
void high_low_freq(int arr[], int size){
    // Initializing Variables
    int high_freq = 1,low_freq = 1, high = 0, low = 0;
    // Initializing an Boolean Array for Storing Already Visited Indexes Status
    bool visited[size] = {false};

    for(int i = 0;i<size;i++){
        // Skipping if Already Processed
        if(visited[i] == true){
            continue;
        }
        
        int cnt=1;
        // Checking if that Element is Repeated in Array or not
        for(int j = i+1;j<size;j++){
            if(arr[i] == arr[j]){
                visited[j] = true;
                cnt++;        
            }
        }

        // Checking Logic
        if(cnt>high_freq){
            high = arr[i];
            high_freq = cnt;
        }
        if(cnt<=low_freq){
            low = arr[i];
            low_freq = cnt;
        }
        //visited[i] = true;
    }

    cout<<"High Frequency Element : "<<high<<endl;
    cout<<"Low Frequency Element : "<<low<<endl;

}

// Optimized Approach - Hashmap : T.C = O(n) - S.C = O(n)
unordered_map<int,int> hashArr(int arr[], int size){
    unordered_map<int,int> hashmap;
    for(int i = 0;i<size;i++){
        hashmap[arr[i]]++;
    }
    return hashmap;
}

void high_low_freq(unordered_map<int,int> hashmap){
     // Initializing Variables
    int high_freq = 1,low_freq = 1, high = 0, low = 0;

    // Iterating through Map and Only Checking Precomputed Frequency Values
    for(auto element: hashmap){
        int count = element.second;
        if(count>high_freq){
            high_freq = count;
            high = element.first;
        }
        if(count<=low_freq){
            low_freq = count;
            low = element.first;
        }
    }

    cout<<"High Frequency Element : "<<high<<endl;
    cout<<"Low Frequency Element : "<<low<<endl;

}


int main(){
    // Recording the starting time
    auto start = chrono::high_resolution_clock::now();

    // Actual Code Logic
    int arr[5] = {10,5,15,10,5};
    //high_low_freq(arr,5);
    high_low_freq(hashArr(arr,5));
    


    // Recording the ending time
    auto end = chrono::high_resolution_clock::now();
    // Calculating the duration
    chrono::duration<double> duration = end - start;
    // Printing the execution time
    cout << "\nExecution time: " << duration.count() << " seconds" << std::endl;

    return 0;
}