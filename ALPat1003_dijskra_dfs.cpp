#include<iostream>
using namespace std;

const int NUM = 505;
const int INF = 1000000;
int team[NUM],dist[NUM];
bool ifVisited[NUM];
int map[NUM][NUM];
int ans=0,maxTeamNum=0;

void init(){
	for(int i=0;i<NUM;i++){
	    team[i] = 0;
		dist[i] = INF;
		ifVisited[i] = false;
		map[i][i] = 0;
		for(int j=0;j<NUM;j++){
			if(i!=j){
			     map[i][j] = INF;
				 map[j][i] = INF;
			}
		}
	}
}

void Dijskra(int city,int start){   //������ʼ����ȷ������ÿ�����е���̾���dist
	ifVisited[start] = true;
	for(int i=0;i<city;i++){
	   dist[i] = map[start][i];
	}
	for(int i=0;i<city-1;i++){  //���ҵ�ǰ��̾������ΪҪ�ظ�city-1��
	    int minDist = INF;
		int index = 0;
		for(int j=0;j<city;j++){  //Ѱ�ҵ�ǰ�ڵ��У���minDist�Ľڵ�j
			if(!ifVisited[j]&&dist[j]<minDist){
		    minDist = dist[j];
			index = j;
	      	}
		}

		ifVisited[index] = true;
		for(int j=0;j<city;j++){
			if(dist[j]>dist[index]+map[index][j]){
			       dist[j] = dist[index]+map[index][j];
			}
		}
	}
}

void dfs(int city,int curCity,int stop,int curDist,int curTeamNum){   //�������д�start��stop��·�߶�ȷ�����ľ������̾���ıȽ�
	ifVisited[curCity] = true;
	if(curCity==stop){
		if(curDist==dist[stop]){
		     ans++;
			 if(curTeamNum > maxTeamNum){
			     maxTeamNum = curTeamNum;
			 }
		}
		return;
	}
	if(curDist>dist[stop]){
	   return;
	}
	for(int i=0;i<city;i++){
		if(!ifVisited[i]&&map[curCity][i]<INF){
			                                                               //����������dfs�ĵݹ�˼�룬�ǳ���Ҫ����
		    dfs(city,i,stop,curDist+map[curCity][i],curTeamNum+team[i]);   
            ifVisited[i] = false;
		}
	}
}

int main(void){	
	freopen("D:/input.txt","r",stdin);
	
	int city,road,start,stop;
	cin>>city>>road>>start>>stop;
	init();

	for(int i=0;i<city;i++){
	   cin>>team[i];
	}
	int c1,c2,len;
	for(int i=0;i<road;i++){
	   cin>>c1>>c2>>len;
	   map[c1][c2] = len;
	   map[c2][c1] = len;
	}
	Dijskra(city,start);
	for(int i=0;i<city;i++){
	   ifVisited[i] = false;
	}
	dfs(city,start,stop,0,team[start]);
	cout<<ans<<" "<<maxTeamNum;

    return 0;
}