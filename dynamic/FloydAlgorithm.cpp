//floyd Algoritm find: shortest path

#include <iostream>
#include <vector>
#include <algorithm>
#define INF 999
using namespace std;
typedef vector<vector<int>> matrix_t;


void floyd(int n, matrix_t& W, matrix_t& D){
    for(int i =0; i <n; i++){
        for(int j=0; j<n; j++){
            //같은 정점 0으로 초기화
            if(i==j)
            W[i][j] = D[i][j] = 0;
            
            D[i][j] = W[i][j];
        }
    }
    for(int k =0; k < n; k++)
        for(int i=0; i<n; i++)
            for(int j =0; j<n; j++)
                D[i][j] = min(D[i][j],D[i][k] + D[k][j]);

}

void floyd2(int n, matrix_t& W, matrix_t& D, matrix_t& P){
    for(int i =0; i <n; i++){
        for(int j=0; j<n; j++){
            //같은 정점 0으로 초기화
            if(i==j)
            W[i][j] = 0;
            
            D[i][j] = W[i][j];
            P[i][j] = 0;
        }
    }
    for(int k =0; k < n; k++)
        for(int i=0; i<n; i++)
            for(int j =0; j<n; j++)
                if(D[i][j] > D[i][k] + D[k][j]){
                    D[i][j] = D[i][k] + D[k][j];
                    P[i][j] =k+1;
                }
}

void inputPInfo(int m, matrix_t& W, matrix_t&D){
    int u ,v ,w;
    for(int i =0; i<m; i++){
        cin >> u >> v >> w;
        W[u-1][v-1] = w;
    }
    
}
void printPInfo(int n, matrix_t A){
    for(int i =0; i <n; i++){
        for(int j =0; j<n; j++){
            //printf("%3d ",A[i][j]);
            cout << A[i][j] <<" ";
        }
    cout <<"\n";
    }
}

void path(matrix_t& P,int u, int v, vector<int>& p ){
    int k = P[u-1][v-1];
    if(k !=0){
        path(P,u,k,p);
        p.push_back(k);
        path(P,k,v,p);
    }
}

int main(void){
    int n,m,c;
    cin >> n >> m;
    matrix_t W(n,vector<int>(n,INF));
    matrix_t D(n,vector<int>(n,INF));
    matrix_t P(n,vector<int>(n,INF));
    inputPInfo(m,W,D);
    floyd2(n,W,D,P);
    printPInfo(n,D);
    printPInfo(n,P);

    int u,v;
    cin >> c;
    while(c-- >0){
        cin >> u >> v;
        vector<int> p;
        path(P,u,v,p);

        if(D[u-1][v-1]==999)
            cout << "NONE" <<"\n";

        else{
            cout << u;

            for(int i=0; i<p.size(); i++)
                cout << " " << p[i];
            
            cout << " " << v << "\n";
        }
    }

}