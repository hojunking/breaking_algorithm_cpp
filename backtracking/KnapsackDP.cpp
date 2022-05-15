#include <iostream>
#include <vector>
#include <utility>
#include <map>
using namespace std;
typedef map<pair<int, int>,int> MAP;


void bubble_sort(vector<int>& t,vector<int> &c, int n){
    
    for(int i=n; 1 <i; i--)
        for(int j=1; j<i; j++)
            if((double)t[j+1]/c[j+1] > (double)t[j]/c[j]){
                swap(t[j+1], t[j]);
                swap(c[j+1], c[j]);
            }
    //check sorted!
    // for(int i : t)
    //     cout << i << " ";
    // cout << "\n";
    // for(int i : c)
    //     cout << i << " ";
    // cout << "\n";
}

int knapsack3(int n,int W, vector<int>& w, vector<int>& p, MAP &P){
    if(n ==0 || W <=0) //개수, 가방무게 validation
        return 0;

    int lvalue = (P.find(make_pair(n-1,W)) != P.end()) ?
        P[make_pair(n-1,W)] : knapsack3(n-1,W,w,p,P); //추가

    int rvalue = (P.find(make_pair(n-1,W-w[n])) != P.end()) ?
        P[make_pair(n-1,W-w[n])] : knapsack3(n-1,W-w[n],w,p,P);

    P[make_pair(n,W)] = (w[n] > W) ? lvalue : max(lvalue, p[n] + rvalue);
    //cout << n << " " << W << " " << P[make_pair(n,W)] << "\n";
    return P[make_pair(n,W)];
} 



int knapsack2(int n, int W,vector<int>& w, vector<int>& p, MAP &P){
    for(int i=1; i<=n; i++)
        for(int j=1; j<=W; j++){
            P[make_pair(i,j)] = (w[i] > j) ? P[make_pair(i-1,j)] :
                max(P[make_pair(i-1,j)],p[i] + P[make_pair(i-1,j-w[i])]);
        if(P[make_pair(i,j)] == 50) cout << i << " " << w[j] <<"\n";
        }
    return P[make_pair(0,W)];
}


int main(){
    int n; cin >> n;
    vector<int> w(n+1), p(n+1);

    for(int i=1; i<=n; i++) //weights
        cin >> w[i];
    for(int i=1; i<=n; i++) //profits
        cin >> p[i];
      
    bubble_sort(p,w,n);

    int T; cin >> T;
    vector<int> W(T+1);

    for(int i=1; i<=T; i++) //backpark weight
        cin >> W[i];

    int k =0;
    while(k < T){
        MAP P;
        k++;
        for(int i=0; i<=n; i++)
            P[make_pair(i,0)] =0;
        for(int j=0; j<=W[k]; j++)
            P[make_pair(0,j)] =0;

        int maxProfit = knapsack3(n,W[k],w,p,P);
        cout << maxProfit <<"\n";

        MAP::iterator it;
        for (it = P.begin(); it != P.end(); it++)
            if(it->first.first != 0 && it->first.second !=0)
                cout << it->first.first << " " << it->first.second << " " << it->second << "\n";
    }
    return 0;
}