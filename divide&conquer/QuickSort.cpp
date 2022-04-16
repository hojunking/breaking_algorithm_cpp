#include <iostream>
#include <vector>
using namespace std;
/*
    divide & conquer - quick_sort
*/
int cnt =0;
int partition(vector<int>& S, int low, int high){
    cnt++;
    int pivot =S[low];
    int j = low;
    for(int i = low +1; i <=high; i++)
        if(S[i] < pivot){
            j++;
            swap(S[i],S[j]);
        }
    swap(S[low],S[j]);
    return j;
}

void quickSort(vector<int>& S ,int low, int high){
    if(low < high){
    int pivotPoint =partition(S,low, high);
        quickSort(S,low,pivotPoint -1);
        quickSort(S,pivotPoint+1,high);
    }
}

int main(void){
    int n;
    cin >> n;
    vector<int> S(n+1);
    for(int i =1; i <n+1; i++)
        cin >> S[i];
    partition(S,1,n);
    for(int i =1; i <n+1; i++){
        if(i<n)
        cout << S[i] << " ";
        else cout << S[i];
        }
    cout << "\n"; cnt =0;
    quickSort(S,1,n);
    cout << cnt <<"\n";
    for(int i =1; i <n+1; i++){
       if(i<n)
        cout << S[i] << " ";
        else cout << S[i];
        }
}