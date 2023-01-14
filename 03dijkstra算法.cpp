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
 
