#include <iostream>
#include <chrono>
#include <vector>
#include <stack>
using namespace std;


// Brute Force Approach : Stack : T.C = O(n) - S.C = O(n)
string reverseWords(string s) {
    // Added An Extra Space at End of the Current String due to the logic of code
    s+=" ";
    // Final String
    string result = "";
    stack<string> strStack;
    // Temporay Words Storage String
    string tempStr = "";

    for(char ch: s){
        // If it's an space it means our previous word is completed so push it into stack and again Empt Temp String
        if(ch == ' '){
            strStack.push(tempStr);
            tempStr = "";
        }
        else{
            // Other Wise Pushes Each Character in Temp String
            tempStr += ch;
        }
    }

    // Poping all Stack Words and Adding to Final String
    while(strStack.size() != 1){
        result += strStack.top() + " ";
        strStack.pop();
    }

    result += strStack.top();
    strStack.pop();

    if(result[0] == ' '){
        result.erase(result.begin());
    }
    
    if(result[result.size()-1] == ' '){
        result.erase(result.begin() + result.size()-1);
    }

    return result;
}


int main(){
    // Recording the starting time
    auto start = chrono::high_resolution_clock::now();

    // Actual Code Logic
    string str = " sky is blue ";
    
    cout<<reverseWords(str)<<endl;
    

    // Recording the ending time
    auto end = chrono::high_resolution_clock::now();
    // Calculating the duration
    chrono::duration<double> duration = end - start;
    // Printing the execution time
    cout << "\nExecution time: " << duration.count() << " seconds" << std::endl;

    return 0;
}