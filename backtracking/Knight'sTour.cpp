#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;
vector<int> mark;
int n,m,T,start,cnt,rcnt;


void make_adj(){
    int imove[] = {-2,-1,1,2,2,1,-1,-2};
    int jmove[] = {1,2,2,1,-1,-2,-2,-1};
    for(int i=0; i<n; i++)
        for(int j =0; j<m; j++)
            for(int k=0; k<8; k++){
                int ni = i + imove[k];
                int nj = j + jmove[k];
                if(ni >= 0 && nj >= 0 && ni < n && nj < m)
                    graph[i*m+j].push_back(ni*m +nj);
            }
}

void tour(int kth, int v) {
    if (kth == n * m){
        cnt++;
        vector<int> adj = graph[v];
        if (find(adj.begin(), adj.end(),start) != adj.end()) 
            rcnt++;
    }
    else{
        for (int u: graph[v])
            if (mark[u] == 0) {
                mark[u] = kth + 1;
                tour(kth + 1, u);
                mark[u] = 0;
            }
    }
}

int main(){
    cin >> n >> m >> T;
    graph.resize(n*m,vector<int>(0));
    mark.resize(n*m,0);
    make_adj();

    rcnt =0;
    start = 0;
    mark[start] = 1; //start
    tour(1,start);
    cout << rcnt <<"\n";
    
    int i,j;
    for(int k=0; k<T;k++){
        cin >> i >> j;
        fill(mark.begin(), mark.end(), 0); //0으로 다시 초기화
        start = i*m +j;
        cnt =0;
        //cout << "start = " <<start << "\n";
        mark[start] =1;
        tour(1,start);
        cout << cnt << "\n";
    }
    return 0;
}