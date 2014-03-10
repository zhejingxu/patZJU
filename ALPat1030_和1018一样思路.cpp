#include<iostream>
#include<vector>
using namespace std;
const int NUM = 505;
const int INF = 100000001;

int dist [NUM];
int edgedis[NUM][NUM];
int edgecost[NUM][NUM];
bool ifVisited [NUM];

vector <vector<int>> paths;
vector <int> preNode [NUM];

int cityN,highwayN,destination;
int s;

void init(){
	for(int i=0;i<NUM;i++){
		for(int j=0;j<NUM;j++){
		   edgedis[i][j] = INF;
		   edgedis[j][i] = INF;
		   edgecost[i][j] = INF;
		   edgecost[j][i] = INF;
		}
		ifVisited[i] = false;
		dist[i] = INF;
	}
}

void dijskra(){
	edgedis[s][s] = 0;
	for(int i=0;i<NUM;i++){
	   dist[i] = edgedis[s][i];
	}
	for(int i=0;i<cityN -1 ;i++){
	    int minDist = INF;
		int minNode = 0;
		for(int j=0;j<cityN;j++){
			if(!ifVisited[i] && dist[i]<minDist){
			    minDist = dist[i];
				minNode = i;
			}
		}
		ifVisited[minNode] = true;
	    for(int i=0;i<cityN;i++){
	       if(dist[i]>dist[minNode]+edgedis[minNode][i]){
	          dist[i] = dist[minNode]+edgedis[minNode][i];  
			  preNode[i].clear();
			  preNode[i].push_back(minNode);
		   }else if(dist[i]==dist[minNode]+edgedis[minNode][i]){
			   preNode[i].push_back(minNode);
		   }
	     }
     }
}

void find_path(int currentNode,vector <int> * path){
	path->push_back(currentNode);
	if(currentNode == s){
		paths.push_back(*path);
	}else{
		for(int i=0;i<preNode[currentNode].size();i++){
		    find_path(preNode[currentNode][i],path);
		}
	}
	path->pop_back();
}

int main()
{
	freopen("D:/travelplan.txt","r",stdin);
	cin>>cityN>>highwayN>>s>>destination;
	init();
	for(int i=0;i<highwayN;i++){
		int distance,cost,start,end;
		cin>>start>>end>>distance>>cost;
		edgedis[start][end] = distance;
		edgedis[end][start] = distance;
		edgecost[start][end] = cost;
		edgecost[end][start] = cost;
	}
	dijskra();
	vector <int> path;
	find_path(destination,&path);
	//for(int i=0;i<paths.size();i++){
	//   vector <int> vec = paths[i];
	//   for(int j=0;j<vec.size();j++){
	//      cout<<vec[j]<<" ";
	//   }
	//   cout<<endl;
	//}
	
	int finalpath = 0;
	int mincost = INF;
	for(int i=0;i<paths.size();i++){
	   int cost = 0;
	   vector <int> vec = paths[i];
	   for(int j=0;j<vec.size()-1;j++){
	       cost += edgecost[vec[j]][vec[j+1]];
	   }
	   if(cost<mincost){
	      mincost = cost;
		  finalpath = i;
	   }
	}
	vector <int> vec = paths[finalpath];
	
	for(int i=vec.size()-1;i>=0;i--){
	   cout<<vec[i]<<" ";
	}cout<<dist[destination]<<" "<<mincost;

	while(true){}
    return 0;
}


