#include <iostream>
#include <chrono>
#include <unordered_map>
#include <algorithm>
using namespace std;

// K-Operations Logic
void k_opt(int arr[], int size, int k_operations){
    int max = *(max_element(arr,arr+size));
    int j = 0;
    while(k_operations>0){
        if(max == arr[j]){
            j++;
            continue;
        }
        if(j >= size){
            break;
        }
        int complement = max - arr[j];
        if(complement > 0){
            arr[j] += 1;
            k_operations--;
        }
        else{
            j++;
        }
    }
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
    }

    cout<<"High Frequency Element : "<<high<<endl;
    cout<<"High Frequency         : "<<high_freq<<endl;
}


int main(){
    // Recording the starting time
    auto start = chrono::high_resolution_clock::now();

    // Actual Code Logic
    int arr[5] = {1,2,4};
    k_opt(arr,3,5);
    high_low_freq(hashArr(arr,5));

    // Recording the ending time
    auto end = chrono::high_resolution_clock::now();
    // Calculating the duration
    chrono::duration<double> duration = end - start;
    // Printing the execution time
    cout << "\nExecution time: " << duration.count() << " seconds" << std::endl;

    return 0;
}