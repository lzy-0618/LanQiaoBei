#include<iostream>

using namespace std;
const int N = 101;
int a[N][N],c[N][N],n;

int main(){
	
	cin >> n;
	// ��ʼ�������� 
	for(int i=1;i<n+1;++i){
		for(int j=1;j<i+1;++j){
			cin >> a[i][j];
		}
	}	
	
	c[1][1] = a[1][1];	// ��ʼ����һ��Ԫ��
	 
	for(int i=2;i<n+1;++i){
		for(int j=1;j<i+1;++j){
			c[i][j] = a[i][j] + max(c[i-1][j],c[i-1][j-1]);
		}
	}
	// ��Ϊ�������ߵĴ������������ߵĴ������ܳ���1
	// ������������������һ�е��м�����λ���� 
	cout << max(c[n][(n+1)/2],c[n][(n+2)/2]) << endl; 
		
	return 0;
}
