//Dijkstra Algoritm find: shortest path
#include <iostream>
#include <vector>
#include <utility>
#define INF 0xffff
using namespace std;

typedef vector<vector<int>> matrix_t;
typedef vector<pair<int,int>> set_of_edges;

vector<int> dijkstra(int n, matrix_t& W, set_of_edges& F){
    int vnear, min;
    vector<int> touch(n+1), length(n+1);

    F.clear();
    for(int i=2; i<=n; i++){
        touch[i] =1; // v1 출발 가정
        length[i] = W[1][i]; //v1의 edge's weight
    }

    for(int j = 1; j<n; j++){
        min = INF;
        for(int i=2; i<= n; i++){ //전체 edge크기 전부 조사 작은거 min
            if(0 <= length[i] && length[i] < min){
                min = length[i];
                vnear =i;
            }
        }
        //touch print
        for(int k =2; k < n+1; k++){
            if(k <n)
            cout << touch[k] << " ";
            else
            cout << touch[k] << "\n";
        }

        F.push_back(make_pair(touch[vnear], vnear));

        for (int i=2; i<=n; i++){ //최단거리를 전부 갱신시켜준다.
            if(length[i] > length[vnear]+ W[vnear][i]){ //direct > step by step인 경우 찾기 및 갱신
                length[i] = length[vnear] + W[vnear][i];
                touch[i]= vnear;
            }
        } 
        length[vnear]= -1; //다음 단계로 갈 때 가장 작은 edge weight -1로 만든다.

    }
    return touch;
}

void printPath(int k,vector<int> touch){ //retracking print path
    int i =k;
    if(touch[k] == 1){
        cout << touch[k] << " " << k;
        return;
    }
    else{
        k = touch[i];
        printPath(k, touch);
        cout << " " << i;
    }
}

int main(void){
    int m,n,u,v,w;
    cin >> n >> m;
    matrix_t W(n+1,vector<int>(n+1,INF));
    set_of_edges F;
    
    for(int i=1; i<n+1; i++)
        W[i][i] = 0;

    for(int i =0; i<m; i++){
        cin >> u >> v >> w;
        W[u][v] = w;
    }

    //input 받아놓기
    int t; cin >> t;
    vector<int> input(t);
    for(int i=0; i<t; i++)
        cin >> input[i];

    vector<int> touch(n+1);
    touch = dijkstra(n,W,F);
    
    //print F - edges
    for(int i=0; i<n-1; i++)
        cout << F[i].first << " " << F[i].second << " " << W[F[i].first][F[i].second] <<"\n";

    for(int i =0; i<input.size(); i++){
        printPath(input[i],touch);
        cout << "\n";
    }
   
}