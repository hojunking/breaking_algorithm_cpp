#include <iostream>
#include <vector>
using namespace std;

int cnt =0;

void merge(vector<int>& S, int low, int mid, int high){
    cnt++;
    int i = low, j = mid +1, k = 0;
    vector<int> U(high-low +1);

    while(i <= mid && j <= high)
        U[k++] = (S[i] < S[j]) ? S[i++] : S[j++];
    if (i > mid)
    while(j <= high)
        U[k++] = S[j++];
    else
    while(i <= mid)
        U[k++] = S[i++];
    
    for(int t = low; t <= high; t++)
        S[t] = U[t - low];
}

void mergeSort(vector<int>& S, int left, int right){
    if(left < right){
        int mid = (left + right) /2;
        mergeSort(S,left, mid);
        mergeSort(S,mid+1,right);
        merge(S,left,mid,right);
    }
}

int main(void){
    int n;
    cin >> n;
    vector<int> S(n);
    for(int i=0; i<n; i++){
        cin >> S[i];
    }
    mergeSort(S,0,n-1);
    cout << cnt << "\n";
    for(int it : S)
        cout << it <<" ";
}