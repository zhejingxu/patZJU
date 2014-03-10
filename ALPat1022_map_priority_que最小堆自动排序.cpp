#include<iostream>
#include<string>
#include<map>
#include<queue>
using namespace std;

/*
    进行记录的输入和查询
	可以用map结构，将记录先进行归类
	---------注意注入输入一行字符串包含空格可以用getline函数-----------
*/

int main(void){
   freopen("D:\digitallibrary.txt","r",stdin);
   
   
   int bookN;
   cin>>bookN;

   getchar();//将空格去掉！

   string id,title,author,keywords,publisher,year;

   /*   如果要用到小顶堆，则一般要把模板的三个参数都带进去。
        STL里面定义了一个仿函数 greater<>，对于基本类型可以用这个仿函数声明小顶堆*/
   map <string,priority_queue<string,vector<string>,greater<string>>> map;

   for(int i=0;i<bookN;i++){
       getline(cin,id);   //头文件<string>
	   getline(cin,title);
	   getline(cin,author);
	   getline(cin,keywords);
	   getline(cin,publisher);
	   getline(cin,year);
	   map["1: "+ title].push(id);
	   map["2: "+ author].push(id);
	   int s = keywords.find(" ");   //string 的find方法返回其在字符串出现的第一次位置，没有出现返回-1
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

