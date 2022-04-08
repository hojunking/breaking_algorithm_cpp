#include <iostream>
#include <vector>
#define INF 99999
using namespace std;
typedef vector<vector<int>> matrix_t;
typedef struct node* node_ptr;

typedef struct node {
    int key;
    node_ptr left;
    node_ptr right;
}node_t;

node_ptr createNode(int k){
    node_ptr nNode= (node_t*)malloc(sizeof(node_t));
    nNode->key = k;
    nNode->left =NULL;
    nNode->right =NULL;
    return nNode;
}

node_ptr tree(int i, int j, vector<int>& keys, matrix_t& R){
    int k = R[i][j];
    if( k==0)
        return NULL;
    else{
        node_ptr Nnode = createNode(keys[k]);
        Nnode->left = tree(i,k-1,keys,R);
        Nnode->right = tree(k+1,j,keys,R);
        return Nnode; 
    }
}


// void search(node_ptr tree, int keyin, node_ptr& p){ //포인터 타입 참조
//     bool found = false;
//     p = tree;
//     while(!found){
//         if(p->key == keyin)
//             found = true;
//         else if(keyin < p->key)
//             p = p->left;
//         else
//             p = p->right;
//     }
// }

int minimum(int i, int j, int& mink, vector<int>& p, matrix_t& A){
    int minValue = INF, value;
    for(int k =i; k <=j; k++){
        int sum=0;
        for(int l=i; l<=j; l++)
            sum += p[l];
            //sum = ((p[j]+1)*p[j] -(p[i]+1)*p[i]) /2;
        value = A[i][k-1] + A[k+1][j] + sum;
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
    A[n+1][n] = R[n+1][n] =0;

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
            if(j <n)
            cout << T[i][j] << " ";
            else
            cout << T[i][j] << "\n";
        }
    }
}

void preOrder(node_ptr node, vector<int>& pre){
    if(node ==NULL)
        return;
    else{
        //cout << node->key << " ";
        pre.push_back(node->key);
        preOrder(node->left,pre);
        preOrder(node->right, pre);
    }
}

void inOrder(node_ptr node, vector<int>& in){
    if(node ==NULL)
        return;
    else{
        preOrder(node->left,in);
        in.push_back(node->key);
        preOrder(node->right,in);
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
    
    matrix_t A(n+2 ,vector<int> (n+2,0));
    matrix_t R(n+2 ,vector<int> (n+2,0));
    optSearchTree(n, p,A,R);

    printMatrix(n,A);
    printMatrix(n,R);
    cout << A[1][n] << "\n";
    node_ptr root = tree(1,n,K,R);
    vector<int> pre; //초기화시키면 push_back() 0 뒤로 붙습니다
    vector<int> in;

    preOrder(root,pre);
    //cout << "\n";
    inOrder(root,in);
    //cout << "\n";

    for(int i=0; i <pre.size(); i++) //pre
        if(i < pre.size()-1) cout << pre[i] << " ";
        else cout << pre[i] << "\n";

    for(int i=0; i <in.size(); i++) //in
        if(i < pre.size()-1) cout << in[i] << " ";
        else cout << in[i] << "\n";      
}