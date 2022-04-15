#include <iostream>
#include <vector>
using namespace std;

void binarySearch(int n, vector<int>& v){
    int cnt =0, mid=0,low=0,high=n-1;
    //cout << high << " " << low << "\n";
    while(low <= high){
        cnt++;
        //cout << "cycle = " << cnt <<"\n";
        mid = (low + high) /2;
        if (v[mid] == mid){
            cout << mid << "\n" << cnt <<"\n";
            return;
        }
        else if(v[mid] > mid){
            high = mid -1;
        }
        else
            low = mid +1;
    }
    cout << -1 << "\n" << cnt << "\n";
    return;
}

int main(void){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i =0; i <n; i++){
        cin >> v[i];
    }
    binarySearch(n,v);
    return 0;
}