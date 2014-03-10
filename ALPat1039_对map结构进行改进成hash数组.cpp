#include<iostream>
#include<vector>
#include<map>
#include<string>   //strcpy函数调用在pat中要使用string.h头文件
#include<algorithm>
using namespace std;

/*
  原来的map结构最后一个case会出现运行超时:map本身用红黑树实现，效率并不是特别高，还需要对每组数据进行排序

  改进:将map结构的字符串匹配，转化成求字符串的hash值，只要vector<int>结构的数组即可

  因为学生名字统一结构为A student name consists of 3 capital English letters plus a one-digit number，所以可以有唯一对应的一个hash值

  用字符数组而不用字符串可以减少输入时的一些细节错误
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


