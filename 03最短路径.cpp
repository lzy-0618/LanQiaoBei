#include<iostream>
using namespace std;

const int N = 20;
const int INF = 1e9;


int map[N][N];			// 邻接矩阵 
int dist[N],p[N];		// 距离数组 前驱数组 
int flag[N];			// flag数组 
int n = 19;				

void add(char u,char v,int w){	// 添加边 
	int i = u - 'A' + 1;
	int j = v - 'A' + 1;
	map[i][j] = w;
	map[j][i] = w;
}

void dijkstra(int u){	
	
	for(int i=1;i<=n;++i){
		dist[i] = map[u][i];
		flag[i] = false;
		if(dist[i] == INF) p[i] = -1;
		else p[i] = u;
	}
	
	dist[u] = 0;
	flag[u] = true;
	
	for(int i=1;i<=n;++i){
		int min_dis = INF,t = u;
		for(int j=1;j<=n;++j){
			if(!flag[j] && dist[j] < min_dis){
				min_dis = dist[j];
				t = j;
			}
		}
		
		if(t == u) return;
		flag[t] = true;
		
		for(int j=1;j<=n;++j){
			if(!flag[j] && map[t][j] < INF){
				if(dist[j] > (dist[t] + map[t][j])){
					dist[j] = dist[t] + map[t][j];
					p[j] = -1;
				}
			}
		}
	}
}

int main(){
	
	// 初始化地图
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			map[i][j] = INF;
		}
	} 
	
	add('A','B',2);
    add('A','C',1);
    add('A','D',1);
    add('A','D',1);
    add('B','J',2);
    add('B','G',1);
    add('C','D',3);
    add('C','F',3);
    add('C','G',3);
    add('D','E',1);
    add('D','G',2);
    add('D','H',1);
    add('D','I',2);
    add('E','H',1);
    add('E','I',3);
    add('F','G',1);
    add('F','J',1);
    add('G','F',1);
    add('G','I',3);
    add('G','K',2);
    add('H','I',1);
    add('H','L',2);
    add('I','M',3);
    add('J','S',2);
    add('K','N',1);
    add('K','L',3);
    add('K','P',2);
    add('L','M',1);
    add('L','R',1);
    add('M','N',2);
    add('M','Q',1);
    add('M','S',1);
    add('N','P',1);
    add('O','P',1);
    add('O','Q',1);
    add('O','R',3);
    add('R','S',1);
	
	int st = 1;		// 开始点就是A 
	dijkstra(st);
	
//	cout << "A - S min_distance = " << dist[19] << endl;
	cout << dist[19] << endl; 
	return 0;
}
