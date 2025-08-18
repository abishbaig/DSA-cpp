#include <iostream>
#include <math.h>
using namespace std;

// Brute Force : T.C = O(n), 0(1) - S.C = O(1)
bool isPrime1(int num){
    bool prime = true;
    // Iterating from 2 <--> (num-1) as every number is divisible by 1 and itself
    for(int i = 2;i<num;i++){
        if(num%i==0){
            prime = false;
            break;
        }
    }
    return prime;
}

// Optimal Approach: T.C = O(sqrt(n)) - S.C = O(1)
bool isPrime2(int num){
    bool prime = true;
    // Iterating from 2 <--> sqrt(num) as Logic Used in Finding Divisors of numbers
    for(int i = 2; i<=sqrt(num);i++){
        if(num%i==0){
            prime = false;
            break;
        }
    }
    return prime;
}

int main(){
    cout<<isPrime2(1)<<endl;
    return 0;
}