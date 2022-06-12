#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;
vector<int> mark;
int n,m,T,start,path_count,cycle_count;


void make_adj(){
    int imove[] = {-2,-1,1,2,2,1,-1,-2};
    int jmove[] = {1,2,2,1,-1,-2,-2,-1};
    for(int i=0; i<n; i++)
        for(int j =0; j<m; j++)
            for(int k=0; k<8; k++){
                int ni = i + imove[k];
                int nj = j + jmove[k];
                if(ni >= 0 && nj >= 0 && ni < n && nj < m){
                    graph[i*m+j].push_back(ni*m +nj);
                    //cout << i*m+j << " = " <<  ni*m +nj << "\n";
                }
            }
    for(int i=0; i < m*n; i++){
        cout << "[" << i << "] = ";
        int j = 0;
        do{
            cout << graph[i][j] << " ";
            j++;
        }while(graph[i][j] !=0);
        cout << "\n";
    }
}

void printPath(int cnt){ //show paths
    cout <<"--------- "<< cnt << " -------------" <<"\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%2d ", mark[i*m + j]);
        cout << "\n";
    }
}

void tour(int kth, int v) {
    if (kth == n * m){
        path_count++;
        //printPath(path_count);

        //find cycle
        vector<int> adj = graph[v];
        if (find(adj.begin(), adj.end(), start) != adj.end()){
            cycle_count++;
            //printPath(cycle_count);
        }
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
    mark.resize(n*m,0); //init mark = 0
    make_adj();

    //find cycle
    cycle_count =0;
    start = 0;
    mark[start] = 1; //start
    
    tour(1,start);
    cout << "cycle_count : " << cycle_count <<"\n"; 
    
    //find path
    int i,j;
    for(int k=0; k < T;k++){
        cin >> i >> j; //input start vertax
        fill(mark.begin(), mark.end(), 0); //init mark = 0
        
        path_count =0;
        start = i * m + j; //start vertax
        mark[start] = 1;
        
        tour(1,start);
        cout << "path_count : " << path_count << "\n";
    }
    return 0;
}