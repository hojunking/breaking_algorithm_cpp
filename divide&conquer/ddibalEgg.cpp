#include <iostream>

//마술의 탑
using namespace std;
int main() {
    int num;
    int cnt=1;
    int sum=0;
    cin >> num;
    while(sum<num)
    {
    sum+=cnt++;
    }
    cout << cnt-1;
    return 0;
}