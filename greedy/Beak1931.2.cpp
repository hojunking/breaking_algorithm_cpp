#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef vector<pair<int ,int>> set_of_times;

void makeTable(set_of_times& time, int n){
    int index =1;
    int start = time[0].first;
    for(int i=1; i< n; i++){
        if(start <= time[i].second){
            index++;
            start = time[i].first;
        }
    }
    cout << index;
}

int main(void){
    int n, s,e; 
    cin >> n;
    set_of_times time;

    for(int i =0; i<n; i++){
        cin >> s >> e;
        time.push_back(make_pair(e,s));
    }
    sort(time.begin(),time.end());

    // for(auto e : time)
    //     cout << e.first << " " << e.second <<"\n";
        
    makeTable(time, n);
}