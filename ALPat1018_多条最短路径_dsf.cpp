#include<iostream>
#include<vector>
using namespace std;

/*
    1.ͨ��Dijskra����������·������¼ÿ�����·���ϵĽڵ�ġ����С�ǰ�ڵ�
	2.ʹ��DFS����������·��������ÿ��·�������ٴ����������ٴ�����
*/
const int INF = 100000000;
const int NUM = 501;
//const int NUM = 4;
int Nbike [NUM];
int map [NUM][NUM];
int dist[NUM];
bool ifVisited [NUM];

vector<vector <int>> minPaths;  //������е�dest�����·��
vector <int> preNode[NUM]; //������нڵ�����·��ǰ�ڵ�

int Cmax,Nstation,Sp,Nroad;

void init(){
	for(int i=0;i<NUM;i++){
	    Nbike[i] = 0;
		dist[i] = 0;
		ifVisited[i] = false;
		for(int j=0;j<NUM;j++){
		      map[i][j] = INF;
			  map[j][i] = INF;
		}
	}
	map[0][0] = 0;
}

void Dijskra(){   //ע���һ����0ҲҪ���뵽�����У���Ϊ��ҲҪ������preNode
	//ifVisited[0] = true;
	for(int i=0;i<NUM;i++){
	   dist[i] = map[0][i];
	}
	for(int i=0;i<=Nstation;i++){
		int minDist = INF;
		int minNode = 0;
		for(int j=1;j<=Nstation;j++){
			if(!ifVisited[j]&&dist[j]<minDist){
			    minDist = dist[j];
				minNode = j;
			}
		}
		ifVisited[minNode] = true;
		for(int j=1;j<=Nstation;j++){   //�����ѷ��ʵĽڵ�minNode����ʣ�µĽڵ�j���������ǵ�dist
			if(dist[j]>dist[minNode]+map[j][minNode]){
			    dist[j] = dist[minNode]+map[j][minNode];
				preNode[j].clear();
				preNode[j].push_back(minNode);
			}
			else if(dist[j]==dist[minNode]+map[j][minNode]){
				preNode[j].push_back(minNode);
			}
		}
	}
}

void dfs(int currentNode,vector<int> *path){ //�����ݹ�Ľ��path·���Ǵ����ڵ㵽���ڵ�0
	path->push_back(currentNode);
	if(currentNode==0){
		minPaths.push_back(*path);
	}else{
		for(int i=0;i != preNode[currentNode].size();i++){
			dfs(preNode[currentNode][i],path);
		}
	}
	path->pop_back(); //���ҵ�����0�Žڵ㣬�ݹ���path�Ѿ�ȫ����ɣ�����minPath����pathҪ������ս�����һ�εݹ�
}

int main(void){
   init();
   freopen("D:\input.txt","r",stdin);
   
   cin>>Cmax>>Nstation>>Sp>>Nroad;

   for(int i=1;i<=Nstation;i++){
      cin>>Nbike[i];
   }
   int s1,s2;
   for(int i=0;i<Nroad;i++){
       cin>>s1>>s2;
	   cin>>map[s1][s2];
	   map [s2][s1] = map[s1][s2];
   }
   Dijskra();
   //for(int i=0;i<NUM;i++){
	  // if(preNode[i].size()>0){
		 //  cout<<i<<": ";
	  // for(int j=0;j<preNode[i].size();j++){
	  //    cout<<preNode[i][j]<<" ";
	  // }
	  // cout<<"\n";
	  // }
   //}
   vector <int> path;  //����dfs�ݹ��vector����
   dfs(Sp,&path);  //ͨ��dfs���minPaths�洢������С·��

   //�������ֱ����ÿ��·������С�ͳ�������С������
   int minSend = INF,minBack = INF,minPath = INF;
   for(int i =0;i<minPaths.size();i++){
       int send = 0,back = 0;
	   for(int j=minPaths[i].size() - 2;j>=0;j--){  //-2��ԭ�������һ���ڵ�0�����ÿ���������Cmax/2
	       int temp = Cmax/2 - Nbike[minPaths[i][j]];
		   if(temp < 0){
		       back += -temp;
		   }else if(temp>back){
		       send += (temp-back);
			   back = 0;
		   }else{
		       back -=temp;
		   }
	   }
	   if(send<minSend||(send==minSend&&back<minBack)){
	       minSend = send;
		   minBack = back;
		   minPath = i;
	   }
   }

   //for(int i=0;i<minPaths[minPath].size();i++){
   //   cout<<minPaths[minPath][i]<<" ";
   //}cout<<"\n";

   cout<<minSend<<" 0";
   for(int i=minPaths[minPath].size()-2;i>=0;i--){
      cout<<"->"<<minPaths[minPath][i];
   }
   cout<<" "<<minBack;
   while(true){}
   return 0;
}

