#include<iostream>
#include<vector>
#include<map>
#include<string>   //strcpy函数调用在pat中要使用string.h头文件
using namespace std;

int main()
{
	freopen("D:/pattest/boysvsgirlstwo.txt","r",stdin);
	int recordN;
	char name[11];
	char sex;
	char id[11];
	int grade;
	char mname[11]="";
	char mid[11]="";
	char mgrade = 101;
	char fname[11] = "";
	char fid[11] = "";
	int fgrade = -1;
	cin>>recordN;
	for(int i=0;i<recordN;i++){
	  cin>>name>>sex>>id>>grade;
	  if(sex=='M'&& grade<mgrade){
	      strcpy(mname,name);
		  strcpy(mid,id);
		  mgrade = grade;
	  }else if(sex=='F'&& grade>fgrade){
	      strcpy(fname,name);
		  strcpy(fid,id);
		  fgrade = grade;
	  }
	}

	if(strcmp(fname,"")==0){
	   cout<<"Absent"<<endl;
	}else{
	   cout<<fname<<" "<<fid<<endl;
	}

	if(strcmp(mname,"")==0){
	   cout<<"Absent"<<endl;
	}else{
	   cout<<mname<<" "<<mid<<endl;
	}
	
	if(strcmp(mname,"")==0 || strcmp(fname,"")==0){
	   cout<<"NA"<<endl;
	}else{
	   cout<<fgrade - mgrade<<endl;
	}
	while(true){}
    return 0;
}


