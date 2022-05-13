#include <iostream>
#include <vector>
#include <utility>
#include <string>
using namespace std;

int n,m,cnt;
vector<vector<int>> W;
vector<int> vindex;

bool promising(int i){
    int j;
    bool flag;
    if(i == n-1 && !W[vindex[n-1]][vindex[0]])
        flag = false;
    else if (i>0 && !W[vindex[i -1]][vindex[i]])
        flag = false;
    else{
        flag = true;
        j=1;
        while(j <i && flag){
            if(vindex[i] == vindex[j])
            flag = false;
            j++;
        }
    }
    return flag;
}

void hamiltonian(int i){
    int j;

    if(promising(i)){
        if(i == n-1){
            cnt++;
        }
        else{ 
            for(j =2; j<=n; j++){
                vindex[i+1] = j;
                hamiltonian(i+1);
            }
        }
    }
}

int main(){
    cin >> n >> m;

    W.resize(n+1,vector<int>(n+1,0));
    vindex.resize(n+1,0);

    int v,e;
    for(int i=0; i<m; i++){
        cin >> v >> e;
        W[v][e] = W[e][v] = 1;
    }

    cnt =0; vindex[0] =1;
    hamiltonian(0);
    cout << cnt;
    return 0;
}