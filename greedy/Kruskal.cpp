#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct edge{
    int u, v, w;
} edge_t;

struct edge_compare {
    bool operator()(edge_t e1, edge_t e2){
        if(e1.w > e2.w) return true;
        else return false;
    }
};

typedef vector<edge_t> set_of_edges;
typedef priority_queue<edge_t, vector<edge_t>, edge_compare> priorityQueue;

vector<int> dset;

void disjoint_set_init(int n){
    dset.resize(n+1);
    for(int i =1; i <n+1; i++)
        dset[i] = i; //init 자기 자신을 바라본다.
}

int disjoint_set_find(int i){
    while(dset[i] != i) //자기 자신을 보는건 루트노드
        i = dset[i];
    return i;
}

void disjoint_set_merge(int p, int q){ //큰 값이 작은 값으로 merge!
    dset[p] = q;
}

void Kruskal(int n, int m, set_of_edges& E, set_of_edges& F){
    int p, q;
    edge_t e; //temp edge_t for sorting in PQ // temp
    priorityQueue PQ;

    for(edge_t e: E)
        PQ.push(e); //insert all of E into PQ
    
   // cout << "spot2" << "\n";
    F.clear(); // result init()
    disjoint_set_init(n); //n개의 노드 init()
    
    while(F.size() < n-1){
        //cout << "spot3" << "\n";
        e = PQ.top(); PQ.pop();
        p = disjoint_set_find(e.u);
        q = disjoint_set_find(e.v);
        if(p != q){     //같다면 Cycle이 생겼다!! 그렇다!!!
            disjoint_set_merge(p,q);
            F.push_back(e);
        }
    }
    
}


int main(void){
    int n, m; cin >> n >> m;
    int u,v,w;
    set_of_edges edges, result;
    
    for(int i=0; i<m; i++){
        cin >> u >> v >> w;
        edge_t t;
        t.u = u; t.v = v; t.w = w;
        edges.push_back(t);    
    }

    //cout << "spot1" << "\n";
    Kruskal(n,m,edges, result);
    
    for(edge_t e : result){
        cout << e.u <<" " <<e.v << " " << e.w <<"\n";
    }
    
}