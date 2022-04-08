#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
using namespace std;
#define INF 999
typedef vector<vector<int>> matrix_t;

struct List
{

    vector<int> A;
    vector<int> B;
};

void floyd2(int n, matrix_t &W, matrix_t &D, matrix_t &P)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            D[i][j] = W[i][j];
            P[i][j] = 0;
        }
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (D[i][j] > D[i][k] + D[k][j])
                {
                    D[i][j] = D[i][k] + D[k][j];
                    P[i][j] = k;
                }
}

void path(matrix_t &P, int u, int v, vector<int> &p)
{
    int k = P[u][v];
    if (k != 0)
    {
        path(P, u, k, p);
        p.push_back(k);
        path(P, k, v, p);
    }
}

void inputPInfo(int m, matrix_t &W)
{
    int u, v, w;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        W[u][v] = w;
    }
}
void printPInfo(int n, matrix_t A)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // printf("%3d ",A[i][j]);
            if(j==n)
                cout << A[i][j];
            else
                cout << A[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(void)
{
    int n, m, c;
    cin >> n >> m;
    matrix_t W(n + 1, vector<int>(n + 1, INF));
    matrix_t D(n + 1, vector<int>(n + 1, INF));
    matrix_t P(n + 1, vector<int>(n + 1, INF));
    List list;

    for (int i = 1; i <= n; i++)
        W[i][i] = 0;

    inputPInfo(m, W);

    cin >> c;

    int u, v;

    for (int i = 0; i < c; i++)
    {
        cin >> u >> v;
        list.A.push_back(u);
        list.B.push_back(v);
    }
    floyd2(n, W, D, P);

    printPInfo(n, D);
    printPInfo(n, P);

    int t1, t2;
    for (int i = 0; i < c; i++)
    {

        vector<int> p;

        t1 = list.A[i], t2 = list.B[i];

        path(P, t1, t2, p);

        if (D[t1][t2] == 999)
            cout << "NONE"
                 << "\n";

        else
        {
            cout << t1;

            for (int j = 0; j < p.size(); j++)
                cout << " " << p[j];

            cout << " " << t2 << "\n";
        }
    }
}