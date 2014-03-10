#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int NUM = 102;

/*
    1.通过DSF遍历每条路径，计算权值
	2.注意最后路径用vector sort排序
*/

typedef struct Node{
    int id;
	int father;
	int weight;
	int ifLeaf;   //-1表示节点不在树中，1表示为叶节点，0表示为非叶节点
};
Node nodes[NUM];
vector <int> finalNode;
vector <vector<int>> paths;
int weights = 0,result,leaf;

void init(){
	for(int i=0;i<NUM;i++){
		nodes[i].father = -1;
		nodes[i].id = i;
		nodes[i].ifLeaf = -1;
		nodes[i].weight = 0;
	}
}

void dfsFinalNode(int node,int currentWeight){
	weights += nodes[node].weight;
	if(node==0){
		if(weights==result){
			finalNode.push_back(leaf);
		}
	}else{
		dfsFinalNode(nodes[node].father,weights);
	}
	weights -= nodes[node].weight;
}
void dfsPaths(int node, vector<int> *path){
	path->push_back(node);
	if(node==0){
		vector<int> pathReverse;
		for(int i=path->size()-1;i>=0;i--){
			pathReverse.push_back(path->at(i));
		}
		paths.push_back(pathReverse);
	}else{
		dfsPaths(nodes[node].father,path);
	}
	path->pop_back();
}

bool compare(vector<int> v1,vector<int> v2){
	for(int i=0;i!=v1.size()&&i!=v2.size();i++){
		if(nodes[v1[i]].weight != nodes[v2[i]].weight){
		  return nodes[v1[i]].weight > nodes[v2[i]].weight;
		}
	}
	return false;
}

int main(void){
   init();
   //freopen("D:\input.txt","r",stdin);
   int Nnode,NnonLeaf;
   cin>>Nnode>>NnonLeaf>>result;
   if(Nnode==1){
	   int root;
	   cin>>root;
	   if(root==result){
		   cout<<root;
	   }
	   return 0;
   }
   for(int i=0;i<Nnode;i++){
	   cin>>nodes[i].weight;
   }
   for(int i=0;i<NnonLeaf;i++){
       int father,Nchild,child;
	   cin>>father>>Nchild;
	   nodes[father].ifLeaf = 0;
	   for(int j=0;j<Nchild;j++){
	      cin>>child;
		  if(nodes[child].ifLeaf != 0){
		     nodes[child].ifLeaf = 1;
		  }
		  nodes[child].father = father;
	   }
   }
   for(int i=0;i<Nnode;i++){
	   if(nodes[i].ifLeaf == 1){
		  leaf = i;
	      dfsFinalNode(i,0);
	   }
   }
   for(int i=0;i<finalNode.size();i++){
      vector <int> path;
	  dfsPaths(finalNode[i],&path);
   }

   sort(paths.begin(),paths.end(),compare);
   for(int i=0;i<paths.size();i++){
	   for(int j=0;j<paths[i].size();j++){
		   cout<<nodes[paths[i][j]].weight;
		   if(j!=paths[i].size()-1)cout<<" ";
	   }
	  cout<<endl;
   }
   
   while(true){}
   return 0;


}