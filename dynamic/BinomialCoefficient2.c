// c로 구현한 이항계수 최적화
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define min(x, y) (x) < (y) ? (x) : (y)

typedef unsigned long long int LongInteger; //Maxsize module 계산 시 LongInteger는 필요없다...

int Max;

LongInteger bin3(int n, int k) {
    if (k > n / 2)
        k = n - k;
    LongInteger* B = (LongInteger*)malloc((k+1) * sizeof(LongInteger));
    memset(B,0,k*sizeof(LongInteger));

    B[0] = 1;

    for (int i = 1; i < n + 1; i++) {
        int j = min(i, k);
        while (j > 0) {
            B[j] = (B[j] + B[j - 1]) % Max;
            j--;
        }
    }
    LongInteger result = B[k];
    free(B);
    return result;
}


int main(void) {
    int n, k;

    scanf("%d %d %d",&n,&k,&Max);
    printf("%llu\n",bin3(n,k));
}