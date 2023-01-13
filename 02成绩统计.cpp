#include<iostream>


using namespace std;

int main() {


	int n;
	int jige = 0,youxiu = 0;
	int fenshu;

	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> fenshu;

		if(fenshu >= 85) {
			++youxiu;
			++jige;
		} else if(fenshu >= 60) {
			++jige;
		}
	}

	double you_lv = (double)youxiu / (double)n;
	int you_res = (you_lv + 0.005) * 100;
	double ji_lv = (double)jige / (double)n;
	int ji_res = (ji_lv + 0.005) * 100;

	cout << ji_res <<"%"<<endl;
	cout << you_res << "%"<<endl;

	return 0;
}
