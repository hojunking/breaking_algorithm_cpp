#include <iostream>
#include <map>
#include <utility>
using namespace std;

int main(){
    //key - value를 mapping시켜주는 것!!
    // JAVA는 HashMap이 있다
    map<string, int> myMap; //pair
    int n;
    cin >> n;
    for(int i =0; i <n; i++){
        string str;
        cin >> str;
        if(myMap.find(str) == myMap.end())
            myMap[str] = 1;
        else
            myMap[str] =myMap[str] +1; //string에 따라서 카운트++ 해준다 즉, string이 나타난 횟수를 나타낼 수 있다.
    }
    //for(auto item: myMap) //auto = pair<int, string>의 형태
        for(pair<string,int> item : myMap)
        cout << item.first <<" :" << item.second << "\n";
}