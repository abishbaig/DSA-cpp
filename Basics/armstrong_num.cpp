#include <iostream>
using namespace std;

// Function to Calculate Power of Integers as Cmath Power Function gives round off answers dealing in doubles datatype
int pow(int x, int y){
    int power = 1;
    for (int i = 1; i<=y;i++){
        power *= x;
    }
    return power;
}

bool armstrong(int num){
    /* Digits to Store Num of Digits in Number and 
    Sum to Store Sum Raised to Power of Digits on each Individual Digit*/

    int digits = 0, sum = 0;
    int temp_num = num;
    
    // Implemented Reverse Number Logic to Count Digits
    while(temp_num!=0){
        digits++;
        temp_num /= 10;
    }

    cout << digits<<endl;
    // Implemented Reverse Number Logic to Calculate Sum
    temp_num = num;
    while(temp_num!=0){
        sum += pow(temp_num%10,digits);
        temp_num /= 10;
    }
    cout<<sum<<endl;

    // Checking If Number is Armstrong by Comparing Sum with Actual Number
    if(sum == num){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    cout<<armstrong(153)<<endl;
    return 0;
}