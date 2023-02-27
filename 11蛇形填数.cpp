#include<iostream>

using namespace std;
// 将一个连续的过程 切分成有规律的几个子过程
// 然后循环循环即可。

int map[40][40];
int row = 0, col = 0, num = 1;

int main(){

	map[0][0] = num;

	while(!map[19][19]){

		// 右移
		map[row][++col] = ++num;

		// 左下移
		while(col){
			map[++row][--col] = ++num;
		}

		// 下移
		map[++row][col] = ++num;

		// 右上移
		while(row){
			map[--row][++col] = ++num;
		}
	}


	cout << map[19][19] << endl;

	return 0;
}