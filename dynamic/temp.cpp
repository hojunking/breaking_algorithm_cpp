#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int Max;

int bin5(int n, int k){
    
    vector<int>B(n+1,0);
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

int binom(int n, int k)
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

int bin3(int n, int k){
    if(k > n /2)
        k = n -k;
    vector<int> B(k+1,0);
    B[0]=1;
    for(int i =1; i < n+1; i++){
        int j = min(i,k);
        while(j > 0){
            B[j] = (B[j] + B[j -1]) % Max;
           // cout << B[j] <<" ";
            j--;
        }
        //cout << "\n";
    }
    return B[k];
}


int main(void){
    int n, k;
    cin >> n >> k >> Max;
    cout << bin3(n, k) <<"\n";
}