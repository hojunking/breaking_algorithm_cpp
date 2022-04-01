#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long LongInteger;

int Max;


LongInteger bin2(int n, int k){ //tabulization
    if(k > n /2)
        k = n -k;
        
    vector<vector<LongInteger>> B(n + 1, vector<LongInteger>(n + 1));
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= min(i, k); j++)
            if (j == 0 || j == i)
                B[i][j] = 1;
            else
                B[i][j] = (B[i - 1][j] + B[i - 1][j - 1]) % Max;
   
    for(int i = 0; i<= n; i++){
        for(int j =0; j<=min(i, k) ;j++){
            cout << B[i][j] << " ";
        }
    cout << "\n";
    }

    return B[n][k];
}


LongInteger bin3(int n, int k){
    if(k > n /2)
        k = n -k;
    vector<LongInteger> B(k+1,0);
    B[0]=1;

    for(int i =1; i < n+1; i++){
        int j = min(i,k);
        while(j > 1){
            B[j] = (B[j] + B[j -1]) % Max;
            cout << B[j] <<" ";
            j--;
        }
        B[j] = i;
        cout << "\n";
    }
    return B[k];
}

LongInteger bin4(int n, int k){
    
    vector<LongInteger> B(n+1,0);
    
    for(int i =0; i<=n; i++){
        for(int j = i; j >=0; j--){
            if(j ==0 || j ==i)
                B[j] = 1;
            else
                B[j] = (B[j] + B[j-1]) % Max;
        }
    }
    return B[k];
}


int main(void){
    int n, k;
    cin >> n >> k >> Max;
    cout << bin3(n, k) <<"\n";
    //cout << bin2(n, k) <<"\n";
}