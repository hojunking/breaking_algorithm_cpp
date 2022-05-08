#include <iostream>
#include <vector>
#include <utility>
#include <string>
using namespace std;

/*
    n개의 수의 합이 W가 되는 경우의 수와 집합 구하기
*/
int n,W,k;
vector<int> w, include;
vector<pair<int,vector<int>>> sets;
//vector<vector<int>> sets;
vector<vector<int>> sets2;


void printSets(void){
    for(int i= 0; i<k; i++){
        for(int j=1; j < n+1; j++){
            if(sets[i].second[j] == 1)
                cout << w[j] << (j < n ? " ": "\n");
            else cout << (j < n ? "": "\n");
            // if(sets[i].second[j])
            //     if(j < n) cout << w[j] << " ";
            //     else cout << w[j] <<"\n";
            // else 
            //     if(j < n) cout << "";
            //     else cout <<"\n";
        }
    }
}

void printSets2(){
    for(int i =1; i<k+1; i++){
        int p =0;
        for(int j=1; j<n+1; j++){
            
            // if(sets2[i][j] == 1)
            //     cout << w[j] << (j < n ? " ": "\n");
            // else cout << (j < n ? "": "\n");
            if(sets2[i][j] == 1){
                //cout << (j ==1 ? "": " ") << w[j];
                p++;
                cout << (p ==1 ? "": " ") << w[j];
            }
        }
        cout << "\n";
        p =0;
    }
}

bool promising(int i, int weight, int total){
    return (weight + total >= W) && (weight == W || weight +w[i+1] <= W);
}


void sum_of_subsets(int i, int weight, int total){
    if(promising(i,weight,total)){
        if(weight == W){
            k++;
            //sets.push_back(make_pair(k,include));
            sets2.resize(k+1);
            sets2[k].resize(n+1);
            copy(include.begin(), include.end(), sets2[k].begin());
            // for(int j=1; j<n+1; j++)
            //     cout << sets2[k][j] << (j < n ? " ": "\n");
        }
        else{
            include[i+1] = 1;
            sum_of_subsets(i+1, weight + w[i+1], total - w[i+1]);
            include[i+1] = 0;
            sum_of_subsets(i+1, weight, total-w[i+1]);
        }
    }
}

int main(){
    cin >> n;  
    cin >> W; 
    
    w.resize(n+1);
    include.resize(n+1,0);
    
    int total = 0;
    for(int i=1; i<=n; i++){
        cin >> w[i];
    }

    for(int i=1; i<=n; i++){
        total += w[i];
    }
    k=0;
    sum_of_subsets(0,0,total);
    cout << k << "\n";
    printSets2();
    return 0;
}