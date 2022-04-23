#include <iostream>
#include <vector>
#include <utility>
using namespace std;

typedef vector<pair<int ,int>> set_of_times;
typedef vector<vector<int>> matrix_t;

void makeTable(set_of_times& table, set_of_times time){
    int index =0;
    for(int i=1; i< time.size(); i++){
        int start = table[index].second;
        if(start <= time[i].first){
            table.push_back(make_pair(time[i].first,time[i].second));
            index++;
            //cout << time[i].first << " " << time[i].second << "\n";
        }
    }
}

int main(void){
    int n, s,e; 
    cin >> n;
    set_of_times time, table;

    for(int i=0; i<n; i++){
        cin >> s >> e;
        time.push_back(make_pair(s,e));
        //cout << time[i].first << " " << time[i].second << "\n";
    }
    table.push_back(time[0]);
    makeTable(table, time);
    cout << table.size() <<"\n";
    for(auto e : table)
        cout << e.first << " " << e.second <<"\n";
}