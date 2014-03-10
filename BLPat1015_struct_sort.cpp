#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct Student{
	string ID;
	int De;
	int Cai;
}Student;

inline bool compare(Student a,Student b){
	if((a.De+a.Cai)!=(b.De+b.Cai)){
		return a.De+a.Cai>b.De+b.Cai;
	}else if(a.De != b.De){
		return a.De > b.De;
	}else return a.ID < b.ID;
}

inline void print(Student s){
	printf("%s %d %d\n",s.ID.c_str(),s.De,s.Cai);
}

int main(void){
	int n,L,H;
	char id[10];
	Student s;
	string ID;
	vector <Student> vec1;
	vector <Student> vec2;
	vector <Student> vec3;
	vector <Student> vec4;

	scanf("%d%d%d",&n,&L,&H);
	while(n--){
		scanf("%s%d%d",id,&s.De,&s.Cai);
		s.ID.assign(id);
		if(s.De>=L&&s.Cai>=L){
			if(s.De>=H&&s.Cai>=H){
				vec1.push_back(s);
			}else if(s.De>=H&&s.Cai<H){
				vec2.push_back(s);
			}else if(s.De<H&&s.Cai<H&&s.De>=s.Cai){
				vec3.push_back(s);
			}else {
				vec4.push_back(s);
			}
		}

	}

	sort(vec1.begin(),vec1.end(),compare);
	sort(vec2.begin(),vec2.end(),compare);
	sort(vec3.begin(),vec3.end(),compare);
	sort(vec4.begin(),vec4.end(),compare);

	printf("%d\n",vec1.size()+vec2.size()+vec3.size()+vec4.size());
	
	for_each(vec1.begin(),vec1.end(),print);
	for_each(vec2.begin(),vec2.end(),print);
	for_each(vec3.begin(),vec3.end(),print);
	for_each(vec4.begin(),vec4.end(),print);

	system("pause");
    return 0;
}