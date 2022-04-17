//floyd Algoritm find: shortest path

#include <iostream>
#include <vector>
#include <algorithm>
#define INF 999
using namespace std;
typedef vector<vector<int>> matrix_t;


void floyd2(int n, matrix_t& W, matrix_t& D, matrix_t& P){
    for(int i =1; i <=n; i++){
        for(int j=1; j <=n; j++){
            D[i][j] = W[i][j];
            P[i][j] = 0;
        }
    }
    for(int k =1; k <= n; k++)
        for(int i=1; i<=n; i++)
            for(int j =1; j<=n; j++)
                if(D[i][j] > D[i][k] + D[k][j]){ //direct가 더 크다면 거쳐서
                    D[i][j] = D[i][k] + D[k][j]; //그 길이를 D에 저장
                    P[i][j] =k; //tracking용
                }
}

void path(matrix_t& P,int u, int v, vector<int>& p ){
    int k = P[u][v];
    if(k !=0){
        path(P,u,k,p);
        p.push_back(k);
        path(P,k,v,p);
    }
}



void inputPInfo(int m, matrix_t& W){
    int u ,v ,w;
    for(int i =1; i <= m; i++){
        cin >> u >> v >> w;
        W[u][v] = w;
    }
    
}
void printPInfo(int n, matrix_t A){
    for(int i =1; i <=n; i++){
        for(int j =1; j <= n; j++){
            //printf("%3d ",A[i][j]);
            if(j == 0)
                cout << A[i][j];
            else
                cout << A[i][j] <<" ";
        }
    cout <<"\n";
    }
    //cout <<"\n";
}




int main(void){
    int n,m,c;
    cin >> n >> m;
    matrix_t W(n+1,vector<int>(n+1,INF));
    matrix_t D(n+1,vector<int>(n+1,INF));
    matrix_t P(n+1,vector<int>(n+1,INF));
    
    for (int i = 1; i <= n; i++)
        W[i][i] = 0;

    inputPInfo(m,W);
    floyd2(n,W,D,P);
    printPInfo(n,D);
    printPInfo(n,P);

    int u,v;
    cin >> c;
    while(c-- >0){
        cin >> u >> v;
        vector<int> p;
        path(P,u,v,p);

        if(D[u][v]==999)
            cout << "NONE" <<"\n";

        else{
            cout << u;

            for(int i=0; i<p.size(); i++)
                cout << " " << p[i];
            
            cout << " " << v << "\n";
        }
    } 

}