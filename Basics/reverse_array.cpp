#include <iostream>
#include <algorithm>
using namespace std;

// Brute Force with Auxilary Array : T.C = O(n) - S.C = O(n)
int* reverseArray1(int arr[], int size){
    // If Array is empty return the same Array
    if(size <= 0){
        return arr;
    }
    // Initialzing an Auxilary Array with size of original array
    int *revArr = new int[size];
    // Looping from Backward of Original Array and Inserting Elements from Starting Index of Auxilary Array
    for(int i = size-1;i>=0;i--){
        // size = 5, i = 4, Index = 5-4-1 = 0
        // size = 5, i = 3, Index = 5-3-1 = 1
        // size = 5, i = 2, Index = 5-2-1 = 2
        // size = 5, i = 1, Index = 5-1-1 = 3
        // size = 5, i = 0, Index = 5-0-1 = 4

        revArr[size-i-1] = arr[i];
    }
    return revArr;
}


// Space Optimized Approach - 2 Pointer Approach : T.C =O(n) - S.C = O(1)
int* reverseArray2(int arr[], int size){
    // Intializing Pointers
    int p1 = 0, p2 = size-1;

    // Iterating While P1 < P2
    while(p1<p2){
        swap(arr[p1],arr[p2]);
        p1++;
        p2--;
    }
    return arr;
}


// Recursive Approach : T.C = O(n) - S.C = O(n)
int* reverseArray3(int arr[], int start, int end){
    // Function Base Case while Start < End
    if(start>=end){
        return arr;
    }
    swap(arr[start],arr[end]);
    /* Don't start++ or end-- as they are Local Vars and 
    Increment and Decrement Opt. works on their memory 
    but with each fucntion call the memory is rewritten 
    and again initialized to their actual passed values/argurments
    */
    return reverseArray3(arr,start+1,end-1);
}


// Inbuilt Library Reverse Approach: T.C = O(n) - S.C = O(1)
int* reverseArray4(int arr[], int size){
    reverse(arr,arr+size);
    return arr;
}


// Function for Printing an Array - Read Only
void printArray(int arr[], int size){
    for(int i = 0; i<size;i++){
        cout<<arr[i]<<", ";
    }
    cout<<endl;
}



int main(){
    int arr[5] = {5,4,3,2,1};
    printArray(arr,5);
    printArray(reverseArray4(arr,5),5);
    return 0;
}