#include <iostream>
#include <queue>
using namespace std;

int main(void){
    int n;
    cin >> n;
   // priority_queue<int> pq; //최대힙(내림차순)
    //priority_queue<int, vector<int>,greater<int>> pq; // 
    //최소힙(오름차순)
    priority_queue<int, vector<int>, less<int>> pq;//내림차순
    for(int i = 0; i <n; i++){
        int x;
        cin >>x;
        pq.push(x);
    }
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << "\n";
}