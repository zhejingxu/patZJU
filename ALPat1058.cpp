#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

/*
   
*/


int main(){

	freopen("D:/input/hogwarts1058.txt", "r", stdin);
	char num1[15];
	char num2[15];
	scanf("%s %s", num1, num2);
	int Knuts1 = 0, Sickle1 = 0, Galleon1 = 0, Knuts2 = 0, Sickle2 = 0, Galleon2 = 0;
	//从字符串中提取六个数字
	int p = 0;
	while (num1[p] != '.'){
		Galleon1 *= 10;
		Galleon1 = Galleon1 + num1[p] - 48;
		p++;
	}p++;
	while (num1[p] != '.'){
		Sickle1 *= 10;
		Sickle1 = Sickle1 + num1[p] - 48;
		p++;
	}p++;
	while (num1[p] != '\0'){
		Knuts1 *= 10;
		Knuts1 = Knuts1 + num1[p] - 48;
		p++;
	}

	p = 0;
	while (num2[p] != '.'){
		Galleon2 *= 10;
		Galleon2 = Galleon2 + num2[p] - 48;
		p++;
	}p++;
	while (num2[p] != '.'){
		Sickle2 *= 10;
		Sickle2 = Sickle2 + num2[p] - 48;
		p++;
	}p++;
	while (num2[p] != '\0'){
		Knuts2 *= 10;
		Knuts2 = Knuts2 + num2[p] - 48;
		p++;
	}

	int bit = (Knuts1 + Knuts2) / 29;
	int Knuts = (Knuts1 + Knuts2) % 29;
	int Sickle = (Sickle1 + Sickle2 + bit) % 17;
	bit = (Sickle1 + Sickle2 + bit) / 17;
	int Galleon = Galleon1 + Galleon2 + bit;
	printf("%d.%d.%d", Galleon, Sickle, Knuts);

	return 0;
}