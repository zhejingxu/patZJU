#include<iostream>
#include<vector>
#include<map>
#include<string>   //strcpy����������pat��Ҫʹ��string.hͷ�ļ�
#include<algorithm>
using namespace std;

/*
  ԭ����map�ṹ���һ��case��������г�ʱ:map�����ú����ʵ�֣�Ч�ʲ������ر�ߣ�����Ҫ��ÿ�����ݽ�������

  �Ľ�:��map�ṹ���ַ���ƥ�䣬ת�������ַ�����hashֵ��ֻҪvector<int>�ṹ�����鼴��

  ��Ϊѧ������ͳһ�ṹΪA student name consists of 3 capital English letters plus a one-digit number�����Կ�����Ψһ��Ӧ��һ��hashֵ

  ���ַ�����������ַ������Լ�������ʱ��һЩϸ�ڴ���
*/

const int NUM = 26 * 26 * 26 * 10;
vector <int> student [NUM];

int gethash(char str[]){
	return ( str[0]-'A')* 26 * 26 * 10 + (str[1] - 'A') * 26 * 10 + ( str[2] - 'A') * 10 + str[3] - '0';
}

int main()
{
	freopen("D:/pattest/courselist.txt","r",stdin);

	int queryN,courseN;
	scanf("%d%d",&queryN,&courseN);

	int studentN,course;
	char name [5];  
	for(int i=0;i<courseN;i++){
	   scanf("%d%d",&course,&studentN);
	   for(int j=0;j<studentN;j++){
		  scanf("%s",name);
		  student[gethash(name)].push_back(course);
	   }
	}

	for(int k=0;k<queryN;k++){
	    scanf("%s",name);
		printf("%s %d",name,student[gethash(name)].size());
		sort(student[gethash(name)].begin(),student[gethash(name)].end());
		if(student[gethash(name)].size()!=0){
			for(int p=0;p<student[gethash(name)].size();p++){
			   printf(" %d",student[gethash(name)][p]);
			}
		}
		printf("\n");
	}

	while(true){}
    return 0;
}


