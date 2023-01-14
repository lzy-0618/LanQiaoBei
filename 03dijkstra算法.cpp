#include<iostream>

using namespace std;

const int N = 100;			// ��������
const int INF = 1e7;		// �����
int map[N][N];				// ��ͼ���ڽӾ���
int dist[N],p[N];			// ��̾������飬ǰ������
bool flag[N];				// ͬflag = true or false �ж� ����S����V-S
int n,m; 					// ������������

void dijkstra(int u) {


	// ��ʼ��Դ�㵽������������·��
	for(int i=1; i<=n; ++i) {
		dist[i] = map[u][i];
		flag[i] = false;		// ��ʼ��ÿ��������V������
		if(dist[i] == INF) p[i] = -1;		// �������ͨ,ǰ��Ϊ-1;����Ϊu
		else p[i] = u;
	}

	// ��ʼ��Դ��u����Ϣ,��Դ��u����S������
	dist[u] = 0;
	flag[u] = true;

	for(int i=1; i<=n; ++i) {
		// Ѱ�Ҿ���Դ��u����Ķ���t
		int min_dis = INF,t = u;
		for(int j=1; j<=n; ++j) {
			if(!flag[j] && dist[j] < min_dis) {
				min_dis = dist[j];
				t = j;
			}
		}
		if(t == u) return; 	// �Ҳ���,˵��u���������е㶼����ͨ������ѭ��
		flag[t] = true;		// �ҵ�t,��t���뼯��
		for (int j=1; j<=n; ++j) {
			if(!flag[j] && map[t][j] < INF) {	// ��ʾ����j��V-S�����ҺͶ���t��ͨ
				if(dist[j] > (dist[t] + map[t][j])) {	// �жϾ����ϵ����
					dist[j] = dist[t] + map[t][j];
					p[j] = t;
				}

			}
		}
	}
}

int main() {

	int u,v,w,st; 			// ����1������2��Ȩ�أ���ʼ��
	cout << "��������еĸ�����";
	cin >> n;
	cout << "���������֮��ĵ�·������";
	cin >> m;

	// ��ʼ��ͼ���ڽӾ���
	for(int i =1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			map[i][j] = INF;
		}
	}

	// ��ֵͼ�ı�ֵ
	for(int i =0; i<m; ++i) {
		cin >> u >> v >> w;
		map[u][v] = min(map[u][v],w);
	}

	// ���뿪ʼ��
	cout << "�����뿪ʼ��:";
	cin >> st;
	dijkstra(st);
	// �����ʼ�㵽����������·����Ϣ
	for(int i=1; i<=n; ++i) {
		cout << st << "--" << i <<":";
		if(dist[i] == INF) {
			cout << "sorry,��·�ɴ�" << endl;
		} else {
			cout << "min_distance = "<< dist[i] << endl;
		}
	}

	return 0;
}

/*
��������(����ͼ)
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
 
