#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

const int COURSES = 2501;

vector<string> courses[COURSES];

bool compare(string str1, string str2){
	return str1 < str2;
}

int main(){
	
	freopen("D:/input.txt", "r", stdin);

	int stuNum, courNum;
	scanf("%d", &stuNum);
	scanf("%d", &courNum);

	for (int i = 0; i < stuNum; i++){
		//char stuName[4];
		//scanf("%s", stuName);
		string stuName;
		cin >> stuName;
		int N;
		scanf("%d", &N);
		for (int j = 0; j < N; j++){
			int courseID;
			scanf("%d", &courseID);
			courses[courseID].push_back(stuName);
		}
	}

	for (int k = 0; k < courNum; k++){
		printf("%d %d\n", k + 1, courses[k + 1].size());
		sort(courses[k + 1].begin(), courses[k + 1].end(), compare);
		for (int p = 0; p < courses[k + 1].size();p++){
			string s = courses[k + 1].at(p);
			cout << s<<endl;
		}
	}
	//system("pause");
	return 0;
}