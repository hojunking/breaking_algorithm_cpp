#include <iostream>
#include <vector>
#include <utility>
#define INF 0xffff
using namespace std;
typedef vector<vector<int>> matrix_t;
typedef vector<pair<int, int>> set_of_edges;
typedef pair<int, int> edge_t;

void prim(int n, matrix_t& W, set_of_edges& F){
    int vnear, min;
    vector<int> nearest(n+1), distance(n+1);
    F.clear(); // F 비우기
    for (int i=2; i<=n; i++){ //init 작업
        nearest[i] =1; //v1에서 출발한다는 가정-> 1로 초기화
        distance[i] =W[1][i];
    }
    //초기 nearest 출력
    for(int i=2; i<n+1; i++){
            if(i < n)
            cout << nearest[i] << " ";
            else
            cout << nearest[i] << "\n";
        }

    for(int j =1; j <n ; j++){
        min = INF;
        for(int i=2; i <n+1; i++){
            if(0 <= distance[i] && distance[i] < min){
                min = distance[i];
                vnear = i;
            }
        }
        F.push_back(make_pair(vnear, nearest[vnear]));
        distance[vnear] =-1; //최단거리값 구하고 -1표시
        for(int i=2; i<=n ; i++){ 
            if(distance[i] > W[i][vnear]){ //이전 상태의 distance보다 작은값을 
                distance[i] = W[i][vnear]; //distance에 넣어 최신화
                nearest[i] = vnear; //vnear기준으로 근접 노드 표시
            }
        }

        //이후 nearest 출력
        for(int i=2; i<n+1; i++){
            if(i < n)
            cout << nearest[i] << " ";
            else
            cout << nearest[i] << "\n";
        }
        
    }
}
int main(void){
    int n,m, u,v,w;
    cin >> n >> m;
    matrix_t W(n+1,vector<int>(n+1, INF)); //최소값을 찾아야한다.초기값 INF
    for(int i=1; i<n+1; i++) //자기 자신 간선 0
        W[i][i] =0;

    for(int i=0; i<m; i++){ //입력 대칭
        cin >> u >> v >> w;
        W[u][v] = w;
        W[v][u] = w;
    }
    set_of_edges F;
    prim(n,W,F);
    for(edge_t e : F){
        u = e.first; v=e.second;
        cout << u <<" "<< v << " " << W[u][v] << "\n";
    }
   
}