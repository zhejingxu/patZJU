#include<iostream>
#include<vector>
using namespace std;

/*
    1.通过Dijskra获得最有最短路径，记录每个最短路径上的节点的“所有”前节点
	2.使用DFS获得所有最短路径，计算每条路径的最少带出数和最少带回数
*/
const int INF = 100000000;
const int NUM = 501;
//const int NUM = 4;
int Nbike [NUM];
int map [NUM][NUM];
int dist[NUM];
bool ifVisited [NUM];

vector<vector <int>> minPaths;  //存放所有到dest的最短路径
vector <int> preNode[NUM]; //存放所有节点的最短路径前节点

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

void Dijskra(){   //注意第一个点0也要参与到遍历中，因为它也要被放入preNode
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
		for(int j=1;j<=Nstation;j++){   //根据已访问的节点minNode访问剩下的节点j，更新它们的dist
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

void dfs(int currentNode,vector<int> *path){ //这样递归的结果path路径是从最后节点到初节点0
	path->push_back(currentNode);
	if(currentNode==0){
		minPaths.push_back(*path);
	}else{
		for(int i=0;i != preNode[currentNode].size();i++){
			dfs(preNode[currentNode][i],path);
		}
	}
	path->pop_back(); //当找到初的0号节点，递归获得path已经全部完成，加入minPath，而path要进行清空进行下一次递归
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
   vector <int> path;  //进行dfs递归的vector容器
   dfs(Sp,&path);  //通过dfs获得minPaths存储所有最小路径

   //接下来分别计算每条路径的最小送出数和最小回收数
   int minSend = INF,minBack = INF,minPath = INF;
   for(int i =0;i<minPaths.size();i++){
       int send = 0,back = 0;
	   for(int j=minPaths[i].size() - 2;j>=0;j--){  //-2的原因，是最后一个节点0，不用考虑它满足Cmax/2
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

