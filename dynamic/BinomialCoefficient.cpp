// 이항계수 최적화 플로이드 아이고 감사합니다.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long LongInteger; //Maxsize module 계산 시 LongInteger는 필요없다...

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
        while(j > 0){
            B[j] = (B[j] + B[j -1]) % Max;
            cout << B[j] <<" ";
            j--;
        }
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

LongInteger bin5(int n, int k){ 
    
    vector<LongInteger>B(n+1,0);
    if(k > n /2)
        k = n -k;
    B[0] = 1;
    
    for(int i =0; i <= n-k; i++ ){
        int j = min(i,k);
        
        while(j > 0){
            B[j] = (B[j] + B[j -1]) % Max;
            //cout << B[j] << " ";
            j--;
        }
        //cout << B[j] << " ";
        //cout << "\n";
    }

    int prev =0, preprev = 1;
    for(int i =n-k; i <= n; i++){
        
        int j =i-n+k+1;

        preprev = B[j-1];
        while(j != k+1){
            prev = B[j];
            B[j] = (B[j] + preprev) % Max;
            preprev = prev;
            //cout << B[j] <<"' ";
            j++;
        }
    //cout << "\n";
    }
    return B[k];
}

int bino6(int n, int k)
{
    vector<int>B(n+1,0);
   
   for (int i = 0; i <= n; i++)
   {
      int prev = 0, preprev = 1;
      for (int j = 0; j <= min(i,k); j++)
      {
         if (j == 0 || j == i)
            B[j] = 1;
         else
         {
            prev = B[j];
            B[j] = (B[j] + preprev) % Max;
            preprev = prev;
         }
      }
   }
   return B[k];
}



int main(void){
    int n, k;
    cin >> n >> k >> Max;
    cout << bin4(n, k) <<"\n";

}