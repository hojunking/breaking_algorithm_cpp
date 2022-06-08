#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int n;
int cnt = 0;
vector<int> col;

int promising(int i){
    int k = 1;
    int flag =1;
    while(k < i && flag){
        if((col[i] == col[k]) || (abs(col[i] - col[k]) == i -k))
            flag = 0;
        k++;
    }
    return flag;
}

void queens(int i){
    if(promising(i)){
        if(i == n) cnt++;
        else
            for(int j =1; j<=n; j++){
                col[i+1] = j; //queen move row+1
                queens(i+1);
            }
        
    }
}

int main(void){
    cin >> n;
    col.resize(n+1,0);
    queens(0);
    cout << cnt;
}