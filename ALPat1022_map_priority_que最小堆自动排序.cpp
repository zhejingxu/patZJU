#include<iostream>
#include<string>
#include<map>
#include<queue>
using namespace std;

/*
    ���м�¼������Ͳ�ѯ
	������map�ṹ������¼�Ƚ��й���
	---------ע��ע������һ���ַ��������ո������getline����-----------
*/

int main(void){
   freopen("D:\digitallibrary.txt","r",stdin);
   
   
   int bookN;
   cin>>bookN;

   getchar();//���ո�ȥ����

   string id,title,author,keywords,publisher,year;

   /*   ���Ҫ�õ�С���ѣ���һ��Ҫ��ģ�����������������ȥ��
        STL���涨����һ���º��� greater<>�����ڻ������Ϳ���������º�������С����*/
   map <string,priority_queue<string,vector<string>,greater<string>>> map;

   for(int i=0;i<bookN;i++){
       getline(cin,id);   //ͷ�ļ�<string>
	   getline(cin,title);
	   getline(cin,author);
	   getline(cin,keywords);
	   getline(cin,publisher);
	   getline(cin,year);
	   map["1: "+ title].push(id);
	   map["2: "+ author].push(id);
	   int s = keywords.find(" ");   //string ��find�������������ַ������ֵĵ�һ��λ�ã�û�г��ַ���-1
	   while(s!=-1){
		   map["3: "+ keywords.substr(0,s)].push(id);
		   keywords = keywords.substr(s+1);
		   s = keywords.find(" ");
	   }  map["3: "+ keywords].push(id);
	   map["4: "+ publisher].push(id);
	   map["5: "+ year].push(id);
   }

   int queryN;
   cin>>queryN;
   getchar();
   string query;
   for(int i=0;i<queryN;i++){
       getline(cin,query);
	   cout<<query<<endl;
	   if(map.count(query)!=0){
		   while(!map[query].empty()){
		   cout<<map[query].top()<<endl;
		   map[query].pop();
		   }
	   }else{
	       cout<<"Not Found"<<endl;
	   }
   }
   while(true){}
   return 0;
}

