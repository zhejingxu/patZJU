#include<iostream>
#include<queue>
using namespace std;


/*树的结构用一维数组表示，因为知道了树节点的数目不大于100，所以一维数组的下标表示子节点，一位数组存放的值表示父节点
  对于每一层进行遍历可以用queue的结构，第一个Q用于存放当前层次的所有父节点，将其子节点放入Q_temp中，然后Q为空后，将Q_temp的元素都导入Q
*/
int main(void){	
	//freopen("D:/input.txt","r",stdin);
	int N,M;
	cin>>N>>M;   //N-the number of nodes in a tree, M-the number of non-leaf nodes
	
	int parentID[101];  //定义数组，下标表示子节点的ID，数组值表示父节点的ID

	for(int i=0;i<101;i++){
	   parentID[i] = -1;
	}

	int currentParent,numOfChild,currentChild;
	for(int i = 0;i < M; i++ ){
	    cin>>currentParent;
		cin>>numOfChild;
		for(int j = 0;j < numOfChild; j++ ){
		    cin>>currentChild;
			parentID[currentChild] = currentParent;
		}
	}

	queue <int> Q,Q_temp;

	Q.push(1);
	bool ifSpace = true;

	while(!Q.empty()){  //第一层while用于判断程序是否结束
	    
		int iCount = 0;  //统计每一层的叶子数目，初始化为0

		while(!Q.empty()){   //第二层while用于判断当前层的父节点是否都检查过
		  
		   	bool hasChild = false;
		    currentParent = Q.front();
		    Q.pop();
		    for(int i=0;i<101;i++){
				if(currentParent == parentID[i]){
				      hasChild = true;
					  Q_temp.push(i);
				}
		    }
			if(!hasChild){
			   iCount++;
			}
		} //这里完成的话表示当前层的父节点都已经检查过

		if(!ifSpace){
		   cout<<" "<<iCount;
		}else {
		   cout<<iCount;
		   ifSpace =false;
		}

		while(!Q_temp.empty()){
			int temp = Q_temp.front();
			Q_temp.pop();
			Q.push(temp);
		}
	}

	//while(true){}
    return 0;
}
