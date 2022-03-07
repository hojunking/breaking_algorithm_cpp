#include <iostream>
#include <utility>
#include <vector>
#define MAX_SIZE 11
using namespace std;

int partition(vector<int>& v, int left, int right);
void quick_sort(vector<int>& v, int left, int right);
void bubble_sort(vector<int>& v, int n){
    for(int i =n; 0<i; i--){
        for(int j = 0; j <i; j++){
            if(v[j] > v[j+1])
                swap(v[j],v[j+1]);
        }
    }
}
int main(void){
    int n;
    cin >> n;
    vector<int> v(n+1);
    for(int i =0; i <n; i++){
        cin >> v[i];
    }
    bubble_sort(v,n);
    //quick_sort(v,0,n-1);
    for(int i =0; i<n; i++){
        cout << v[i] << " ";
    }
}



void quick_sort(vector<int>& v, int left, int right){
    if(left < right){
        int q = partition(v, left, right);
        quick_sort(v,left,q-1);
        quick_sort(v,q+1, right);
    }
}
int partition(vector<int>& v, int left, int right){
    int low =left, high = right+1, pivot = v[left];
    do{
        do{
            low++;
        }while(low <= right && v[low] < pivot);
        
        do{
            high--;
        }while(high >= left && v[high] > pivot);
        
        if(low < high)
            swap(v[low], v[high]);

    }while(low < high);
    swap(v[left],v[high]);
    return high;
}