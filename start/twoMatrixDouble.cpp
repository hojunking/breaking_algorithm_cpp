
#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int>> matrix_t;

void mult(int n, matrix_t A, matrix_t B,matrix_t& C ){
   for(int i =1; i<=n; i++){
       for(int j =1; j<=n ; j++){
           C[i][j] += A[i][j] * B[i][j];
       }
   }
}

int main(void){
    int n;
    cin >> n;

    matrix_t A(n+1, vector<int>(n+1));
    matrix_t B(n+1, vector<int>(n+1));
    matrix_t C(n+1, vector<int>(n+1));
   
    for (int i = 1; i <=n;i++){
        for(int j=1; j<=n; j++)
            cin >> A[i][j];
    }
    for (int i = 1; i <=n;i++){
        for(int j=1; j<=n; j++)
            cin >> B[i][j];
    }
    
    for (int i = 1; i <=n;i++){
        for(int j=1; j<=n; j++)
            cout << C[i][j] << " ";
        cout << "\n";
    }
    
}