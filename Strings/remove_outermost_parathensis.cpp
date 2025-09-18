#include <iostream>
#include <chrono>
#include <vector>
using namespace std;


// Optmial Approach: T.C = O(n) - S.C = O(1)
// Finding Depth in between ( - ), as depth will be zero from starting bracket and will become zero at ending bracket as given is balanced parenthesis
string removeOuterParentheses(string s) {
    string newStr = "";
    int depth = 0;
    for(char c: s){
        if(c == '('){
            if(depth > 0) newStr += c;
            depth++;
        }
        else{
            depth--;
            if(depth>0) newStr += c;
        }
    }
    return newStr;
}


int main(){
    // Recording the starting time
    auto start = chrono::high_resolution_clock::now();

    // Actual Code Logic
    string str = "(()())(())";
    cout<<removeOuterParentheses(str)<<endl;

    // Recording the ending time
    auto end = chrono::high_resolution_clock::now();
    // Calculating the duration
    chrono::duration<double> duration = end - start;
    // Printing the execution time
    cout << "\nExecution time: " << duration.count() << " seconds" << std::endl;

    return 0;
}