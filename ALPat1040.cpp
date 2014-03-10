#include<iostream>
#include<vector>
#include<map>
#include<string>   //strcpy函数调用在pat中要使用string.h头文件
#include<algorithm>
using namespace std;

/*
   刚开始采用“求倒序序列后，再求俩个字符串最大子串”的方法，超时！
   
   现在采用由“某个中心点向周围进行扩散”的方法
   针对某个中心点有俩种情况：
      a b b a
	  a b a
*/

int main()
{
	freopen("D:/pattest/symmetric.txt","r",stdin);
	string str;
	getline(cin,str);
	int max = 0,offset = 0;
	for(int i=0;i<str.size();i++){
	   offset = 0;
	   //a b a
	   while(i-offset>=0 && i+offset<str.size() && str[i-offset]==str[i+offset]){
	      offset++;
	   }
	   if((2*offset-1)>max){
	      max = 2*offset - 1;
	   }
	   //a b b a
	   offset = 0;
	   while(i-offset>=0 && i+offset+1<str.size() && str[i-offset]==str[i+offset+1]){
	      offset++;
	   }
	   if(2*offset>max){
	      max = 2*offset;
	   }
	}
	cout<<max;
	while(true){}
    return 0;
}


