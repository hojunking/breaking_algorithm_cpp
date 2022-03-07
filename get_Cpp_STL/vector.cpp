#include <iostream>
#include <vector>
using namespace std;

int sum(vector<int>& v){
    int s =0;
    vector<int>::iterator iter;
    for(iter = v.begin(); iter != v.end(); iter++){
        s += *iter;
    }
    return s;
}

int main(void){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i <n;i++){
        cin >> v[i];
    }
    cout << sum(v) <<"\n";
}