#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
using namespace std;
#define INF 999999
typedef vector<vector<int>> matrix_t;
typedef struct node* node_ptr;

typedef struct node {
    int key;
    node_ptr left;
    node_ptr right;
}node_t;


void preOrder(node_ptr node, vector<int>& pre){
    if(node){
        //cout << node->key << " ";
        pre.push_back(node->key);
        preOrder(node->left,pre);
        preOrder(node->right, pre);
    }
}

void inOrder(node_ptr node, vector<int>& in){
    if(node)
    {
        preOrder(node->left,in);
        in.push_back(node->key);
        preOrder(node->right,in);
    }
}

void search(node_ptr tree, int keyin, node_ptr& p){ //포인터 타입 참조
    bool found;
    found = false;
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
    for(int k =i; k <=j; k++){
        
        value = A[i][k-1] + A[k+1][j];
        for(int l=i; l<=j; l++)
            value += p[l];
        
        if(minValue > value){
            minValue = value;
            mink = k;
        }
    }
    
    return minValue;
}


void optSearchTree(int n, vector<int>& p, matrix_t& A, matrix_t& R){
    int k;
    for(int i =1; i <=n; i++){
        A[i][i-1] =0; A[i][i] = p[i];
        R[i][i-1] =0; R[i][i] =i;
    }
    A[n + 1][n] = 0;
    R[n + 1][n] = 0;

    for(int diagonal =1; diagonal <= n-1; diagonal++){
        for(int i =1; i <= n - diagonal; i++){
            int j = i + diagonal;
            A[i][j] = minimum(i,j,k,p,A);
            R[i][j] = k;
        }
    }
}

void printMatrix(int n, matrix_t& T){
    for(int i =1; i <=n+1; i++){
        for(int j=i-1; j <=n; j++){
            if(j == i-1)
                cout << T[i][j];
            else
                cout << " " <<T[i][j];
        }
        cout << "\n";
    }
}

node_ptr tree(int i, int j, vector<int>& keys, matrix_t& R){
    int k = R[i][j];
    if(k==0)
        return NULL;
    else{
        //node_ptr nNode = createNode(keys[k]);
        node_ptr nNode = new node_t;
        nNode->key = keys[k];
        nNode->left = tree(i,k-1,keys,R);
        nNode->right = tree(k+1,j,keys,R);
        return nNode; 
    }
}

int main(void){
    int n; cin >> n; // key의 개수 n
    
    vector<int> K(n+1,0);
    for(int i=1; i<=n; i++) //input keys
        cin >> K[i];
    
    vector<int> p(n+1,0);
    for(int i=1; i<=n; i++) //빈도
        cin >> p[i];

    matrix_t A, R;

    A.resize(n + 2, vector<int>(n + 2, 0));
    R.resize(n + 2, vector<int>(n + 2, 0));
    optSearchTree(n, p,A,R);

    printMatrix(n,A);
    printMatrix(n,R);

    node_ptr root = tree(1,n,K,R);
    vector<int> pre; //초기화시키면 push_back() 0 뒤로 붙습니다
    vector<int> in;

    cout << A[1][n] << "\n";

    preOrder(root,pre);
    inOrder(root,in);

    for(int i=0; i <pre.size(); i++) //pre
        if(i == 0) cout << pre[i];
        else cout << " " << pre[i];
    cout << "\n";
    
    for(int i=0; i <in.size(); i++) //in
        if(i ==0) cout << in[i];
        else cout << " " << in[i];      
    cout << "\n";

}