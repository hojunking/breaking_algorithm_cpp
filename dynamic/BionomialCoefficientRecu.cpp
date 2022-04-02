//이항계수 재귀구현

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long LongInteger;  //Maxsize module 계산 시 LongInteger는 필요없다...

int Max;

LongInteger bin(int n, int k){ //memoization
     if(k == 0 || n == k)
        return 1; 
     else return (bin(n-1,k) + bin(n-1,k-1)) % Max;
     //(n, k) = (n-1,k-1) + (n-1, k)
     // -> B[i-1][j-1] + b[i-1][j] = b[i][j]
}

int bino1(int n, int k) // c코드입니다.
{
   if (k == 0 || k == n)
      B[n][k] = 1;
   else
   {
      // B[n][k]가 계산 되었으면, F[n]을  -> -1인가, 아닌가?
      // -1 이면 재귀호출, 아니면 연산
      if (B[n][k] == -1)
         B[n][k] = bino(n - 1, k - 1) + bino(n - 1, k);
      else
         B[n][k] = B[n - 1][k - 1] + B[n - 1][k];
   }
   return B[n][k];
}

int main(void){
    int n, k;
    cin >> n >> k >> Max;
    cout << bin(n, k) <<"\n";
}