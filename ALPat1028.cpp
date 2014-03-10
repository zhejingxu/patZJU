#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;

struct Student{
   char id[10];   //输入字符串是6位的，就要定义大于等于7位的字符串数组，否则答案会出错
   char name[10];
   int grade;
}stu;

vector <Student> vec;

bool compare1(Student stu1,Student stu2){
	int result = strcmp(stu1.id,stu2.id);
	return result < 0;
}

bool compare2(Student stu1,Student stu2){
	int result = strcmp(stu1.name,stu2.name);
	if(result!=0){
	   return result < 0;
	}
	result = strcmp(stu1.id,stu2.id);
	return result < 0;
}

bool compare3(Student stu1,Student stu2){
	if(stu1.grade!=stu2.grade){
		return stu1.grade < stu2.grade;
	}
	int result = strcmp(stu1.id,stu2.id);
	return result < 0;
}

int main()
{
	freopen("D:/listsortingthree.txt","r",stdin);
    int recordN,column;
	scanf("%d %d",&recordN,&column);
	for(int i=0;i<recordN;i++){
		scanf("%s %s %d",stu.id,stu.name,&stu.grade);
		vec.push_back(stu);
	}
	if(column==1){
		sort(vec.begin(),vec.end(),compare1);
	}
	if(column==2){
		sort(vec.begin(),vec.end(),compare2);
	}
	if(column==3){
		sort(vec.begin(),vec.end(),compare3);
	}
	for(int i=0;i<vec.size();i++){
		printf("%s %s %d\n",vec[i].id,vec[i].name,vec[i].grade);
	}
	while(true){}
    return 0;
}

