#include <iostream>
using namespace std;

/* Optimal Approach : T.C = O(1) - S.C = O(1)
Formula = (n(n+1))/2
Eg: N = 5
Sum = (5(5+1))/2 = (30/2) = 15
*/
int sumofN1(int num){
    int sum = ((num*(num+1))/2);
    return sum;
}

// Functional Recursive Approach: T.C = O(n) - S.C = O(n)
// As SumofNaturalNumbers(N) = N + SumofNaturalNumbers(N-1)
int sumofN2(int num){
    if(num == 0){    
        return 0;
    }
    return num + sumofN2(num-1);
}

int main(){
    cout<<sumofN2(5)<<endl;
    return 0;
}