#include <iostream>
#include <chrono>
#include <climits>

using namespace std;

// My Approach: Better Approach : T.C = O(n) - S.C = O(1) {2 Traversels}
void second_Max_Min1(int arr[], int size){
    // If range is only 1 or 0 then only max and min present not any 2nd
    if(size <= 1){
        cout<<"2nd Max Element: "<<-1<<endl;
        cout<<"2nd Min Element: "<<-1<<endl;
    }

    // Initializing All Variables
    int maxEl = INT_MIN, minEl = INT_MAX;
    int secondMax = INT_MIN, secondMin = INT_MAX;

    // Finding Max and Min of Array
    for(int i = 0;i<size;i++){
        maxEl = max(maxEl,arr[i]);
        minEl = min(minEl,arr[i]);
    }

    // Finding 2nd Max and Min of Array
    bool maxF = false, minF = false;
    for(int i = 0;i<size;i++){
        if(secondMax<arr[i] && arr[i] != maxEl){
            maxF = true;
            secondMax = arr[i];
        }
        if(secondMin>arr[i] && arr[i] != minEl){
            minF = true;
            secondMin = arr[i];
        }
    }

    // Printing Values
    if(maxF && minF){
        cout<<"2nd Max Element: "<<secondMax<<endl;
        cout<<"2nd Min Element: "<<secondMin<<endl;
    }
    else if(maxF){
        cout<<"2nd Max Element: "<<secondMax<<endl;
        cout<<"2nd Min Element: "<<-1<<endl;
    }
    else if(minF){
        cout<<"2nd Max Element: "<<-1<<endl;
        cout<<"2nd Min Element: "<<secondMin<<endl;
    }
}


// My Approach: Better Approach : T.C = O(n) - S.C = O(1) {1 Traversel}
void second_Max_Min2(int arr[], int size){
    // If range is only 1 or 0 then only max and min present not any 2nd
    if(size <= 1){
        cout<<"2nd Max Element: "<<-1<<endl;
        cout<<"2nd Min Element: "<<-1<<endl;
    }

    // Initializing All Variables
    int maxEl = INT_MIN, minEl = INT_MAX;
    int secondMax = INT_MIN, secondMin = INT_MAX;

    // Finding Max, Min, 2nd Max and 2nd Min of Array
    bool maxF = false, minF = false;
    for(int i = 0;i<size;i++){
        if(arr[i]>maxEl){
            secondMax = maxEl;
            maxEl = arr[i];
        }
        else if(arr[i] > secondMax && arr[i] != maxEl){
            maxF = true;
            secondMax = arr[i];
        }

        if(arr[i]<minEl){
            secondMin = minEl;
            minEl = arr[i];
        }
        else if(arr[i] < secondMin && arr[i] != minEl){
            minF = true;
            secondMin = arr[i];
        }
    }

    // Printing Values
    if(maxF && minF){
        cout<<"2nd Max Element: "<<secondMax<<endl;
        cout<<"2nd Min Element: "<<secondMin<<endl;
    }
    else if(maxF){
        cout<<"2nd Max Element: "<<secondMax<<endl;
        cout<<"2nd Min Element: "<<-1<<endl;
    }
    else if(minF){
        cout<<"2nd Max Element: "<<-1<<endl;
        cout<<"2nd Min Element: "<<secondMin<<endl;
    }
}

int main(){
    // Recording the starting time
    auto start = chrono::high_resolution_clock::now();

    // Actual Code Logic
    int arr[6] = {1,2,4,7,7,5};
    second_Max_Min2(arr,6);

    // Recording the ending time
    auto end = chrono::high_resolution_clock::now();
    // Calculating the duration
    chrono::duration<double> duration = end - start;
    // Printing the execution time
    cout << "\nExecution time: " << duration.count() << " seconds" << std::endl;

    return 0;
}