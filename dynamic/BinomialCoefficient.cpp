#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long LongInteger;

int Max;
LongInteger bin2(int n, int k){ //tabulization
   vector<LongInteger>;
    
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= min(i, k); j++)
            if (j == 0 || j == i)
                B[i][j] = 1;
            else
                B[i][j] = (B[i - 1][j] + B[i - 1][j - 1]) % Max;
    return B[n][k];
}

int main(void){
    int n, k;
    cin >> n >> k >> Max;
    cout << bin2(n, k) <<"\n";
}