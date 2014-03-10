#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

/*
    ������Ŀ��M��ֵС�ڵ���100������ĳ��������ֵĴ�������һ�ٵ�ʱ����Թ��˵�����������������ᳬʱ��
	��ӹ���������󣬿���ͨ��case4
	��cin/cout�ĳ�scanf/printf�����ͨ��case3
*/

typedef struct Person{
	char name[10];
	int age;
	int wealth;
};

bool compare(Person p1,Person p2){
	if (p1.wealth != p2.wealth){
		return p1.wealth > p2.wealth;
	}
	else if (p1.age!=p2.age){
		return p1.age < p2.age;
	}
	else{
		//return p1.name < p2.name;
		return strcmp(p1.name, p2.name) < 0;
	}
}

int main(){
	
	freopen("D:/input/input1055.txt", "r", stdin);

	int iPerson, iQuery;
	scanf("%d %d", &iPerson, &iQuery);
	
	vector<Person> persons(iPerson);

	for (int i = 0; i < iPerson; i++){
		scanf("%s", persons[i].name);
		scanf("%d %d", &persons[i].age, &persons[i].wealth);
	}

	sort(persons.begin(), persons.end(), compare);

	//��ӹ��������飬���ǵ�ÿ�����������ֻ��ǰ100�������½�������filter
	//iFilter��ʾ��Ҫ�������������£�ԭ��������100000�����ı�����ֻҪ200*100=20000��
	int filter[100000];
	int iFilter = 0;
	int age_count[201] = { 0 };  
	for (int k = 0; k < persons.size(); k++){
		age_count[persons[k].age]++;
		if (age_count[persons[k].age] < 101){
			filter[iFilter] = k;
			iFilter++;
		}
	}

	for (int j = 0; j < iQuery; j++){
		int num = 0;
		int downAge = 0;
		int upAge = 0;
		scanf("%d %d %d", &num, &downAge, &upAge);
		printf("Case #%d:\n", j + 1);
		int iCount = 0;
		//��������filter���б���
		for (int p = 0; p < iFilter && iCount < num; p++){
			if (persons[filter[p]].age <= upAge && persons[filter[p]].age >= downAge){
				printf("%s ", persons[filter[p]].name);
				printf("%d %d\n", persons[filter[p]].age, persons[filter[p]].wealth);
				iCount++;
			}
		}
		if (iCount == 0){
			printf("None\n");
		}
	}

	return 0;
}