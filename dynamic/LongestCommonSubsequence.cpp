#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// recursive -> overlapping subproblems -> memoization
// top-down -> bottom-up
// LCS

typedef vector<vector<int>> matrix_t;

int LCS(vector<char>& A, vector<char>& B, matrix_t& D){
    int m = A.size(), n = B.size();

    matrix_t C (m,vector<int>(n,0)); // (m by n) matrix, set 0
    D.resize(m,vector<int>(n,0));
    
    for(int i=1; i <m; i++){
        for(int j=1; j <n ; j++){
            if(A[i] == B[j]){
                C[i][j] = C[i-1][j-1] +1;
                D[i][j] = 1;
            }
            else{
                C[i][j] = max(C[i][j-1], C[i-1][j]);
                D[i][j] = (C[i][j-1] > C[i-1][j] ? 2 : 3);
            }
        }
    }
    // matrix C 확인
    // for(int i=0; i <m; i++){
    //     for(int j=0; j < n; j++)
    //         cout << C[i][j] << " ";
    //     cout << " \n";
    // }

    //matrix D 확인
    // for(int i=0; i <m; i++){
    //     for(int j=0; j < n; j++)
    //         cout << D[i][j] << " ";
    //     cout << "\n";
    // }
    return C[m-1][n-1];
}

void getLcs(int i, int j,matrix_t& D,string& lcs,string& t){
    if(i ==0 || j ==0)
        return;
    else{
        if(D[i][j]==1){
            //cout << t[i-1] << "\n";
            lcs +=t[i-1];
            getLcs(i-1,j-1,D,lcs,t); 
        }
        else if(D[i][j]==2)
            getLcs(i,j-1,D,lcs,t);
        
        else if(D[i][j]==3)
            getLcs(i-1,j,D,lcs,t);
    }
    
}

void inputStr(vector<char>& T, string t, int& len){
    len++;
    T.resize(len);
    T[0]=' ';
    for(int i =1; i < len; i++)
        T[i] = t[i-1];
}


int main(void){
    string t1,t2,lcs;
    cin >> t1 >> t2;

    vector<char> A,B;
    matrix_t D; // tracking marix
    
    int x,y;  //length of string
    x = t1.length();
    y = t2.length();
    
    inputStr(A,t1,x); // input string to vector
    inputStr(B,t2,y);

    cout << LCS(A,B,D) << "\n";
    
    getLcs(x-1,y-1,D,lcs,t1);
    reverse(lcs.begin(),lcs.end());
    cout << lcs << "\n";

    //cout << lcs << "\n";

    // for(int i =0; i <x+1; i++)
    //     cout << A[i];
    // cout << "\n";

    // for(int i =0; i <y+1; i++)
    //     cout << B[i];
    // cout << "\n";

}