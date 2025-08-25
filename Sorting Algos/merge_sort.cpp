#include <iostream>
#include <chrono>
#include <vector>
using namespace std;


// Merge Logic
void merge(vector<int>& arr, int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid+1;

    // Putting Elements in Temp Array in Sorted Fashion
    while(left<=mid && right<=high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    // Putting all Remaining Elements 1st Left and then Right coz already sorted now
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }

    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }

    // Placement in Actual Array
    for(int i = low;i<=high;i++){
        arr[i] = temp[i-low];
    }
}

// Merge Sort : T.C = O(nlogn) - S.C = O(n)
void mergeSort(vector<int>& arr, int low, int high){
    // Base Case
    if(low>=high){
        return;
    }
    int mid = ((low+high)/2);
    // Left Subarray
    mergeSort(arr,low,mid);
    // Right Subarray
    mergeSort(arr,mid+1,high);
    // Merging Sub-Arrays
    merge(arr,low,mid,high);
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
    mergeSort(arr,0,arr.size()-1);
    printArr(arr);

    // Recording the ending time
    auto end = chrono::high_resolution_clock::now();
    // Calculating the duration
    chrono::duration<double> duration = end - start;
    // Printing the execution time
    cout << "\nExecution time: " << duration.count() << " seconds" << std::endl;

    return 0;
}