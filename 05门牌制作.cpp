#include<iostream>
using namespace std;


int main(){
	
	int num = 0;
	int a,b,c,d;
	for(int i=1;i<2021;++i){
		a = i / 1000;
		b = (i % 1000) / 100;
		c = (i % 100) / 10;
		d = i % 10;
		if(a == '2' - '0') ++num;
		if(b == '2' - '0') ++num; 
		if(c == '2' - '0') ++num; 
		if(d == '2' - '0') ++num;  
	}	
	
	cout << num << endl;
	
	return 0;
}
