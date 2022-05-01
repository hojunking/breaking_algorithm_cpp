#include <iostream>
#include <vector>
using namespace std;

typedef struct item *link;
typedef struct item{
    int id;
    int weight;
    int profit;
    int profit_per_unit;
}item_t;
int n,W,T;
vector<item_t> items;

void bubbleSort(){
    for(int i=n; i>1; i--){
        for(int j=1; j<i+1; j++){
            cout << items[j].profit <<"\n";
            if(items[j].profit < items[j+1].profit)
            swap(items[j],items[j+1]);
        }
    }
}

bool compare_item(item_t i, item_t j){
    if(i.profit_per_unit > j.profit_per_unit)
        return true;
    else return false;
}

void knapsack1(int& maxprofit, int& totweight){
    maxprofit = totweight = 0;
    for(int i=1; i<=n; i++){
        if(totweight + items[i].weight <= W){
            maxprofit += items[i].profit;
            totweight += items[i].weight;
        }else{
            maxprofit += (W-totweight) * items[i].profit_per_unit;
            totweight += (W-totweight);
            break;
        }
    }
}
int main(void){
    cin >> n;
    items.resize(n+1);
    for(int i=1; i<=n; i++)
        cin >> items[i].weight;
    for(int i=1; i<=n; i++)
        cin >> items[i].profit;
    cin >> T >> W;
    bubbleSort();
    int maxprofit, totweight;
    knapsack1(maxprofit,totweight);
    cout << maxprofit;

    

}