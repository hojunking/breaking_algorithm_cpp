#include <iostream>
#include <vector>
using namespace std;

void getPrime(int a, int b) {
	vector<int> list(b+1);
    
    for (int i = 2; i <= b; i++)
		list[i] = i;
	for (int i = 2; i * i <= b; i++) {
		if (list[i] == 0) continue;
		for (int j = i + i; j <= b; j += i)
			list[j] = 0;
	}
	for (int i = a; i <= b; i++) {
		if (list[i] != 0) cout << list[i] << "\n";
	}
}

int main(void) {
	int a, b;
	cin >> a >> b;
	getPrime(a, b);
}