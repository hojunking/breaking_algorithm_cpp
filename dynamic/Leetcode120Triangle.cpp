#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> matrix_t;
int cnt =0;

void inputMatrix(int n, matrix_t& A){
    for (int i = 0; i < n; i++) 
        for (int j = 0; j <= i; j++) 
            cin >> A[i][j];
}

void findPath(int n,int i, int j, matrix_t A, matrix_t D){
    if (D[i+1][j] <= D[i+1][j+1]) {
        cout << A[i+1][j+1] <<" ";
        cnt++;
        if (cnt != (n - 1)) {
            findPath(n, i + 1, j + 1, A, D);
        }
    }
    else {
        cout << A[i+1][j] <<" ";
        cnt++;
        if (cnt != (n - 1)) {
            findPath(n, i + 1, j, A, D);
        }
    }
}
  
int main(void){
    int n; cin >> n;
    matrix_t A(n,vector<int>(n));
    matrix_t D(n,vector<int>(n));
    inputMatrix(n,A);

    for(int i = 0; i<n; i++)
        D[n-1][i] = A[n-1][i];

    for(int i = n-1; 0 <i; i--)
        for(int j =0; j < i; j++){
            if(D[i][j] >= D[i][j+1])
                D[i-1][j] =A[i-1][j] + D[i][j];
            else
                D[i-1][j] = A[i-1][j] + D[i][j+1];
        }

    cout << D[0][0] <<"\n" ;
    cout << A[0][0] << " ";
    findPath(n,0,0,A,D);
}
