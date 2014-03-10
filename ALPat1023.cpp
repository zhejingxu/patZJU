#include<iostream> 
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
const int NUM = 21;

/*
   1.将字符串转换为一个20位二维数组，一维作为数组下表，一维判断是否重复，double后存在一个新的数组
   2.对比俩个数组是否都重复  ---- > 原来想的逐位检查，后来发现有种hash[10]的做法，来记录每位出现的次数，很棒！
   */

int main(void){
   freopen("D:\havefunwithnumbers.txt","r",stdin);
   string str;
   getline(cin,str);
   int num[NUM];  //存放输入的每位数据
   int numD[NUM];  //双倍后的结果
   bool ifHave[NUM];  //判断第二个数组的当前位是否已经重复过
   for(int i=0;i<NUM;i++){
       num[i] = 0;
	   ifHave[i] = false;
   }
   
   for(int i=str.size()-1;i>=0;i--){
	   num[i] = str.at(i) - 48;
   }
   int bit = 0;  //判断当前有没有进位
   for(int i=str.size()-1;i>=0;i--){
	   int temp = num[i] * 2 + bit;
	   if(temp>=10){
	       numD[i] = temp % 10;
		   bit = 1;
	   }else{
	       numD[i] = temp;
		   bit = 0;
	   }
   }
   if(bit==1){
	  numD[0] += 10;
   }
   bool result;
   for(int i=0;i<str.size();i++){
	   result = false;
	   for(int j=0;j<str.size();j++){
		   if(!ifHave[j] && num[i]==numD[j]){
		      ifHave[j] = true;
			  result = true;
			  break;
		   }
	   }
	   if(!result){
	      break;
	   }
   }
   if(!result){
	   cout<<"No"<<endl;
   }else{
	  cout<<"Yes"<<endl;
   }
   for(int i=0;i<str.size();i++){
	  cout<<numD[i];
   }
   while(true){}
   return 0;
}
