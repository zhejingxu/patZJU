#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int NUM = 50;
const int null = -1;

/*
   根据中序遍历和后序遍历获得先序遍历的结果后
   再按层次输出
*/

typedef struct Node{
    int id;
	int left;
	int right;
};

vector <Node> vec;
queue <Node> Q,Q_temp;
int in[NUM];
int post[NUM];
int root,left,right;

void create(int s1,int e1,int s2,int e2){  //分别是后序遍历和中序遍历的首位节点下标
	Node nodes;
	nodes.id = e1;  //存放在数组post中下标位置
	nodes.left = null;
	nodes.right = null;
	if(s1==e1 || s2==e2){       //只有一个节点，没有右孩子也没有左孩子
	   vec.push_back(nodes);
	   return;  //递归终止条件说明剩下的中序遍历只有一个节点
	}

	if(post[e1]!=in[s2] && post[e1]==in[e2]){   //有左孩子没有右孩子
	   nodes.left = e1-1;
	   create(s1,e1-1,s2,e2-1);

	}else if(post[e1]!=in[e2] && post[e1]==in[s2]){  //有右孩子没有左孩子
		nodes.right = e1-1;
		create(s1,e1-1,s1+1,e2);

	}else{          //同时有右孩子和左孩子
		nodes.right = e1-1;
		int cutpost = s1;
	    int cutin = s2;
		for(int i=s2;i<=e2;i++){
		   if(in[i]==post[nodes.id]){
		       cutin = i;
		       break;
		     }
	    }
	    nodes.left = s1;
	    for(int i=s2;i<cutin;i++){
		    for(int j=s1;j<=e1-1;j++){
			if(in[i]==post[j] && j > cutpost){
				nodes.left = j;
				cutpost = j;
			}
		   }
	     }
	   create(cutpost+1,e1-1,cutin+1,e2);
	   create(s1,cutpost,s2,cutin-1);
	}
	vec.push_back(nodes);
	return;
}

int main(void){
   freopen("D:\input4.txt","r",stdin);
   int nodeNum;
   scanf("%d",&nodeNum);
   for(int i=0;i<nodeNum;i++){
	   scanf("%d",&post[i]);
   }
   for(int i=0;i<nodeNum;i++){
	   scanf("%d",&in[i]);
   }
   create(0,nodeNum-1,0,nodeNum-1);

   queue <Node> Q,Q_temp;
   for(int i=0;i<vec.size();i++){
	   if(vec[i].id == nodeNum-1){
		   Q.push(vec[i]);
		   printf("%d",post[nodeNum-1]);
	   }
   }
   
   while(!Q.empty()){
       
	   while(!Q.empty()){
		   Node node = Q.front();
		   Q.pop();
		   if(node.left!= null ){
			   printf(" %d",post[node.left]);
			   for(int i = 0;i<vec.size();i++){
				   if(vec[i].id == node.left){
					   Q_temp.push(vec[i]);
				   }
			   }
		   }
		   if(node.right!= null){
			   printf(" %d",post[node.right]);
			   for(int i = 0;i<vec.size();i++){
				   if(vec[i].id == node.right){
					   Q_temp.push(vec[i]);
				   }
			   }
		   }
       }
	   while(!Q_temp.empty()){
		   Node temp = Q_temp.front();
		   Q_temp.pop();
		   Q.push(temp);
	   }
   }

   //printf("\n");
   //for(int i=0;i<vec.size();i++){
	  // printf("%d:",vec[i].id);
	  // printf("%d",post[vec[i].id]);
	  // if(vec[i].left!=-1){
		 //  printf(" %d",post[vec[i].left]);
	  // }else{printf(" null");}
	  // if(vec[i].right!=-1){
		 //  printf(" %d",post[vec[i].right]);
	  // }else{printf(" null");}
	  // printf("\n");
   //}

   while(true){}
   return 0;
}
