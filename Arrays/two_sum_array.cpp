#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Better Approach: HashMap: T.C = O(n) - S.C = O(n)
vector<int> twoSum1(vector<int>& arr, int target){
    // Unordered Map for Storing Key as Array ELement and Value as its Index
    unordered_map<int,int> map;

    for(int i = 0;i<arr.size();i++){
        // Storing Value of Current Index
        int num = arr[i];
        // Missing Value whose sum with the Num = Target
        int complementVal = target - num;
        
        // map.find() returns Iterator and if that iterator is not equal to the end iterator of map then key is found
        if(map.find(complementVal) != map.end()){
            return {map[complementVal],i};
        }

        // Else store the element in map with its index
        map[num] = i;
    }

    // In case not found
    return {-1,-1};
}


// Optimal Approach: 2 Pointer: T.C = O(nlogn) - S.C = O(1)
//Logic Only Works for Sorted Array
vector<int> twoSum2(vector<int>& arr, int target){
    // Sorting the array first
    sort(arr.begin(),arr.end());

    // Initializing pointers
    int p1 = 0, p2 = arr.size()-1;
    
    // Logic
    while(p1<p2){
        /* If Sum of both pointers Values = Target
        Else if Sum > target means the p2 has to decrement as value must be low
        Else if Sum < target means the p1 has to increment as value must be high*/
        if(arr[p1] + arr[p2] == target){
            return {p1,p2};
        }
        else if(arr[p1] + arr[p2] > target){
            p2--;
        }
        else if(arr[p1] + arr[p2] < target){
            p1++;
        }
    }
    return {-1,-1};
}


int main(){
    // Recording the starting time
    auto start = chrono::high_resolution_clock::now();

    // Actual Code Logic
    vector<int> arr = {3,2,4};
    int target = 6;

    cout<<twoSum2(arr,target)[0]<<", "<<twoSum2(arr,target)[1]<<endl;


    // Recording the ending time
    auto end = chrono::high_resolution_clock::now();
    // Calculating the duration
    chrono::duration<double> duration = end - start;
    // Printing the execution time
    cout << "\nExecution time: " << duration.count() << " seconds" << std::endl;

    return 0;
}