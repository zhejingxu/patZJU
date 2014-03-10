#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int NUM = 10005;
const int INF = 1000000;

/*
�㷨ʵ�ֵĲ������£�

1.ʹ�ò��鼯�ж�ͼ�Ƿ�Ϊ��ͨ��
2.����ѡȡһ�㣬��dfs������ѡȡ����һ����Զ����ĵ�A������һ��dfs���ҵ������о�����Զ�ĵ��Լ���A����deepest root
*/

typedef struct Edge{
    int start;
	int end;
};

Edge edge [NUM-1];

int fatherNode [NUM];
int compNum;

int depth[NUM];
bool ifVisited[NUM];

vector <int> vec; //���deepest�ĵ�

int findFather(int a){
	if(fatherNode[a] == -1){
	   return a;
	}
	else{
	   fatherNode[a] = findFather(fatherNode[a]);
	   return fatherNode[a];
	}
}

void calComponent(int n1,int n2){
	int n1_ = findFather(n1);
	int n2_ = findFather(n2);
	if(n1_ == n2_){
	    return;
	}
	compNum --;
	fatherNode[n1_] = n2_;
}

//����curNodeΪRoot�������ȼ���Ӧ�ڵ㣬�������õ���Դֻ��edge������ͷβ�ڵ㣬�Ѿ�Ҫ�ı���depth[i]
int bfs(int root){

	queue<int> Q,Q_temp;
	int maxDepth = 1;
	Q.push(root);
	depth[root] = 1;

	while(!Q.empty()){

		while(!Q.empty()){
		   
		   int curNode = Q.front();
		   Q.pop();
		   ifVisited[curNode] = true;
		   
		   for(int i=0;i<NUM-1;i++){
			   if(edge[i].start==curNode && !ifVisited[edge[i].end]){
				      Q_temp.push(edge[i].end);
				      depth[edge[i].end] = depth[curNode]+1;
				   if(depth[edge[i].end] > maxDepth){
				      maxDepth = depth[edge[i].end];
				   }
				  // cout<<"edge 1:"<<edge[i].start<<" "<<edge[i].end<<endl;
			}else if(edge[i].end==curNode  && !ifVisited[edge[i].start] ){
				      Q_temp.push(edge[i].start);
				      depth[edge[i].start] = depth[curNode]+1;
				   if(depth[edge[i].start] > maxDepth){
				      maxDepth = depth[edge[i].start];
				   }
				 //  cout<<"edge 2:"<<edge[i].start<<" "<<edge[i].end<<endl;
			}
		   }
		 }
		 
		while(!Q_temp.empty()){
			int temp = Q_temp.front();
			Q.push(temp);
			Q_temp.pop();
		}
	}
	return maxDepth;
}


int main(void){
   freopen("D:\input.txt","r",stdin);
   //freopen("D:\input2.txt","r",stdin);
   //freopen("D:\input3.txt","r",stdin);
   for(int i=0;i<NUM;i++){
       fatherNode[i] = -1;
	   depth[i] = 0;  //��ʼ�����нڵ����ȶ�Ϊ0
	   ifVisited[i] = false;
   }
   int nodeNum;
   cin>>nodeNum;
   compNum = nodeNum;
   
   if(nodeNum == 1){
       cout<<"1";   //case 2 ������1�����Ϊ1
	   return 0;
   }

   for(int i=0;i<nodeNum-1;i++){
	   cin>>edge[i].start>>edge[i].end;
	   calComponent(edge[i].start,edge[i].end);
   }
   if(compNum > 1){
       cout<<"Error: "<<compNum<<" components";
   }
   else{
      //��������bfs��ȡedge[0].start��Ϊ��һ����
	   int maxDepth = bfs(edge[0].start);

	   for(int i=0;i<nodeNum;i++){
		   if(maxDepth==depth[i+1]){
			   vec.push_back (i+1);	   
		   }
	   }
	  
	   for(int i=0;i<NUM;i++){
	      depth[i] = 0;  //��ʼ�����нڵ����ȶ�Ϊ0
	      ifVisited[i] = false;
       }

	   maxDepth = bfs(vec[0]);
	   
	   for(int i=0;i<nodeNum;i++){
	       if(maxDepth==depth[i+1]){
			   vec.push_back (i+1);
		   }
	   }

	   /*cout<<"maxDepth:"<<maxDepth<<endl;
	   cout<<"all: "<<depth[1]<<" "<<depth[2]<<" "<<depth[3]<<" "<<depth[4]<<" "<<depth[5]<<endl;*/

	   sort(vec.begin(),vec.end());
	  
	   cout<<vec[0];
	   for(int i=1;i<vec.size();i++){
		   if(vec[i]!=vec[i-1]){ 
		      cout<<endl<<vec[i];
		   }
	   }
   }
   while(true){}
   return 0;
}

