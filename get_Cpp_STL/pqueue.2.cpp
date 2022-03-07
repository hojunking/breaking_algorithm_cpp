#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct mycompare {
    bool operator() (string s1, string s2){
        return s1.length() < s2.length(); //두 문자열의 길이 비교(내림 오름 변경가능)
    }
};

int main(void){
    int n;
    cin >> n;
    //priority_queue<string, vector<string>> pq; //내림차순
    priority_queue<string, vector<string>, mycompare> pq; //mycompare 구조체를 이용
    for(int i = 0; i <n; i++){ //알파벳(ASKI순서)
        string x;
        cin >>x;
        pq.push(x);
    }
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << "\n";
}