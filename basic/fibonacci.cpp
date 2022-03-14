#include <iostream>
using namespace std;

typedef unsigned long long Int;

Int fib(Int n, Int max){
    if (n <= 1)
        return n;
    Int a=1, b=1,temp;
    for(Int i =2; i<n; i++){
        temp = (a+b) % max;
        a= b;
        b = temp;
    }
    return b;
}

int main(){
    Int n, max;
    cin >> n >> max;
    cout << fib(n,max);
}