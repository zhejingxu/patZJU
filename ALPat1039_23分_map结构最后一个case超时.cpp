#include<iostream>
#include<vector>
#include<map>
#include<string>   //strcpy����������pat��Ҫʹ��string.hͷ�ļ�
#include<algorithm>
using namespace std;

/*
  ���һ��case��������г�ʱ:map�����ú����ʵ�֣�Ч�ʲ������ر�ߣ�����Ҫ��ÿ�����ݽ�������
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


