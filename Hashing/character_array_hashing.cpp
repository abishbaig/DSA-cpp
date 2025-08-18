#include <iostream>
#include <chrono>
#include <vector>
using namespace std;


// Precomputing Function for lower Case
int* lowerCsHash(string& s){
    // 26 Aplhabets
    int* hash = new int[26]{0};

    // Precompute Logic : alphabet - 'a' = Position 
    for(int i = 0;i<s.size();i++){
        hash[s[i]-'a']++;
    }
    return hash;
}


// Precomputing Function for Upper Case
int* UpperCsHash(string& s){
    // 26 Aplhabets
    int* hash = new int[26]{0};

    // Precompute Logic : alphabet - 'A' = Position 
    for(int i = 0;i<s.size();i++){
        hash[s[i]-'A']++;
    }
    return hash;
}

// Precomputing Function for Both Cases
int* CharHash(string& s){
    /*
    Total ASCII CHARS = 256
    Standard = 0-127
    Extended = 128 - 255
    */  
    int* hash = new int[256]{0};

    // Precompute Logic: Simple Storing Index of CHaracter acc. to ASCII Values (INT)
    for(int i = 0;i<s.size();i++){
        hash[s[i]]++;
    }
    return hash;
}


int main(){
    // Recording the starting time
    auto start = chrono::high_resolution_clock::now();

    // Actual Code Logic
    string s1 = "abishbaig";
    string s2 = "ABISHBAIG";
    string s3 = "Abish Baig";

    int* lowerHash = lowerCsHash(s1);
    int* upperHash = UpperCsHash(s2);
    int* charHash = CharHash(s3);

    // Fetching : T.C = O(1)
    cout<<lowerHash['s'-'a']<<endl;
    cout<<upperHash['H'-'A']<<endl;
    cout<<charHash['i']<<endl;

    // Recording the ending time
    auto end = chrono::high_resolution_clock::now();
    // Calculating the duration
    chrono::duration<double> duration = end - start;
    // Printing the execution time
    cout << "\nExecution time: " << duration.count() << " seconds" << std::endl;



    return 0;
}