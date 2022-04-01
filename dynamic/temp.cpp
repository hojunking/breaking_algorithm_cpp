#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long LongInteger;

int Max;

LongInteger bin3(int n, int k){
    if(k > n /2)
        k = n -k;
    vector<LongInteger> B(k+1,0);
    B[0]=1;

    for(int i =1; i < n+1; i++){
        int j = min(i,k);
        while(j > 1){
            B[j] = (B[j] + B[j -1]) % Max;
            j--;
        }
        B[j] = i;
    }
    return B[k];
}


int main(void) {
    int n, k;
    cin >> n >> k >> Max;
    cout << bin3(n, k) << "\n";
}