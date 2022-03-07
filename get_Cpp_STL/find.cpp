#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i =0; i <n; i++){
        cin >> v[i];
    }
    
    //find 10
    int x;
    cin >> x;
    auto it = find(v.begin(), v.end(), x);
    if(it != v.end()) //iterater가 end()까지 왔을 경우 -> 없다
        cout << "I found "<<*it <<"!" <<"\n";
    else
        cout << "I can't find!" <<"\n";
}