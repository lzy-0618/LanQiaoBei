#include<iostream>

using namespace std;

/*
С��׼���� 256MB ���ڴ�ռ俪һ�����飬
�����ÿ��Ԫ�ض��� 32λ ������������
��������ǳ���ռ�õĿռ��ά���ڴ���Ҫ�ĸ����ռ䣬
���� 256MB �Ŀռ���Դ洢���ٸ� 32 λ������������
*/ 
int main(){
	// 1 B ��1 �ֽڣ� = 8 bit ��λ�� 
	int sum,ge,res;
	sum = 256 * 1024 * 1024;
	ge = 4;
	res = sum / ge;
	cout << res << endl; 
	return 0;
} 


