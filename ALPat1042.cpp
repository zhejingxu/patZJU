#include<iostream>
#include<vector>
#include<map>
#include<string>   //strcpy����������pat��Ҫʹ��string.hͷ�ļ�
#include<algorithm>
using namespace std;

/*
   �տ�ʼ��vector�洢��������֣���ʱ����Ϊ��vector����
   ����������Ҫ��c++������cin���cout�ĳ�c������scanf���printf
*/

vector <int> vec;
const int NUM = 10001;

int main()
{
	freopen("D:/pattest/unique.txt","r",stdin);

	int count[NUM];
	int numN,num;
	scanf("%d",&numN);
	for(int k=0;k<NUM;k++){
	   count[k] = 0;
	}
	for(int i=0;i<numN;i++){
	   scanf("%d",&num);
	   if(count[num]==0){
		   vec.push_back(num);
	   }
	   count[num]++;
	}
	bool ifExit = false;
	for(int j=0;j<vec.size();j++){
		if(count[vec[j]]==1){
		   printf("%d",vec[j]);
		   ifExit = true;
		   break;
		}
	}
	if(!ifExit){
	   printf("None");
	}
	while(true){}
    return 0;
}


