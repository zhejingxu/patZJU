#include<iostream>
#include<vector>
#include<map>
#include<string>   //strcpy函数调用在pat中要使用string.h头文件
#include<algorithm>
using namespace std;

/*
  最后一个case会出现运行超时:map本身用红黑树实现，效率并不是特别高，还需要对每组数据进行排序
*/

map <string,vector<int>> student;

int main()
{
	freopen("D:/pattest/courselist.txt","r",stdin);

	int queryN,courseN;
	scanf("%d%d",&queryN,&courseN);

	int studentN,course;
	string name;
	for(int i=0;i<courseN;i++){
	   scanf("%d%d",&course,&studentN);
	   for(int j=0;j<studentN;j++){
		  cin>>name;
		  student[name].push_back(course);
	   }
	}

	for(int k=0;k<queryN;k++){
	    cin>>name;
		cout<<name<<" ";
		sort(student[name].begin(),student[name].end());
		if(student[name].size()==0){
		   printf("0");
		}else{
			printf("%d",student[name].size());
			for(int p=0;p<student[name].size();p++){
			   printf(" %d",student[name][p]);
			}
		}
		printf("\n");
	}

	while(true){}
    return 0;
}


