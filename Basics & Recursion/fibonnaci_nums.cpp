#include <iostream>
using namespace std;

// Space Optimized Approach - Iterative Approach : T.C = O(n) - S.C = O(1)
int fib1(int fib_SeqNum){
    // As Fib(0) or Fib(1) already known
    if(fib_SeqNum<=1){
        return fib_SeqNum;
    }
    
    // Initializing f(0) as p1 = 0 and f(1) as p2 = 1 and fibRes to store result
    int p1 = 0, p2 = 1, fibRes = 0;
    // Starting from 2 as previous 2 fibNums are already known
    for(int i = 2;i<=fib_SeqNum;i++){
        // Logic
        fibRes = p1 + p2;
        p1 = p2;
        p2 = fibRes;
    }
    return fibRes;
}

// Recursive Approach : T.C = O(2^n) {Height of Binary Tree} - S.C = O(n) {Depth of Binary Tree}
int fib2(int fib_SeqNum){
    // Base Case
    if(fib_SeqNum<=1){
        return fib_SeqNum;
    }
    else{
        // Formula to Calculate: Fib(n) = Fib(n-1) + Fib(n-2)
        return fib2(fib_SeqNum-1) + fib2(fib_SeqNum-2);
    }
}


// DP(Naive) Approach - Auxilary Array : T.C = O(n) - S.C = O(n)
int fib3(int fib_SeqNum){
    // As Fib(0) or Fib(1) already known
    if(fib_SeqNum<=1){
        return fib_SeqNum;
    }
    // Initializing an Auxilary Array to Store Fib(n)
    int* fib = new int[fib_SeqNum+1];
    fib[0] = 0;
    fib[1] = 1;
    // Using Formula to Calculate and Store Each Fib Number Result in Array
    for(int i = 2;i<=fib_SeqNum;i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    return fib[fib_SeqNum];
}




int main(){
    cout<<fib3(4)<<endl;
    return 0;
}