#include <iostream>
#include <vector>
#include <math.h>
#define MAX 5000000

using namespace std;

int n;
int minFactor[MAX+1];

void updateFactor(){
  for (int i=2; i<=MAX; i++)
    minFactor[i] = i;
  
  for (int i=2; i<=sqrt(MAX); i++)
    if (minFactor[i] == i)
      for (int j=i*i; j<=MAX; j+=i)
        if (minFactor[j] == j)
          minFactor[j] = i;
}

void solve(int num){
  while (num > 1){
    cout << minFactor[num] << " ";
    num /= minFactor[num];
  }
  cout << endl;
}

int main(){
  //cin >> n;

  updateFactor();
    for(int i=2; i<=10; i++)
        cout << minFactor[i] << " ";
    int num;
    cin >> num;
    solve(num);

}