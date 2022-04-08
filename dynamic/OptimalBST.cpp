#include <iostream>
#include <vector>
#define INF 999
using namespace std;
typedef vector<vector<int>> matrix_t;
typedef struct node* node_ptr;

typedef struct node {
    int key;
    node_ptr left;
    node_ptr right;
}node_t;

void search(node_ptr tree, int keyin, node_ptr& p){ //포인터 타입 참조
    bool found = false;
    p = tree;
    while(!found){
        if(p->key == keyin)
            found = true;
        else if(keyin < p->key)
            p = p->left;
        else
            p = p->right;
    }
}

int minimum(int i, int j, int& mink, vector<int>& p, matrix_t& A){
    int minValue = INF, value;
    for(int k =i; k <=j-1; k++){
        value = A[i][k-1] + A[k+1][j];
        if(minValue > value){
            minValue = value;
            mink = k;
        }
    }
    int sum=0;

     for(int k=i; k<=j; k++)
         sum += p[k];

    //sum = ((p[j]+1)*p[j] -(p[i]+1)*p[i]) /2;

    return minValue + sum;
}


void optSearchTree(int n, vector<int>& p, matrix_t& A, matrix_t& R){
    int k;
    for(int i =0; i <=n; i++){
        A[i][i-1] =0; A[i][i] = p[i];
        R[i][i-1] =0; R[i][i] =i;
    }
    A[n+1][n] = R[n+1][n] =0;

    for(int diagonal =1; diagonal <= n-1; diagonal++){
        for(int i =1; i <= n - diagonal; i++){
            int j = i + diagonal;
            A[i][j] = minimum(i,j,k,p,A);
            R[i][j] = k;
        }
    }
}

void printMatrix(int n, matrix_t T){
    for(int i =1; i <=n+1; i++){
        for(int j=i-1; j <=n; j++){
            if(j <n)
            cout << T[i][j] << " ";
            else
            cout << T[i][j];
        }
        cout <<"\n";
    }
}

int main(void){
    int n; cin >> n; // key의 개수 n
    
    vector<int> K(n+2);
    for(int i=1; i<=n; i++) //input keys
        cin >> K[i];
    
    vector<int> p(n+2);
    for(int i=1; i<=n; i++) //빈도
        cin >> p[i];
    
    matrix_t A(n+2 ,vector<int> (n+2));
    matrix_t R(n+2 ,vector<int> (n+2));
    optSearchTree(n, p,A,R);

    printMatrix(n,A);
    printMatrix(n,R);
    cout << A[1][n] << "\n";

    
}