#include<iostream>
#include<string>
#include<vector>
using namespace std;

typedef struct Student{
    string id;
	int gradeS;
	int gradeC;
	int gradeM;
	int gradeE;
};

void setBestRank(int rankA,int rankC, int rankM, int rankE){
	if(rankA<=rankC&&rankA<=rankM&&rankA<=rankE){
	    cout<<rankA<<" A"<<endl;
	}
	else if(rankC<rankA&&rankC<=rankM&&rankC<=rankE){
	    cout<<rankC<<" C"<<endl;
	}
	else if(rankM<rankA&&rankM<rankC&&rankM<=rankE){
	    cout<<rankM<<" M"<<endl;
	}
	else if(rankE<rankA&&rankE<rankC&&rankE<rankM){
	    cout<<rankE<<" E"<<endl;
	}
}

int main(void){	
	freopen("D:/input.txt","r",stdin);

	Student stu;
	vector <Student> vec;
	
	int N,M;
	cin>>N>>M;
	for(int i=0;i<N;i++){
		cin>>stu.id;
		cin>>stu.gradeC;
		cin>>stu.gradeM;
		cin>>stu.gradeE;
		stu.gradeS = stu.gradeC + stu.gradeE + stu.gradeM;
		vec.push_back(stu);
	}

	string requestID [2000];
	for(int i=0;i<M;i++){
	    cin>>requestID[i];
	}

	int rankA = 1, rankM = 1, rankC = 1, rankE = 1;
	bool ifExit = false;

	for(int i=0;i<M;i++){
		for(int j=0;j<vec.size()&&(!ifExit);j++){
			if(vec[j].id==requestID[i]){
				for(int k=0;k<vec.size();k++){
					if(vec[k].gradeS>vec[j].gradeS){
					      rankA++;
					}
					if(vec[k].gradeM>vec[j].gradeM){
					      rankM++;
					}
					if(vec[k].gradeC>vec[j].gradeC){
					      rankC++;
					}
					if(vec[k].gradeE>vec[j].gradeE){
					      rankE++;
					}
				}
				ifExit = true;
			}
		}
		if(ifExit){
		setBestRank(rankA,rankC,rankM,rankE);
		}else {
	    cout<<"N/A"<<endl;
		}
		rankA = 1; rankM = 1; rankC = 1; rankE = 1; ifExit = false;
	}

	

	while(true){}
    return 0;
}
