#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

const int MAX = 300;

/*
   通过每个字母的ASC码建立查询表
   ASC码的范围是0-128
*/

int main(){
	
	freopen("D:/input/input1050.txt", "r", stdin);

	string a, b;
	getline(cin, a);
	getline(cin, b);
	vector<bool> vec(MAX, false);

	for (int i = 0; i < a.size(); i++){
		vec[a[i]] = true;
	}
	for (int j = 0; j < b.size(); j++){
		vec[b[j]] = false;
	}
	
	for (int k = 0; k < a.size(); k++){
		if (vec[a[k]]){
			printf("%c", a[k]);
		}
	}

	return 0;
}