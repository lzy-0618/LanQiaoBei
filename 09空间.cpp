#include<iostream>

using namespace std;

/*
小蓝准备用 256MB 的内存空间开一个数组，
数组的每个元素都是 32位 二进制整数，
如果不考虑程序占用的空间和维护内存需要的辅助空间，
请问 256MB 的空间可以存储多少个 32 位二进制整数？
*/ 
int main(){
	// 1 B （1 字节） = 8 bit （位） 
	int sum,ge,res;
	sum = 256 * 1024 * 1024;
	ge = 4;
	res = sum / ge;
	cout << res << endl; 
	return 0;
} 


