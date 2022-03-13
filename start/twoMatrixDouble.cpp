
#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int>> matrix_t;

void mult(int n,int k,int m, matrix_t A, matrix_t B,matrix_t& C )
{
   for(int i =1; i<=n; i++){
       for(int j =1; j<=m ; j++){
           C[i][j] =0;
           for(int u =1; u <= k; u++)
            C[i][j] += A[i][u] * B[u][j];
       }
   }
}

int main(void)
{
    int n,k,m;
    cin >> n >> k >> m;

    matrix_t A(n+1, vector<int>(n+1));
    matrix_t B(k+1, vector<int>(k+1));
    matrix_t C(m+1, vector<int>(m+1));
   
    for (int i = 1; i <=n;i++){
        for(int j=1; j<=k; j++)
            cin >> A[i][j];
    }
    for (int i = 1; i <=k;i++){
        for(int j=1; j<=m; j++)
            cin >> B[i][j];
    }
    mult(n,k,m,A,B,C);
    for (int i = 1; i <=n;i++){
        for(int j=1; j<=m; j++)
            cout << C[i][j] <<" ";
        cout <<"\n";
    }
    
}