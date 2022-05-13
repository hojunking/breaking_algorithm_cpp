#include <iostream>
#include <vector>
#include <utility>
#include <map>
using namespace std;
typedef map<pair<int, int>,int> MAP;


void bubble_sort(vector<int>& t, int n){
    for(int i=n; 1 <i; i--)
        for(int j=1; j<i; j++)
            if(t[j+1] > t[j])
                swap(t[j+1], t[j]);

    //check sorted!
    // for(int i : t)
    //     cout << i << " ";
    // cout << "\n";
}

int knapsack3(int n,int W, vector<int>& w, vector<int>& p, MAP &P){
    if(n ==0 || W <=0) //개수, 가방무게 validation
        return 0;

    int lvalue = (P.find(make_pair(n-1,W)) != P.end()) ?
        P[make_pair(n-1,W)] : knapsack3(n-1,W,w,p,P); //추가

    int rvalue = (P.find(make_pair(n-1,W-w[n])) != P.end()) ?
        P[make_pair(n-1,W)] : knapsack3(n-1,W-w[n],w,p,P);

    P[make_pair(n,W)] = (w[n] > W) ? lvalue : max(lvalue, p[n] + rvalue);
    //cout << n << " " << W << " " << P[make_pair(n,W)] << "\n";
    return P[make_pair(n,W)];
}

int main(){
    int n; cin >> n;
    vector<int> w(n+1), p(n+1);

    for(int i=1; i<=n; i++) //weights
        cin >> w[i];
    for(int i=1; i<=n; i++) //profits
        cin >> p[i];
      
    bubble_sort(w,n);
    bubble_sort(p,n);

    int T; cin >> T;
    vector<int> W(T+1);

    for(int i=1; i<=n; i++) //backpark weight
        cin >> W[i];

    MAP P;
    int maxProfit = knapsack3(n,W[1],w,p,P);
    cout << maxProfit;

    for(int i=1; i<=n; i++)
        for(int j=10; j<=W[1]; j +=10)
            cout << i << " " << j << " " << P[make_pair(i,j)] << "\n";
    
    return 0;
}