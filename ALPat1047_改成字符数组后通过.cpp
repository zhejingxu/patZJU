#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;


/*
    用字符串组进行操作比用string进行操作更快  
*/

typedef struct Student{
	char stuName[20];   //字符数组长度定义应该大于4，不能等于4
};

vector<Student> students;

bool compare(int id1, int id2){
	return strcmp(students[id1].stuName,students[id2].stuName)<0;
}

int main(){
	
	freopen("D:/input.txt", "r", stdin);

	int stuNum, courNum;
	scanf("%d", &stuNum);
	scanf("%d", &courNum);

	students.resize(stuNum);
	vector<vector<int>> courses(courNum);

	for (int i = 0; i < stuNum; i++){
		scanf("%s", students[i].stuName);
		int N;
		scanf("%d", &N);
		for (int j = 0; j < N; j++){
			int courseID;
			scanf("%d", &courseID);
			courses[courseID-1].push_back(i);
		}
	}

	for (int k = 0; k < courNum; k++){
		printf("%d %d\n", k + 1, courses[k].size());
		sort(courses[k].begin(), courses[k].end(), compare);
		for (int p = 0; p < courses[k].size();p++){
			int a = courses[k][p];
			printf("%s\n", students[courses[k][p]].stuName);
		}
	}
	//system("pause");
	return 0;
}