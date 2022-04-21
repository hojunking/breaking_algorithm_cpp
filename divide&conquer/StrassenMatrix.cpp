#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> matrix_t;

int threshold,cnt=0;

void makeBinary(int& n);
void resize(int n, matrix_t& M);
void inputMatrix(int n,matrix_t& M);
void printMatrix(int n, matrix_t M);
void madd(int n, matrix_t A,matrix_t B,matrix_t& C);
void msub(int n, matrix_t A,matrix_t B,matrix_t& C);
void mmult(int n,matrix_t A,matrix_t B,matrix_t& C);
void partition(int m,matrix_t M,
     matrix_t& M11,matrix_t& M12, matrix_t& M21, matrix_t& M22);
void merge(int n, matrix_t& C,matrix_t C11,matrix_t C12,matrix_t C21,matrix_t C22);
void strassen(int n, matrix_t A, matrix_t B, matrix_t& C);

int main(){
    int n,t;
    cin >> n >> threshold;
    t = n;
    makeBinary(n);
    matrix_t A,B,C;
    //사이즈 설정
    resize(n,A);
    resize(n,B);
    resize(n,C);

    inputMatrix(t,A);
    inputMatrix(t,B);
    strassen(n,A,B,C);
    cout << cnt <<"\n";
    printMatrix(t,C);
}
void strassen(int n, matrix_t A, matrix_t B, matrix_t& C){
        cnt++;
        matrix_t A11, A12, A21, A22;
        matrix_t B11, B12, B21, B22;
        matrix_t C11, C12, C21, C22;
        matrix_t M1,M2,M3,M4,M5,M6,M7;
        matrix_t L,R;
        int m = n/2;

        resize(m,A11);resize(m,A12);resize(m,A21);resize(m,A22);
        resize(m,B11);resize(m,B12);resize(m,B21);resize(m,B22);
        resize(m,C11);resize(m,C12);resize(m,C21);resize(m,C22);
        
        resize(m,M1);resize(m,M2);resize(m,M3);resize(m,M4);resize(m,M5);
        resize(m,M6);resize(m,M7);
        
        resize(m,L);resize(m,R);
        
    if(n <= threshold)
        mmult(n,A,B,C);
    else{
        partition(m,A,A11,A12,A21,A22);
        partition(m,B,B11,B12,B21,B22);
        //M1
        madd(m, A11,A22,L);
        madd(m, B11,B22,R);
        strassen(m,L,R,M1);
        //M2
        madd(m,A21,A22,L);
        strassen(m,L,B11,M2);
        //M3
        msub(m,B12,B22,L);
        strassen(m,A11,L,M3);
        //M4
        msub(m,B21,B11,L);
        strassen(m,A22,L,M4); //순서 틀리면 좇된다...
        //M5
        madd(m,A11,A12,L);
        strassen(m,L,B22,M5);
        //M6
        msub(m,A21,A11,L);
        madd(m,B11,B12,R);
        strassen(m,L,R,M6);
        //M7
        msub(m,A12,A22,L);
        madd(m,B21,B22,R);
        strassen(m,L,R,M7);
        
        //C11
        madd(m,M1,M4,L);
        msub(m,L,M5,R);
        madd(m,R,M7,C11);
        //C12
        madd(m,M3,M5,C12);
        //C21
        madd(m,M2,M4,C21);
        //C22
        madd(m,M1,M3,L);
        msub(m,L,M2,R);
        madd(m,R,M6,C22);

        merge(m,C,C11,C12,C21,C22);
    }
}
void makeBinary(int& n){
    int k=1;
    while(k <n)
    k *=2;
    n = k;
}
void mmult(int n,matrix_t A, matrix_t B, matrix_t& C){
    for(int i = 0; i<n;i++){
        for(int j =0; j<n; j++){
            C[i][j] = 0;
            for(int k = 0; k <n; k++)
                C[i][j] += A[i][k] * B[k][j];   
        }
    }
}
void partition(int m,matrix_t M,
                matrix_t& M11,matrix_t& M12,matrix_t& M21,matrix_t& M22){
     for(int i =0; i < m; i++)
        for(int j=0; j < m; j++){
            M11[i][j] = M[i][j];
            M12[i][j] = M[i][j+m];
            M21[i][j] = M[i+m][j];
            M22[i][j] = M[i+m][j+m];
        }
}
void merge(int m, matrix_t& M,matrix_t M11,matrix_t M12,matrix_t M21,matrix_t M22){
    for(int i =0; i<m; i++){
        for(int j =0; j<m; j++){
            M[i][j] = M11[i][j];
            M[i][j+m] = M12[i][j];
            M[i+m][j] = M21[i][j];
            M[i+m][j+m] = M22[i][j];
        }
    }
}
void inputMatrix(int n,matrix_t& M){
    for(int i =0; i < n; i++)
        for(int j=0; j < n; j++)
            cin >> M[i][j];
}
void printMatrix(int n, matrix_t M){
    for(int i =0; i < n; i++){
        for(int j=0; j < n; j++)
            if(j < n-1)
            cout << M[i][j] <<" ";
            else
            cout << M[i][j];
        cout <<"\n";
    }
}
void resize(int n, matrix_t& M){
    M.resize(n,vector<int>(n));
}
void madd(int n, matrix_t A,matrix_t B,matrix_t& C){
     for(int i =0; i < n; i++)
        for(int j=0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}
void msub(int n, matrix_t A,matrix_t B,matrix_t& C){
     for(int i =0; i < n; i++)
        for(int j=0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

