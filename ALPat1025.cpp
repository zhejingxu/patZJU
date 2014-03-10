#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

/*
   排序问题:
   注意case 3为只有一个用例比如
   1
   1
   1234567890009 85
*/

typedef struct Person{
	char id[13];
    int mark;
	int location;
	int totalrank;
	int localrank;
};

vector <Person> vec;
vector <Person> vectemp;

bool compare(Person p1,Person p2){
	if(p1.mark != p2.mark){
		return p1.mark > p2.mark;
	}
	int result = strcmp(p1.id,p2.id);
    return result < 0;
}

int main(void){
   freopen("D:\patrankingtwo.txt","r",stdin);
   int locationN,record;
   cin>>locationN;
   for(int i=0;i<locationN;i++){
      cin>>record;
	  for(int j=0;j<record;j++){
		  Person p;
		  scanf("%s %d",p.id,&p.mark);
		  p.location = i + 1;
		  vectemp.push_back(p);
	  }
	  //计算当地location的排名
	  sort(vectemp.begin(),vectemp.end(),compare);
	  int currentmark = vectemp[0].mark;
	  int currentrank = 1;
	  if(vectemp.size()>1){
	  for(int j=0;j<vectemp.size();j++){
		  if(vectemp[j].mark==currentmark){
			  vectemp[j].localrank = currentrank; 
		  }else{
			  vectemp[j].localrank = j + 1;
			  currentrank = j + 1;
			  currentmark = vectemp[j].mark;
		  }
		  vec.push_back(vectemp[j]);
	   }
	  }else{
		  Person p = vectemp.front();
		  p.localrank = 1;
		  vec.push_back(p);
	  }
	  vectemp.clear();
   }
   //计算总排名
   sort(vec.begin(),vec.end(),compare);
   cout<<vec.size()<<endl;
   int currentmark = vec[0].mark;
   int currentrank = 1;
   if(vec.size()>1){
	   for(int i=0;i<vec.size();i++){
		   if(vec[i].mark == currentmark){
			   vec[i].totalrank = currentrank;
		   }else{
			   vec[i].totalrank = i + 1;
			   currentrank = i + 1;
			   currentmark = vec[i].mark;
		   }
	   cout<<vec[i].id<<" "<<vec[i].totalrank<<" "<<vec[i].location<<" "<<vec[i].localrank<<endl;
	   }
   }else{
       cout<<vec[0].id<<" "<<"1"<<" "<<vec[0].location<<" "<<vec[0].localrank<<endl;
   }
   
   while(true){ }
}