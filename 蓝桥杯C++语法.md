## 01单词分析：C++ 数组初始化

全局变量

```c_cpp
int a[6];   // 默认设置为0
```

局部变量

```c_cpp
int a[6] = {0};   // 只有设置为0 才是0
```

<br/>

## 02成绩统计： C++ 四舍五入

```c_cpp
int a = b + 0.5;    // 保留整数

// 保留一位小数
int a = (b + 0.05) * 10;
double c = a / 10 ;

// 保留两位小数
int a = (b + 0.005) * 100;
double c = a / 100;
```

以上方法仅适用正数。

C++ cmath 库 有 专门的四舍五入函数

```c_cpp
#include<cmath>

round(3.4) // 3
```

控制输入位数的话

```c_cpp
#include<iomanip>
#include<iostream>

// a 保留两位输出
cout << fixed << setprecision(2) << a << endl;
```

<br/>

## 03 最短路径 Dijkstra算法 和 Floyd 算法

Dijkstra 算法 是单源点最短路径算法

代码模板

```c_cpp
#include<iostream>

using namespace std;

const int N = 100;			// 最大城市数
const int INF = 1e7;		// 无穷大
int map[N][N];				// 地图的邻接矩阵
int dist[N],p[N];			// 最短距离数组，前驱数组
bool flag[N];				// 同flag = true or false 判断 输入S还是V-S
int n,m; 					// 顶点数，边数

void dijkstra(int u) {


	// 初始化源点到各个顶点的最短路径
	for(int i=1; i<=n; ++i) {
		dist[i] = map[u][i];
		flag[i] = false;		// 初始化每个顶点在V集合中
		if(dist[i] == INF) p[i] = -1;		// 如果不连通,前驱为-1;否则为u
		else p[i] = u;
	}

	// 初始化源点u的信息,将源点u纳入S集合中
	dist[u] = 0;
	flag[u] = true;

	for(int i=1; i<=n; ++i) {
		// 寻找距离源点u最近的顶点t
		int min_dis = INF,t = u;
		for(int j=1; j<=n; ++j) {
			if(!flag[j] && dist[j] < min_dis) {
				min_dis = dist[j];
				t = j;
			}
		}
		if(t == u) return; 	// 找不到,说明u与其他所有点都不连通，跳出循环
		flag[t] = true;		// 找到t,将t纳入集合
		for (int j=1; j<=n; ++j) {
			if(!flag[j] && map[t][j] < INF) {	// 表示顶点j在V-S集合且和顶点t连通
				if(dist[j] > (dist[t] + map[t][j])) {	// 判断距离关系更新
					dist[j] = dist[t] + map[t][j];
					p[j] = t;
				}

			}
		}
	}
}

int main() {

	int u,v,w,st; 			// 顶点1，顶点2，权重，开始点
	cout << "请输入城市的个数：";
	cin >> n;
	cout << "请输入城市之间的道路个数：";
	cin >> m;

	// 初始化图的邻接矩阵
	for(int i =1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			map[i][j] = INF;
		}
	}

	// 赋值图的边值
	for(int i =0; i<m; ++i) {
		cin >> u >> v >> w;
		map[u][v] = min(map[u][v],w);
	}

	// 输入开始点
	cout << "请输入开始点:";
	cin >> st;
	dijkstra(st);
	// 输出开始点到各个点的最短路径信息
	for(int i=1; i<=n; ++i) {
		cout << st << "--" << i <<":";
		if(dist[i] == INF) {
			cout << "sorry,无路可达" << endl;
		} else {
			cout << "min_distance = "<< dist[i] << endl;
		}
	}

	return 0;
}

/*
测试样例(有向图)
5
11
1 5 2
5 1 8
1 2 16
2 1 29
5 2 32
2 4 13
4 2 27
1 3 15
3 1 21
3 4 7
4 3 19
/
 
```

[csdn文章参考链接](https://blog.csdn.net/weixin_44267007/article/details/119770562)

Floyd 算法 多源算法，即一次性计算出所有点之间相互的最短距离。

Floyd算法的核心来自动态规划 

```c_cpp
map[i][j] = min(map[i][j],map[i][k] + map[k][j])
```

## 04 回文日期

如何判断是不是闰年

```c_cpp
// 判断是否是闰年
bool isLeap(int year) {
	if((year % 400 == 0)||(year % 4 ==0 && year % 100 !=0)) {
		return true;
	} else {
		return false;
	}
}
```

如何判断日期合法？

```c_cpp
// 判断是否为合法日期
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
```

## 05 门牌制作

求一个正整数的长度:

```c_cpp
int len = 0;
int x = 123456798;
while(x){
  x /= 10;
  ++len;
}
```

让一个正整数逆序输出 C++实现

如何获取一个整数的各个数位（四位数如下）

```c_cpp
		a = i / 1000;           // 千
		b = (i % 1000) / 100;   // 百
		c = (i % 100) / 10;     // 十
		d = i % 10;             // 个
```

## 010 成绩统计2 printf 四舍五入

```c_cpp
1. printf("%3.0f",floatnum)
// %3.0f 表明待打印的浮点数至少占据3个字符宽度，且不带小数点和小数部分
// 整数部分至少占3个位宽；

2. printf("%6.2f",floatnum)
// %6.2f 表明待打印的数（floatNum）至少占6个字符宽度（包括两位小数和一个小数点）
// 且小数点后面有2位小数，小数点占一位，所以整数部分至少占3位。
```

printf 保留小数点后有效位数四舍五入原则

```c_cpp
%c    表示输出一个单一的字符
%d    以十进制、有符号的形式输出整数
%f    以十进制、有符号的形式输出float、double型小数
%s    输出一个字符串
```
