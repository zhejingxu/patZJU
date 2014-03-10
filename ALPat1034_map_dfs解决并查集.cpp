#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

map <string,int> weight;
map <string,vector<string>> contract;
map <string,int> result;
map <string,bool> ifVisited;

int recordN,K;
string head;
int curSize,curWeight;

void dfs(string str){
	curSize++;
	curWeight += weight[str];
	ifVisited[str] = true;

	if(weight[head]<weight[str]){
	   head = str;
	}
	
	vector <string> vec = contract[str];
	if(vec.size()!=0){
	  for(int i=0;i<vec.size();i++){
		  if(!ifVisited[vec[i]]){
		     dfs(vec[i]);
		  }
	  }
	}
}

int main()
{
	freopen("D:/headofagangtwo.txt","r",stdin);
	cin>>recordN>>K;
	for(int i=0;i<recordN;i++){
	   string p1,p2;
	   int time;
	   cin>>p1>>p2>>time;
	   contract[p1].push_back(p2);
	   contract[p2].push_back(p1);
	   weight[p1] += time;
	   weight[p2] += time;
	   ifVisited[p1] = false;
	   ifVisited[p2] = false;
	}
	for(map<string,bool>::iterator it = ifVisited.begin();it!=ifVisited.end();++it){
		if(!(*it).second){
		   curSize = 0;curWeight = 0;
		   head = (*it).first;
		   dfs((*it).first);
		   if(curSize>2 && curWeight>2*K){
		      result[head] = curSize;
		   }

		}
	}
	cout<<result.size()<<endl;
	for(map<string,int>::iterator it = result.begin();it!=result.end();++it){
		cout<<(*it).first<<" "<<(*it).second<<endl;
	}
	while(true){}
    return 0;
}


