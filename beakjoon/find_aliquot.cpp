#include <iostream>
#include <vector>

typedef unsigned long long int LONG;
using namespace std;


int n;
int findMax(vector<int> A){
    int max = 0;
    for(int i=0; i<n; i++)
        if(A[i] > max) max = A[i];
    return max;
}

int findMin(vector<int>A){
    LONG min = 1000000;
    for(int i=0; i<n; i++)
        if(min > A[i]) min = A[i];
    return min; 
}

int main(void){
    cin >> n;
    vector<int> A(n);
    
    for(int i=0; i<n; i++)
        cin >> A[i];

    cout << findMax(A)*findMin(A);
}