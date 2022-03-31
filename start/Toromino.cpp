#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> matrix_t;

int whereIs(int n, int srow, int scol, int row, int col){
    int  m  = n/2;
    if(row - srow < m){
        if(col - scol < m)
            return 1;
        else
            return 2;
        }
    else{
        if(col - scol < m)
            return 3;
        else return 4;
    }
}

void fill(int n, matrix_t& t, int srow, int scol, int where){
    if(where !=1) t[srow][scol] =n;
    if(where !=2) t[srow][scol+1] =n;
    if(where !=3) t[srow+1][scol] =n;
    if(where !=4) t[srow+1][scol+1] =n;
}

int rowhole(int part, int where, int n, int srow, int row){
    int  m = n / 2;
    if(part != where){
        row = srow + m -1;
        if(part == 3 || part ==4)
            row +=1;
    }
    return row;
}

int colhole(int part, int where, int n, int scol, int col){
    int  m = n / 2;
    if(part != where){
        col = scol + m -1;
        if(part == 2 || part ==4)
            col +=1;
    }
    return col;
}

void toromino(int n, matrix_t& t, int srow, int scol, int row, int col){
    int where = whereIs(n,srow,scol,row,col);
    if(n==2){
        fill(n,t,srow, scol, where);
    }
    else{
        int m = n / 2;
        int hrow, hcol;
        fill(n, t, srow + m - 1, scol + m - 1, where);
        hrow= rowhole(1, where, n, srow, row);
        hcol= colhole(1, where, n, scol, col);
        toromino(m, t, srow, scol, hrow, hcol);

        hrow= rowhole(2, where, n, srow, row);
        hcol= colhole(2, where, n, scol, col);
        toromino(m, t, srow, scol+m, hrow, hcol);

        hrow= rowhole(3, where, n, srow, row);
        hcol= colhole(3, where, n, scol, col);
        toromino(m, t, srow+m, scol, hrow, hcol);

        hrow= rowhole(4, where, n, srow, row);
        hcol= colhole(4, where, n, scol, col);
        toromino(m, t, srow+m, scol+m, hrow, hcol);
    }
}

void print_board(int n, matrix_t t){
    for(int i =0; i < n ;i++){
        for(int j =0; j <n; j++)
            cout << t[i][j] <<" ";
    cout << "\n";
    }
    
}

int main(void){
    int n, row, col;
    cin >> n >> row >> col;
    matrix_t t(n, vector<int>(n));
    int srow =0 , scol = 0;
    toromino(n,t,srow,scol,row,col);
    print_board(n, t);
}