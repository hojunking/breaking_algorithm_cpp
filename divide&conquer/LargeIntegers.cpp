#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector<int> LargeInteger;
int thredhold, cnt =0;


void printInt(LargeInteger r);
void make_int(string a, LargeInteger& u);
void remove_leading_zeros(LargeInteger& v);
void roundup_carry(LargeInteger& v);
void ladd(LargeInteger a, LargeInteger b,LargeInteger&c);
void lmult(LargeInteger a, LargeInteger b, LargeInteger& c);
void power_exp(LargeInteger u, int m, LargeInteger& v);
void div_exp(LargeInteger u, int m, LargeInteger& v);
void rem_exp(LargeInteger u, int m, LargeInteger& v);
void prod(LargeInteger u, LargeInteger v, LargeInteger& r);


int main(void){
    cin >> thredhold;
    string a,b;
    cin >> a >> b;
    LargeInteger u,v,r;
    make_int(a,u);
    make_int(b,v);
    prod(u,v,r);
    printInt(r);
}

void printInt(LargeInteger r){
    cout << cnt << "\n";
    if(r.size() == 0)
        cout << 0;
    else{
        for(int i = r.size()-1; -1 <i ; i--){
            cout << r[i];
        }
    }
}

void prod(LargeInteger u, LargeInteger v, LargeInteger& r){
    cnt++; // 재귀호출이 4->3
    LargeInteger x,y,w,z;
    LargeInteger t1,t2,t3,t4,t5,t6,t7,t8;
    int n = max(u.size(), v.size());
    if(u.size() == 0 || v.size() == 0)
        r.resize(0);
    else if(n <= thredhold)
        lmult(u,v,r);
    else{
        int m = n /2;
        div_exp(u,m,x); rem_exp(u,m,y);
        div_exp(v,m,w); rem_exp(v,m,z);
        prod(x,w,t1);// x*w
        power_exp(t1,m*2,t2); // xw* 10^2m

        prod(x,z,t3); prod(w,y,t4); //xz, wy
        ladd(t3,t4,t5); //xz + wy

        power_exp(t5,m,t6); // (xz+wy)*10^m
        prod(y,z,t7); //yz

        ladd(t2,t6,t8); //xw* 10^2m + (xz+wy)*10^m
        ladd(t8,t7,r); // xw* 10^2m + (xz+wy)*10^m + yz
    }
}

void make_int(string a, LargeInteger& u){ //문제 없음
    u.resize(a.length());
    for(int i= 1; i <= u.size(); i++)
        u[a.length()-i] = a[i-1] -'0';
}

void roundup_carry(LargeInteger& v){
    int carry=0;
    for(int i =0; i < v.size(); i++){
        v[i] += carry;
        carry = v[i] / 10;
        v[i] = v[i] % 10;
    }
    if(carry != 0)  
        v.push_back(carry);
}

void ladd(LargeInteger a, LargeInteger b,LargeInteger&c){
    c.resize(max(a.size(), b.size()));
    fill(c.begin(), c.end(), 0);
    for(int i =0; i<c.size(); i++){
        if(i <a.size()) c[i] += a[i];
        if(i <b.size()) c[i] += b[i];
    }
    roundup_carry(c);
}

void lmult(LargeInteger a, LargeInteger b, LargeInteger& c){
    c.resize(a.size()+ b.size() -1);
    fill(c.begin(), c.end(), 0);
    for(int i=0; i<a.size(); i++)
        for(int j=0; j <b.size(); j++)
            c[i+j] += a[i]*b[j];
    roundup_carry(c);
}

void power_exp(LargeInteger u, int m, LargeInteger& v){
    if(u.size() == 0)
        v.resize(0);
    else{
        v.resize(u.size() + m); // 사이즈 초기화
        fill(v.begin(), v.end(), 0) ; // 0으로 초기화
        copy(u.begin(), u.end(), v.begin() + m); //거꾸로 붙이고, m의 자리수 만큼 뒤로
    }
}
void remove_leading_zeros(LargeInteger& v){
    while(v.size()!=0 && v.back() ==0)
    v.pop_back();
}


void rem_exp(LargeInteger u, int m, LargeInteger& v){
    if(u.size() == 0)
        v.resize(0);
    else{
        int k = m < u.size() ? m : u.size();
        v.resize(k);
        copy(u.begin(), u.begin() +k, v.begin());
        remove_leading_zeros(v);
    }
}
void div_exp(LargeInteger u, int m, LargeInteger& v){
    if(u.size() <= 0)
        v.resize(0);
    else{
        if(m >= u.size())
            v.resize(0);
        else{
            v.resize(u.size() - m);
            copy(u.begin() + m, u.end(),v.begin());
            remove_leading_zeros(v);
        }
    }
}