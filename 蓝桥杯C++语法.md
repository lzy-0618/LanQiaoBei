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