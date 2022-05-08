#include <iostream>
#include <vector>

using namespace std;
int W, cnt = 0;
vector<int> include, w;// include 배열은 w 배열의 원소를 넣었냐 안넣었냐

bool promising(int i, int weight, int total) {
   return (weight + total >= W) && (weight == W || weight + w[i + 1] <= W);
}

void sum_of_subsets_for_cnt(int i, int weight, int total) {
   if (promising(i, weight, total)) {
      if (weight == W)
         cnt++;
      else {
         include[i + 1] = true;
         sum_of_subsets_for_cnt(i + 1, weight + w[i + 1], total - w[i + 1]);
         include[i + 1] = false;
         sum_of_subsets_for_cnt(i + 1, weight, total - w[i + 1]);
      }
   }
}

void sum_of_subsets(int i, int weight, int total) {
   if (promising(i, weight, total)) {
      if (weight == W) {
         int f_cnt = 0;// 출력형식

         for (int i = 1; i < include.size(); i++) {
            if (include[i] == 1) {
               f_cnt++;
               if (f_cnt == 1)
                  cout << w[i];
               else
                  cout << " " << w[i];
            }
         }
         cout << endl;

      }
      else {
         include[i + 1] = true;
         sum_of_subsets(i + 1, weight + w[i + 1], total - w[i + 1]);
         include[i + 1] = false;
         sum_of_subsets(i + 1, weight, total - w[i + 1]);
      }
   }
}

int main() {
   int n, weight = 0, total = 0;
   cin >> n >> W;
   include.resize(n + 1, 0);
   w.push_back(0);

   for (int i = 0; i < n; i++) {
      int temp;
      cin >> temp;
      total += temp;
      w.push_back(temp);
   }
   sum_of_subsets_for_cnt(0, 0, total);
   if (cnt == 0)
   {
      cout << cnt << endl;
      return 0;
   }
   else
      cout << cnt << endl;
   sum_of_subsets(0, 0, total);

}