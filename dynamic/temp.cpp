#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
using namespace std;
#define INF 999999
typedef vector<vector<int>> matrix_t;
typedef struct node* node_ptr;
typedef struct node
{
    int key;
    node_ptr left;
    node_ptr right;
} node_t;

void preorder(node_ptr np, vector<int>& preary)
{
    if (np) 
    {
        preary.push_back(np->key);
        preorder(np->left, preary);
        preorder(np->right, preary);
    }
}

void inorder(node_ptr np, vector<int>& inary)
{
    if (np)
    {
        inorder(np->left, inary);
        inary.push_back(np->key);
        inorder(np->right, inary);
    }
}


void search(node_ptr tree, int keyin, node_ptr& p)
{
    bool found;
    p = tree;
    found = false;
    while (!found)
    {
        if (p->key == keyin)
            found = true;
        else if (keyin < p->key)
            p = p->left;
        else // keyin > p->key
            p = p->right;
    }
}
int minimum(int i, int j, int& mink, vector<int>& p, matrix_t& A)
{
    int minValue = INF, value;
    for (int k = i; k <= j; k++) 
    {
        value = A[i][k - 1] + A[k + 1][j];
        for (int m = i; m <= j; m++) 
            value = value + p[m];

        if (minValue > value) 
        {
            minValue = value;
            mink = k;
        }
    }
    return minValue;
}

void optsearchtree(int n, vector<int>& p, matrix_t& A, matrix_t& R)
{
    int k;
    for (int i = 1; i <= n; i++)
    {
        A[i][i - 1] = 0; A[i][i] = p[i];
        R[i][i - 1] = 0; R[i][i] = i;
    }

    // Output for 0
    A[n + 1][n] = 0;
    R[n + 1][n] = 0;
    for (int diagonal = 1; diagonal <= n - 1; diagonal++)
        for (int i = 1; i <= n - diagonal; i++)
        {
            int j = i + diagonal;
            A[i][j] = minimum(i, j, k, p, A);
            R[i][j] = k;
        }
}


node_ptr tree(int i, int j, vector<int>& keys, matrix_t& R)
{
    int k = R[i][j];
    if (k == 0)
        return NULL;
    else 
    {
        //node_ptr node = create_node(keys[k]);

        node_ptr node = new node_t;// Create Node
        node->key = keys[k];// Allocate keys[k] value in Node member key in Node
        node->left = tree(i, k - 1, keys, R);
        node->right = tree(k + 1, j, keys, R);
        return node;
    }
}

int main()
{
    int n, temp;
    matrix_t A, R; vector<int> k, p, inary, preary; node_ptr root;

    cin >> n;
    A.resize(n + 2, vector<int>(n + 2, 0)); R.resize(n + 2, vector<int>(n + 2, 0));
    k.push_back(0); p.push_back(0);// Starting at index 1

    // Array k input
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        k.push_back(temp);
    }

    //Array p input
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        p.push_back(temp);
    }
    optsearchtree(n, p, A, R);

    // Print Array A
    for (int i = 1; i <= n + 1; i++)
    {
        for (int j = i - 1; j <= n; j++)
        {
            if (j == i - 1)
                cout << A[i][j];
            else
                cout << " " << A[i][j];
        }
        cout << "\n";
    }

    // Print Array R
    for (int i = 1; i <= n + 1; i++)
    {
        for (int j = i - 1; j <= n; j++)
        {
            if (j == i - 1)
                cout << R[i][j];
            else
                cout << " " << R[i][j];
        }
        cout << "\n";
    }
    root = tree(1, n, k, R);

    // Opt
    cout << A[1][n] << "\n";
    // Traverse Node
    preorder(root, preary);
    inorder(root, inary); 
    for (int i = 0; i < preary.size(); i++)
    {
        if (i == 0)
            cout << preary[i];
        else
            cout << " " << preary[i];
    }
    cout << "\n";
    for (int i = 0; i < inary.size(); i++)
    {
        if (i == 0)
            cout << inary[i];
        else
            cout << " " <<inary[i];
    }
    cout << "\n";
}