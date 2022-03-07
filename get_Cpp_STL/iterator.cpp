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
    v.push_back(5);
    //vector<int>::iterator it; //auto it;
    //auto it = v.begin();
    //end -> 맨 마지막(size) 원소의 다음을 가르킴
    sort(v.begin(), v.end()+3); //정렬함수
    for(auto& it : v)
        cout << it << " ";

}