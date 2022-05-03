#include <iostream>
#include <vector>
using namespace std;

int n; int cnt =0;
vector<int> col(n+1,0);

void printHigh(){
    cnt++;
    for (int j = 1; j <= n; j++)
        if (j < n)
            cout << col[j];
        else 
            cout << col[j] << "\n";
}

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
        if(i == n)
            printHigh();
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
    queens(0);
    cout << cnt;
}