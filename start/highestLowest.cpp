#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i <n;i++){
        cin >> v[i];
    }
    int h=v[0],l=v[0];
    for(int j =1; j <n; j++){
        if(v[j] > h)
            h = v[j];
        else if(v[j] < l)
            l = v[j];
    }
    cout << l << "\n" << h;
}