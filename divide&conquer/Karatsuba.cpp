#include <iostream>
#include <string>
#include <cmath>
using namespace std;

typedef unsigned long long largeInt;

const int threshold =1;

int digit(largeInt v){
    return (v == 0) ? 0 : to_string(v).length(); //최대 길이
}

largeInt div_exp(largeInt v, int m){
    for(int i=0; i<m; i++)
        v /= 10;
    return v;
}

largeInt rem_exp(largeInt v, int m){
    int exp = 1;
    for(int i=0; i< m; i++)
         exp *=10;
    return v % exp;
}

largeInt pow_exp(largeInt v, int m){
    for(int i=0; i<m; i++)
        v *= 10;
    return v;
}


largeInt karatsuba(largeInt u, largeInt v){
    cnt++;
    largeInt x,y,w,z,p,q,r;
    int n = max(digit(u), digit(v)); // n => max 길이
    if( u==0 || v==0)
        return 0;
    else if(n <= threshold)
        return u * v;
    else{
        int m = n/2; //최대 길이 /2
        x = div_exp(u,m); y = rem_exp(u,m);
        w = div_exp(v,m); z = rem_exp(v,m);
        r = karatsuba(x+y, w+z);
        p = karatsuba(x,w); //x*w => p
        q = karatsuba(y,z);// y*z => q
        return pow_exp(p,2*m) + pow_exp(r-p-q, m) + q;
    }
}

int main(void){
    cout << "input two integer : "; 
    largeInt a, b; cin >> a >> b;
    largeInt c = karatsuba(a,b);
    cout <<"answer :" << c << "\n";
}