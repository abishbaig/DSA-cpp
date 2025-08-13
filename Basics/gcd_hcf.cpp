#include<iostream>
using namespace std;

// Brute Force Solution : T.C = O(min(n1,n2))
int gcd_hcf_1(int n1, int n2){
    int gcd = 1;
    int minNum = min(n1,n2);
    for(int i = 2;i<=minNum;i++){
        if(n1%i==0 && n2%i==0){
            gcd = i;
        }
    }
    return gcd;
}

// Better Approach : T.C = O(min(n1,n2)) {Fewer Iterations in Practice}
int gcd_hcf_2(int n1,int n2){
    int gcd = 1;
    int minNum = min(n1,n2);
    for(int i = minNum;i>=2;i--){
        if(n1%i==0 && n2%i==0){
            gcd = i;
        }
    }
    return gcd;
}

// Optimal Approach : Recursive Version : T.C = O(min(n1,n2))
int gcd_hcf_3(int n1, int n2){
    if(n1 == 0 && n2 != 0){
        return n2;
    }
    else if(n2 == 0 && n1 != 0){
        return n1;
    }
    else if(n1 == 1 || n2 == 1){
        return 1;
    }
    else{
        if(n1>n2){
            return gcd_hcf_3(n1-n2,n2);
        }
        else if(n2>n1){
            return gcd_hcf_3(n2-n1,n1);
        }
    }
}
// Optimal Approach : Iterative Version : T.C = O(min(n1,n2))
int findGcd(int a, int b) {
    while(a > 0 && b > 0) {
        // If a is greater than b,
        // subtract b from a and update a
        if(a > b) {
             // Update a to the remainder
             // of a divided by b
            a = a % b;
        }
        // If b is greater than or equal
        // to a, subtract a from b and update b
        else {
            // Update b to the remainder
            // of b divided by a
            b = b % a; 
        }
    }
    // Check if a becomes 0,
    // if so, return b as the GCD
    if(a == 0) {
        return b;
    }
    // If a is not 0,
    // return a as the GCD
    return a;
}


int main(){
    cout<<findGcd(20,15)<<endl;
    return 0;
}