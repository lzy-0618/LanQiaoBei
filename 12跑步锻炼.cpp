#include<iostream>
#include<set>

using namespace std;

int week = 6;	// 满7归1
int sum_km = 0;

set<int>day31 = {1,3,5,7,8,10,12};
set<int>day30 = {4,6,9,11};

// 判断是否是闰年
bool isLeap(int year) {
	if((year % 400 == 0)||(year % 4 ==0 && year % 100 !=0)) {
		return true;
	} else {
		return false;
	}
}

int main(){

	int day = 0;
	for(int i = 2000;i <= 2020;++i){
		for(int j =1;j <= 12;++j){

			// 获取月份天数
			if(day31.count(j) > 0){
				day = 31;
			}else if(day30.count(j) > 0){
				day = 30;
			}else if(!isLeap(i)) day = 28;
			else day = 29;

			for(int k = 1;k <= day;	++k){
				if(k == 1 || week == 1) sum_km += 2;
				else sum_km += 1;

				++week;
				if(week > 7) week = 1;

				if(i == 2020 && j == 10 && k == 1){
						cout << sum_km << endl;
						return 0;	// 程序退出即可
				}
			} 
		}
	}


	return 0;
}