#include <iostream>
#include <vector>
#include <utility>
#include <string>
using namespace std;
/*
Input

첫 줄에 정점의 수 n과 간선의 수 k가 주어진다.

둘째 줄부터 k개의 간선이 주어진다.

Output

첫째 줄에 색칠 가능한 최소의 m값을 출력한다.

둘째 줄에 해당 m값으로 색칠할 수 있는 경우의 수를 출력한다.

*/

int n,m,k,cnt;
vector<vector<int>> W;
vector<int> vcolor;

bool promising(int i){
    int j = 1;
    bool flag = true;
    while(j < i && flag){
        if(W[i][j] && vcolor[i] == vcolor[j])
            flag =false;
        j++;
    }
    return flag;
}

void m_coloring(int i){
    int color;

    if(promising(i)){
        if(i == n){
            // for(int j =1; j<n+1; j++)
            //     cout << vcolor[j] << " ";
            // cout << "\n";
            cnt++;
        }
        else {
            for(color =1; color <= m; color++){
                vcolor[i + 1] = color;
                m_coloring(i+1);
            }
        }
    }
}

int main(){
    cin >> n; cin >> k; // edges & vertax
    vcolor.resize(k+1,0);
    W.resize(n+1,vector<int>(n+1,0));

    int v, e;
    for(int i=0; i<k; i++){
        cin >> v >> e;
        W[v][e] = W[e][v] = 1; //adjacency matrix
    }

    m =3; // m-color의 초기값은 3부터 시작
    // while(cnt == 0){
    //     m++;
    //     m_coloring(0);
    // }
    m = 4;
    m_coloring(0);

    cout << m << "\n" << cnt;
    return 0;
}