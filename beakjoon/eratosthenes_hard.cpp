#include <iostream>
#include <vector>
#define MAX 5000000
using namespace std;

int n;
int factors[MAX+1];
void makeFactors(){
    for(int i=2; i<=MAX; i++)
        factors[i] = i;
    
    for(int i=2; i*i<=MAX; i++)
        if(factors[i] == i)
            for(int j= i*i;j<=MAX; j+=i)
                if(factors[j] == j)
                    factors[j] = i;
}

void printFactors(int num){
    int p = num;
    while(p > 1){
        cout << factors[p] << " ";
        p /= factors[p];
    }
    cout << "\n";
}

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    cin >> n;
    makeFactors();

    for(int i=0; i<n; i++){
        int inp;
        cin >> inp;
        printFactors(inp);
    }

    return 0;
}