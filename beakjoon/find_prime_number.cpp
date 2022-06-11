#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


int n;

int findNumber(int f){
    int end = (int) sqrt(f);
    for(int i =2; i<=end; i++){
        if(f % i == 0) return 0;
    }
    return 1;
}


int main(void){
    cin >> n;
    vector<int> A(n);
    
    int k =0;
    for(int i=0; i<n; i++){
        cin >> A[i];
        k += findNumber(A[i]);
    }
    cout << k;


    return 0;
}