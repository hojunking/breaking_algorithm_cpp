#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int>> matrix_t; // 타입선언을 해도 된다.
//vector<vector<int>> v; //전역변수 선언방식

matrix_t v; //타입선언 들고오기
int main(){  //이차원 vector를 구현합니다.
    int n,m;
    cin >> n >> m;
    v.resize(n, vector<int>(m)); //크기 지정
    //vector<vector<int>> v(n, vector<int>(m));
    for(int i =0; i <n ; i++){
        for(int j = 0; j <m; j++){
            cin >> v[i][j];
        }
    }
    for(int i =0; i <m ; i++){
        for(int j = 0; j <n; j++){
            cout << v[j][i] << " ";
        }
        cout << "\n";
    }
}