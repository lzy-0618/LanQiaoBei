#include<iostream>
#include<iomanip>
using namespace std;

int main(){
	
	
	// ÇëÊäÈëÄãµÄ´úÂë
	int n,temp,sum = 0;
	cin >> n;
	int Max = -1e7,Min = 1e7;
	double Mean;
	
	for(int i=0;i<n;++i){
		cin >> temp;
		if(temp > Max) Max = temp;
		if(temp < Min) Min = temp;
		sum += temp;
	}
	
	Mean = (double) sum / n;
	cout << Max << endl;
	cout << Min << endl;
	printf("%.2lf",Mean);
	 
	return 0;
} 
