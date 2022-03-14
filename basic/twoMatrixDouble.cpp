#include <iostream>
#include <vector>

using namespace std;
typedef vector<vector<int>> matrix;

void mult(int n, int k, int m, matrix A, matrix B, matrix& C){
    for(int i =0; i <n; i++)
        for(int j = 0; j <m; j++){
            C[i][j]=0;
            for(int t =0; t <k; t++)
            C[i][j] += A[i][t] * B[t][j];
        }
    
}

int main(void){
    int n,k,m;
    cin >> n >> k >> m;
    matrix A(n,vector<int>(n));
    matrix B(k,vector<int>(k));
    matrix C(m,vector<int>(m));

    for(int i = 0; i <n; i++)
        for(int j =0; j <k; j++)
            cin >> A[i][j];
    
    for(int i =0; i<k; i++)
        for(int j =0; j<m; j++)
            cin >> B[i][j];
    
    mult(n,k,m,A,B,C);
    for(int i =0; i<n; i++){
        for(int j=0; j<m; j++)
            if(j <m-1)
                cout << C[i][j] << " ";
            else
                cout << C[i][j];
        if(i < n-1)
        cout << "\n";
    }
    
}