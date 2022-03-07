#include <iostream>
using namespace std;

int get_input(int &n){
    cout << "Input an Integer : ";
    cin >> n;
    return n;
}

int main(void){
    int i;
    get_input(i);
    
    cout << "Hello World!! : "<< i << "\n";
}