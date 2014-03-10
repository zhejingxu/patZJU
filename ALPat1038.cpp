#include<iostream>
#include<vector>
#include<map>
#include<string>   //strcpy函数调用在pat中要使用string.h头文件
#include<algorithm>
using namespace std;

/*
  5 32 321 3214 0229 87
  输出229 321 3214 32 87
  对字符串排序的思想：将俩个字符串前后拼接，对比哪个拼接结果比较大
  注意特例 输入  4  00 00 12 011 输出 1112
           输入  2  00 00 输出0  ---> case 2
*/
const int NUM = 100005;
string vec[NUM];

bool compare(string s1,string s2){
	string temp1 = s1+s2;
	string temp2 = s2+s1;
	//cout<<temp1<<" "<<temp2<<endl;
	//去掉数字串开头的‘0’
	while(temp1[0]== '0'&&temp1!="0"){
		temp1 = temp1.substr(1,-1);
	}
	while(temp2[0]== '0'&&temp2!="0"){
		temp2 = temp2.substr(1,-1);
	}
	if(temp1.size()!=temp2.size()){
		return temp1.size() < temp2.size();
	}
	for(int i=0;i<temp1.size();i++){
		if(temp1[i]!=temp2[i]){
		 //   cout<<temp1[i]<<" "<<temp2[i]<<endl;
			//cout<<"---------"<<endl;
			return temp1[i] < temp2[i];
		   
		}	
	}
	return false;
}

int main()
{
	freopen("D:/pattest/smallestnumber.txt","r",stdin);
	int n;
	cin>>n;
	string num;
	for(int k=0;k<n;k++){
		cin>>vec[k];
	}
	sort(vec,vec + n,compare);

	//把第一个元素的0去掉，除此之外，开头几个元素可能都是0
	int i = 0;
	string str = vec[i];
	while(str[0]== '0'){
		str = str.substr(1,-1);
		if(str=="" && i + 1<n){
		   i++;
		   str = vec[i];
		}else if(str=="" && i + 1 == n){ 	//注意如果没有输出！！则输出结果为O！！！
		   str = "0";
		   break;
		}
	}
	cout<<str;
	i++;
	if(n - i> 0){
	   for( ;i<n;i++){
	   cout<<vec[i];
	   }
	}
	while(true){}
    return 0;
}


