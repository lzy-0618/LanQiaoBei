#include<iostream>

using namespace std;

// �ж��Ƿ�������
bool isLeap(int year) {
	if((year % 400 == 0)||(year % 4 ==0 && year % 100 !=0)) {
		return true;
	} else {
		return false;
	}
}

// �ж��Ƿ�Ϊ�Ϸ�����
bool check(int year,int month,int day) {
	if(month > 12 || month == 0) return false;
	if(day > 31) return false;
	if(month == 2) {
		if(isLeap(year)&&day>29) return false;
		if(!isLeap(year)&&day>28) return false;
	}
	if(month ==4||month == 6 ||month == 9 || month == 11) {
		if(day > 30) return false;
	}
	return true;
}


int main() {

	int n;			// �������� num
	cin >> n;
	int a,b,c,d,e,f,g,h;	// 8λ����
	int year,month,day;
	bool flag = false;		// �ж��Ƿ����ɻ�������

	for(int i=n+1; i<99999999; ++i) {
		
		// ��,��,��
		year = i / 10000;
		month = (i%10000) / 100;
		day = i%100;

		a=i%10;
		b=(i/10)%10;
		c=(i/100)%10;
		d=(i/1000)%10;
		e=(i/10000)%10;
		f=(i/100000)%10;
		g=(i/1000000)%10;
		h=(i/10000000)%10;
		
		// ������Ĵ� 
		if(a==h&&b==g&&c==f&&d==e&&!flag) {
			if(check(year,month,day)) {
				cout<< i << endl;
				flag = true;
			}
		}
		
		// ���ABABBABA �����Ӵ� 
		if(a==h&&b==g&&c==f&&d==e&&a==c&&b==d) {
			if(check(year,month,day)) {
				cout<< i << endl;
				break;
			}
		}

	}

	return 0;
}
