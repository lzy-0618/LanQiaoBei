#include<iostream>
using namespace std;
const int N=100;	//���и������޸�
const int INF=1e7;	//��ʼ�������Ϊ.......
int map[N][N],dist[N],p[N],n,m;	//nΪ���и�����mΪ���м�·�ߵ�����
bool flag[N];	//���flag[i]=true,˵���ö���i�Ѿ����뵽����S������i���ڼ���V-S

void Dijkstra(int u){
	
	for(int i=1;i<=n;i++){//********>>>--1--<<<******//
		dist[i]=map[u][i];	//��ʼ��Դ��u������������������·������
		flag[i]=false;
		if(dist[i]==INF)
			p[i]=-1;	//˵��Դ��u������i�ޱ�����������p[i]=-1
		else
			p[i]=u;	//˵��Դ��u������i�б�����������p[i]=u
	}
	flag[u]=true;//��ʼ������S�У�ֻ��һ��Ԫ�أ�Դ��u
	dist[u]=0;	//��ʼ��Դ��u�����·��Ϊ0���Լ����Լ������·��
	for(int i=1;i<=n;i++){//********>>>--2--<<<******//
		int temp=INF,t=u;
		for(int j=1;j<=n;j++){//>>--3--<<�ڼ���V-S��Ѱ�Ҿ���Դ��u����Ķ���t
			if(!flag[j] && dist[j]<temp){
				t=j;	//��¼����Դ��u����Ķ���
				temp=dist[j];
			}
		}
		if(t==u) return ;	//�Ҳ���t����ѭ��
		flag[t]=true;	//���򣬽�t���뼯��S
		for(int j=1;j<=n;j++){//>>--4--<<���¼���V-S����t�ڽӵĶ��㵽u�ľ���
			if(!flag[j] && map[t][j]<INF){//��flag[j]��ʾj��v-s�����У�map[t][j]<INF��ʾt��j�ڽ�
				if(dist[j]>(dist[t]+map[t][j])){//����t����j��·������
					dist[j]=dist[t]+map[t][j];
					p[j]=t;	//��¼j��ǰ��Ϊt
				}
			}
		}	
	}	
}

int main(){
		int u, v, w, st;
	system("color 0d");
	cout << "��������еĸ�����" << endl;
	cin >> n;
	cout << "���������֮���·�߸���" << endl;
	cin >> m;
	cout << "���������֮���·���Լ�����" << endl;
	for(int i=1;i<=n;i++)//��ʼ��ͼ���ڽӾ���
		for (int j = 1; j <= n; j++)
		{
			map[i][j] = INF;//��ʼ���ڽӾ���Ϊ�����
		}
	while (m--)
	{
		cin >> u >> v >> w;
		map[u][v] = min(map[u][v], w);	//�ڽӾ���洢��������С�ľ���
	}
	cout << "������С�����ڵ�λ�ã�" << endl;
	cin >> st;
	Dijkstra(st);
	cout << "С�����ڵ�λ�ã�" << st << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << "С����" << st << " - " << "Ҫȥ��λ�ã�" << i << endl;
		if (dist[i] == INF)
			cout << "sorry,��·�ɴ�" << endl;
		else
			cout << "��̾���Ϊ��" << dist[i] << endl; 
	}
	return 0;
}

