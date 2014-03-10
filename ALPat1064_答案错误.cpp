#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
using namespace std;
const int NUM = 1001;

/*
    1.计算树的层数，以及输入当前完全二叉树的根节点
	2.下面我使用的这种方法真是太复杂了= =！！数学要去太高完全做不来
*/

typedef struct Node{
	int level;
	int begin;
	int end;
	int key;
};

vector <int> nodes;
Node keyNodes[NUM];
queue <Node> Q,Q_temp;

int findKey(int level, int begin, int end){
	int lastLineNode,lastLineNodeHope = pow((double)2,level-1),key;
	if(level==1){
	    //cout<<begin<<" ";
		return begin;
	}
	else{
		lastLineNode = nodes.size()-pow((double)2,level-1)+1;  //最后一行现在有的节点数
		if(lastLineNode<=lastLineNodeHope/2){  //说明最后一行没有超过一半
		   key = (end - begin - lastLineNode)/2 + lastLineNode;
		}else if(lastLineNode > lastLineNodeHope/2){  //说明最后一行超过一半
		   key = begin + lastLineNodeHope/2 + (end - begin - 1 - lastLineNodeHope/2)/2;
		}
	}
	return key;
}

int main(void){
   freopen("D:\input2.txt","r",stdin);
   int Nnode,nodeValue;
   cin>>Nnode;
   for(int i=0;i<Nnode;i++){
       cin>>nodeValue;
	   nodes.push_back(nodeValue);
   }
   sort(nodes.begin(),nodes.end());

   int levels = log((double)Nnode)/log((double)2)+1;
   int root = findKey(levels,0,Nnode-1);
   
   keyNodes[root].begin = 0;
   keyNodes[root].end = Nnode-1;
   keyNodes[root].level = levels;
   keyNodes[root].key = root;
   Q.push(keyNodes[root]);

   while(!Q.empty()){
	   while(!Q.empty()){
		   int key = Q.front().key;
		   Q.pop();
		   cout<<key<<" ";
		  // cout<<nodes[key]<<" ";
		   int leftKey = findKey(keyNodes[key].level-1,keyNodes[key].begin,key-1);
		   if(leftKey!=key){
			      cout<<leftKey<<" ";
			      keyNodes[leftKey].begin = keyNodes[key].begin;
                  keyNodes[leftKey].end = key-1;
                  keyNodes[leftKey].level = levels-1;
                  keyNodes[leftKey].key = leftKey;
                  Q_temp.push(keyNodes[leftKey]);
		   }
		   int rightLevel = log((double)keyNodes[key].end - key)/log((double)2)+1;
		   int rightKey = findKey(rightLevel,key+1,keyNodes[key].end);
		   		  if(rightKey!=key){
			      cout<<rightKey<<" ";
			      keyNodes[rightKey].begin = key+1;
                  keyNodes[rightKey].end = keyNodes[key].end;
                  keyNodes[rightKey].level = levels-1;
                  keyNodes[rightKey].key = rightKey;
                  Q_temp.push(keyNodes[rightKey]);
		   }
				  cout<<endl;
	   }
	   while(!Q_temp.empty()){
			Node temp = Q_temp.front();
			Q_temp.pop();
			Q.push(temp);
		}
   }
   while(true){}
   return 0;
}