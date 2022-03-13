#include <iostream>
#include <map>
#include <utility>
using namespace std;

int main(){
    //key - value를 mapping시켜주는 것!!
    // JAVA는 HashMap이 있다
    map<int, string> myMap; //pair
    int n;
    cin >> n;
    for(int i =0; i <n; i++){
        int num;
        cin >> num;
        string str;
        cin >> str;
        myMap[num] = str;
    }
    //for(auto item: myMap) //auto = pair<int, string>의 형태
        for(pair<int,string> item : myMap)
        cout << item.first <<" :" << item.second << "\n";
}