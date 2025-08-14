#include <iostream>
#include <math.h>
using namespace std;

// Brute Force : T.C = O(n) - S.C = O(1)
void divisors1(int num){
    for(int i = 1; i<=num;i++){
        if(num%i == 0){
            cout<<i<<", ";
        }
    }
}

// Optimal Approach : T.C = O(sqrt(n)) - S.C = O(1)
void divisors2(int num){
    for(int i = 1;i<=sqrt(num);i++){
        if(num%i==0){
            cout<<i<<", ";
            if(i!=(num/i)){
                cout<<num/i<<", ";
            }
        }
    }
}

int main(){
    divisors2(36);
    cout<<endl;
    return 0;
}