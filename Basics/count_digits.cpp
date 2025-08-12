#include <iostream>
using namespace std;

int countDigits(int num){
    int digitCount = 0;
    while(num!=0){
        digitCount++;
        num /= 10;
    }
    return digitCount;
}

int main(){
    cout<<countDigits(1234)<<endl;
    return 0;
}