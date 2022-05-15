#include <iostream>
#include <vector>
using namespace std;

int n,W,maxProfit;
vector<int> w, p,bestset,include;
float bound;


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

// void array_copy(vector<int> bestset, vector<int> include){
// }

bool promising(int i, int profit, int weight){
    int j,k,totalweight;
    if(weight >= W){ //총 무게를 넘긴다면
        cout << i << " " << weight << " " << profit << " " << bound << " " << maxProfit << "\n";
        return false;
    }
    else{
        j = i+1;
        bound = profit; //기존 profit 저장
        totalweight = weight; //기존 무게 저장
        while(j <=n && totalweight + w[j] <= W){ //총 무게 보다 작은선에서 찾기
            totalweight += w[j];
            bound += p[j];
            j++;
        }
        k = j; //position 저장
        //cout << " k = " << k << "W-totalweight = " << W-totalweight <<"\n";
        
        if(k <=n)
            bound += (W - totalweight) * ((float)p[k] / w[k]);
            cout << i << " " << weight << " " << profit << " " << bound << " " << maxProfit << "\n";

        return (bound > maxProfit) ? true : false;
    }
}

void knapsack4(int i, int profit, int weight){
    if(weight <= W && profit > maxProfit){
        maxProfit = profit;
        bestset.resize(include.size());
        copy(include.begin(),include.end(),bestset.begin());
    }
    if(promising(i,profit,weight)){
        include[i+1] = 1;
        knapsack4(i+1, profit + p[i+1], weight + w[i+1]); //추가
        include[i+1] = 0; //
        knapsack4(i+1, profit, weight); // 추가 하지 않음
    }
}

int main(){
    cin >> n >> W;
    w.resize(n+1); p.resize(n+1);
    include.resize(n+1,0); bestset.resize(n+1);

    for(int i=1; i<=n; i++) //weights
        cin >> w[i];
    for(int i=1; i<=n; i++) //profits
        cin >> p[i];

    bubble_sort(p,w,n);

    maxProfit =0;
    knapsack4(0,0,0);
    cout << maxProfit << "\n";
    
    for(int i=1; i<=n; i++){
        if(bestset[i])
            cout << w[i] << " " << p[i] <<"\n";
    }
    return 0;
}