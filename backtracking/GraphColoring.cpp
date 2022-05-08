#include <iostream>
#include <vector>
#include <utility>
#include <string>
using namespace std;


int n,m,k;
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
    if(flag) m++;
    return flag;
}

void m_coloring(int i){
    int color;

    if(promising(i)){
        if(i == n){
            m =1;
            for(int j =1; j<n+1; j++)
                cout << vcolor[j] << " ";
            cout << "\n";
            
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
        W[v][e] = W[e][v] = 1;
    }
    m=3;
    m_coloring(0);
    return 0;
}