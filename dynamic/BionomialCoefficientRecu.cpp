#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long LongInteger;

int Max;

 LongInteger bin(int n, int k){ //memoization
     if(k == 0 || n == k)
        return 1; 
     else return (bin(n-1,k) + bin(n-1,k-1)) % Max;
     //(n, k) = (n-1,k-1) + (n-1, k)
     // -> B[i-1][j-1] + b[i-1][j] = b[i][j]
 }

int main(void){
    int n, k;
    cin >> n >> k >> Max;
    cout << bin(n, k) <<"\n";
}