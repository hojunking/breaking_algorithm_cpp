#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100

void find_path(int, int, int);
int cnt = 0;
int a[MAX][MAX], D[MAX][MAX];

int main() {
    int N;
    //배열 구현
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    //맨 밑에 줄을 따로 배열로 지정
    for (int i = N - 1; i < N; i++) {
        for (int j = 0; j < N; j++) {
            D[i][j] = a[i][j];
        }
    }

    for (int i = N - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (D[i][j] >= D[i][j + 1]) {
                D[i - 1][j] = a[i - 1][j] + D[i][j];
            }
            else {
                D[i - 1][j] = a[i - 1][j] + D[i][j + 1];
            }
        }
    }

    printf("%d\n", D[0][0]);
    printf("%d ", a[0][0]);
    find_path(N, 0, 0);
}

void find_path(int n, int i, int j) {

    if (D[i + 1][j] <= D[i + 1][j + 1]) {
        printf("%d ", a[i + 1][j + 1]);
        cnt++;
        if (cnt != (n - 1)) {
            find_path(n, i + 1, j + 1);
        }
    }
    else {
        printf("%d ", a[i + 1][j]);
        cnt++;
        if (cnt != (n - 1)) {
            find_path(n, i + 1, j);
        }
    }
}