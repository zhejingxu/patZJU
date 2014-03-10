#include<iostream>
#include<queue>
using namespace std;


/*���Ľṹ��һά�����ʾ����Ϊ֪�������ڵ����Ŀ������100������һά������±��ʾ�ӽڵ㣬һλ�����ŵ�ֵ��ʾ���ڵ�
  ����ÿһ����б���������queue�Ľṹ����һ��Q���ڴ�ŵ�ǰ��ε����и��ڵ㣬�����ӽڵ����Q_temp�У�Ȼ��QΪ�պ󣬽�Q_temp��Ԫ�ض�����Q
*/
int main(void){	
	//freopen("D:/input.txt","r",stdin);
	int N,M;
	cin>>N>>M;   //N-the number of nodes in a tree, M-the number of non-leaf nodes
	
	int parentID[101];  //�������飬�±��ʾ�ӽڵ��ID������ֵ��ʾ���ڵ��ID

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

	while(!Q.empty()){  //��һ��while�����жϳ����Ƿ����
	    
		int iCount = 0;  //ͳ��ÿһ���Ҷ����Ŀ����ʼ��Ϊ0

		while(!Q.empty()){   //�ڶ���while�����жϵ�ǰ��ĸ��ڵ��Ƿ񶼼���
		  
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
		} //������ɵĻ���ʾ��ǰ��ĸ��ڵ㶼�Ѿ�����

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
