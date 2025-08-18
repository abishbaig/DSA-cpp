#include <iostream>
#include <chrono>
using namespace std;

// To find the Largest Element in an array : T.C = O(n) - S.C = O(1)
int maxElement(int arr[], int size){
    // Greedy
    int max = arr[0];
    for(int i = 1;i<size;i++){
        if(max<arr[i]){
            max = arr[i];
        }
    }
    return max;
}

// Function for precomputing an Hash Array : T.C = O(n) - S.C = O(n) where 'n' = Size of Hash Array
int* Hash(int arr[], int size){
    int max_elmnt = maxElement(arr,size);
    // Initializing Hash Array of Array's Max Element Size and Initializing All Elements with 0
    int* hash = new int[max_elmnt+1]{0};
    
    
    // Precomputing Step
    for(int i = 0;i<size;i++){
        hash[arr[i]]++;
    }
    return hash;
}

int main(){
    // Recording the starting time
    auto start = chrono::high_resolution_clock::now();

    // Actual Code Logic
    int arr[5] = {1,2,1,3,4};
    int* hash = Hash(arr,5);

    // Storing and Fetching T.C = O(1)
    cout<<hash[1]<<endl;

    
    // Recording the ending time
    auto end = chrono::high_resolution_clock::now();
    // Calculating the duration
    chrono::duration<double> duration = end - start;
    // Printing the execution time
    cout << "\nExecution time: " << duration.count() << " seconds" << std::endl;
    delete[] hash;

    return 0;
}