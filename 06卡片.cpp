#include<iostream>
using namespace std;

int digit[10];

bool check() {
	for(int i=0; i<10; ++i) {
		if(digit[i] <= 0) {
			return false;
		}
	}
	return true;
}

int main() {

	for(int i=0; i<10; ++i) {
		digit[i] = 2021;
	}

	long long res = 1;
	long long temp,val;
	bool flag = false;
	while(true) {
		temp = res;
		while(temp) {
			val = temp % 10;
			temp /= 10;
			--digit[val];
			if(!check()) {
				flag = true;
				break;
			}
		}
		if(flag) break;
		++res;
	}
	cout << res << endl;
}
