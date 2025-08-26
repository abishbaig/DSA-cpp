#include <iostream>
#include <chrono>
#include <vector>
using namespace std;

// Helper Partition Function
int partition(vector<int>& arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    
    while(i<j){
        // Check 1
        while(arr[i]<=pivot && i<=high-1){
            i++;
        }

        // Check 2
        while(arr[j] > pivot && j>=low+1){
            j--;
        }

        if(i<j){
            swap(arr[i],arr[j]);
        }
    }

    swap(arr[low],arr[j]);
    return j;
}

// Quick Sort: Divide and Conquer : T.C = Worst Case = O(n^2) & Best and Avg. Case = O(nlogn) - S.C = O(n) + O(1)
void quickSort(vector<int>& arr, int low, int high){
    // Checking In Range of array
    if(low<high){
        int ptIndex = partition(arr,low,high);

        // Left Sub-Array Sort
        quickSort(arr,low,ptIndex-1);

        // Right Sub-Array Sort
        quickSort(arr,ptIndex+1,high);
    }
}

// Function for Printing Array : T.C = O(n)
void printArr(vector<int> arr){
    for(auto x: arr){
        cout<<x<<", ";
    }
    cout<<endl;
}


int main(){
    // Recording the starting time
    auto start = chrono::high_resolution_clock::now();

    // Actual Code Logic
    vector<int> arr = {5,4,3,2,1};
    quickSort(arr,0,arr.size()-1);
    printArr(arr);

    // Recording the ending time
    auto end = chrono::high_resolution_clock::now();
    // Calculating the duration
    chrono::duration<double> duration = end - start;
    // Printing the execution time
    cout << "\nExecution time: " << duration.count() << " seconds" << std::endl;

    return 0;
}