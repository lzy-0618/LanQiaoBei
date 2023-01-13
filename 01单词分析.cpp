#include <iostream>
#include <string>

int zifu_num[26];
char max_zifu = 'a';
int  max_num = 0;

using namespace std;
int main() {

	string danci;
	cin >> danci;
	for(int i = 0; i< danci.length(); ++i) {
		int pos = danci[i] - 'a';
		++zifu_num[pos];
	}

	for(int i = 0; i<26; ++i) {
		if(zifu_num[i] > max_num) {
			max_zifu = 'a' + i;
			max_num = zifu_num[i];
		}
	}
	cout << max_zifu << endl;
	cout << max_num << endl; 

	return 0;
}
