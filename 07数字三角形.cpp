#include<iostream>

using namespace std;
const int N = 101;
int a[N][N],c[N][N],n;

int main(){
	
	cin >> n;
	// 初始化三角形 
	for(int i=1;i<n+1;++i){
		for(int j=1;j<i+1;++j){
			cin >> a[i][j];
		}
	}	
	
	c[1][1] = a[1][1];	// 初始化第一个元素
	 
	for(int i=2;i<n+1;++i){
		for(int j=1;j<i+1;++j){
			c[i][j] = a[i][j] + max(c[i-1][j],c[i-1][j-1]);
		}
	}
	// 因为向左下走的次数与向右下走的次数相差不能超过1
	// 所以最后结果锁定在最后一行的中间两个位置上 
	cout << max(c[n][(n+1)/2],c[n][(n+2)/2]) << endl; 
		
	return 0;
}
