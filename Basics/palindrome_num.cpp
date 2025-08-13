#include <iostream>
#include <cmath>
using namespace std;

int reverse(int x) {
        long long revNum = 0;
        while (x != 0) {
            revNum = (x % 10) + (revNum * 10);
            x /= 10;
        }
        int negRange = -(pow(2, 31));
        int posRange = (pow(2, 31)) - 1;
        if (revNum >= negRange && revNum <= posRange) {
            return revNum;
        }
        else {
            return 0;
        }
}

bool isPalindrome(int x) {
    if(x<0){
        return false;
    }
    int reverseNum = reverse(x);
    if(reverseNum == x){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    cout<<isPalindrome(-121);
    return 0;
}