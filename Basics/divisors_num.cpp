#include <iostream>
using namespace std;

// Brute Force : T.C = O(n) - S.C = O(1)
void divisors(int num){
    for(int i = 1; i<=num;i++){
        if(num%i == 0){
            cout<<i<<", ";
        }
    }
}

int main(){
    divisors(36);
    cout<<endl;
    return 0;
}