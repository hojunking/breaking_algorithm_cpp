#include <iostream>
#include <vector>
#include <string>
#define INF 999
using namespace std;
typedef vector<vector<int>> matrix_t;

int minimum(int i, int j, int& mink, vector<int>& d, matrix_t& M ){
    int minValue = INF, value;
    for(int k=i; k <= j-1; k++){
        value = M[i][k] + M[k+1][j] + d[i-1]*d[k]*d[j];
        if(minValue > value){
            minValue = value;
            mink = k;
        }
    }
    return minValue; 
}

void minMult(int n, vector<int>& d, matrix_t& P, matrix_t& M){
    int i,j,k, diagonal;
    for(i = 1; i <= n; i++)
        M[i][i] = 0;
    
    for(diagonal =1; diagonal <=n-1; diagonal++)
        for(i =1; i<=n-diagonal; i++){
            j = i +diagonal;
            M[i][j] = minimum(i, j, k,d,M);
            P[i][j] = k; //tracking
        }

}

void printMatrix(int n, matrix_t T){
    for(int i =1; i <=n; i++){
        for(int j=i; j <=n; j++){
            if(j <n)
            cout << T[i][j] << " ";
            else
            cout << T[i][j];
        }
        cout <<"\n";
    }
}

void order(int i, int j, matrix_t& P, string& s){
    if(i ==j)
        s += string("(A") + to_string(i) + string(")");
    else{
        int k = P[i][j];
        s += string("(");
        order(i, k,P,s);
        order(k+1,j, P,s);
        s += string(")");
    }
}

int main(void){
    //행렬의 개수
    int n; cin >> n;
    vector<int> d(n+2);

    matrix_t M(n+1, vector<int>(n+1));
    matrix_t P(n+1, vector<int>(n+1));
    //행렬의 크기 값
    for(int i=0; i<n+1; i++)
        cin >> d[i];
    minMult(n, d, P, M);
    printMatrix(n,M);
    printMatrix(n,P);
    //최적값
    cout << M[1][n] <<"\n";
    string s;
    //order(1,n,P,s);
    cout << s;
    
}