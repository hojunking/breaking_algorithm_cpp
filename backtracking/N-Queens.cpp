#include <iostream>
#include <vector>
#include <utility>
#include <string>
using namespace std;

int n,p =0;
vector<int> col;
vector<string> M;
typedef unsigned long long LONG;

bool promising(int i){
    int k =1;
    bool flag = true;

    while(k < i && flag){
        if((col[i] == col[k]) || (abs(col[i] - col[k]) == i-k))
            flag = false;
        k++;
    }
    return flag;
}

void queens(int i){
    int j;
    if(promising(i)){
        if(i == n){
            p++;
            string tmp ="";
            for (int u = 1; u <= n; u++)
                tmp += to_string(col[u]);
                
           // cout << tmp << "\n";
           M.push_back(tmp);
        }
        else{
            for(j =1; j <=n; j++){
                col[i+1] = j;
                queens(i+1);
            }
        }
    }
}
int main(void){
    cin >> n;
    col.resize(n+1,0);

    queens(0);
    cout << p <<"\n";
    LONG max =0;
    for(int i=0; i<p; i++){
        LONG tmp = stoull(M[i]);
        if(tmp > max)
            max = tmp;
    }
    cout << max << "\n";
}