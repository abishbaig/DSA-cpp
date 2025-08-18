#include <iostream>
#include<chrono> // For Measuring Execution Time in secs {Extra}
using namespace std;

// 2 Pointer Approach : T.C = O(n) - S.C = O(1)
bool palindrome1(string str){
    // Initializing left and right pointers
    int left = 0, right = str.length()-1;
    // Iterate While Both Pointers don't cross each other or become equal
    while(left<right){
        // Checking if Non-AlphaNumeric
        if(!isalnum(str[left])){
            left++;
        }
        // Checking if Non-AlphaNumeric
        else if(!isalnum(str[right])){
            right--;
        }
        // Checking both characters after lower case conversion for authenticity
        else if(tolower(str[left])!=tolower(str[right])){
            return false;
        }
        else{
            left++;
            right--;
        }
    }
    // All String traversed and Valid Palindrome Detected
    return true;
}

// Recursive Approach : T.C = O(n) - S.C = O(n)
bool palindrome2(string str, int i){
    // If i reaches half of len of str means all elements are traversed and check
    if(i>=(str.length()/2)){
        return true;
    }
    if(tolower(str[i])!=tolower(str[str.length()-i-1])){
        return false;
    }
    return palindrome2(str,i+1);
}


int main(){
    // Recording the starting time
    auto start = chrono::high_resolution_clock::now();
    
    // Actual Code
    cout<<palindrome2("Adda",0);
    
    // Recording the ending time
    auto end = chrono::high_resolution_clock::now();
    
    // Calculating the duration
    chrono::duration<double> duration = end - start;
    
    // Printing the execution time
    cout << "\nExecution time: " << duration.count() << " seconds" << std::endl;


    return 0;
}