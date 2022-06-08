#include <iostream>
#include <vector>
#include <utility>
using namespace std;

/*
    beak 1182
*/
int n, W, k;
vector<int> w;

void sum_of_subsets2(int i, int sum){
    sum += w[i];

    if(i>=n) return;
    if(sum == W) k++;

    sum_of_subsets2(i+1,sum-w[i]);
    sum_of_subsets2(i+1,sum);
}



int main(void){
    int total =0;
    cin >> n >> W;
    w.resize(n);

    for(int i=0; i<n; i++)
        cin >> w[i];
    
    k=0;
    sum_of_subsets2(0,0);
    cout << k;
}