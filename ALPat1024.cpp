#include<iostream> 
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
const int NUM = 100;

/*
   1.将字符串转换为一个20位二维数组，一维作为数组下表，一维判断是否重复，double后存在一个新的数组
   2.对比俩个数组是否都重复  ---- > 原来想的逐位检查，后来发现有种hash[10]的做法，来记录每位出现的次数，很棒！
   */

int main(void){
   freopen("D:\palindromicnumber.txt","r",stdin);
   string str;
   int maxstep,step = 0;
   cin>>str>>maxstep;
   int input[NUM];  //存放输入的结果
   int result[NUM];  //存放数组结果

   for(int i=0;i<NUM;i++){
	  input[i] = 0;
      result[i] = 0;
   }

   for(int i=0;i<str.size();i++){
	   input[NUM - str.size() + i] = str.at(i) - 48;
	   result[NUM - str.size() + i] = input[NUM - str.size() + i];
   }

   int len = str.size();  //当前数据的长度
   bool ifExit = true;
   while(step<maxstep){
	   ifExit = true;
	   //先判断当前是不是循环数
	   for(int i=NUM-1;i>=NUM-len;i--){
		   if(result[i]!=result[2*NUM-1-i-len]){
		       ifExit = false;
			   break;
		   }    	       
	   }

	   if(ifExit){
	      break;
	   }

	   //结果不是回文数就将结果搬入input
	   for(int i=0;i<NUM;i++){
	      input[i] = result[i];
	   }

	   int bit = 0,temp;
	   for(int i=NUM-1;i>=NUM-len;i--){
		   temp = input[i] + input[2*NUM-1-i-len] + bit;
		   if(temp>=10){
		      bit = 1;
			  result[i] = temp % 10;
			  if(i==NUM-len){  //如果已经加法到最高一位
			     result[i-1] = 1;
				 len ++; 
				 break;
			  }
		   }else{
		      bit = 0;
			  result[i] = temp;
		   }
	   }
       step ++;
   }

   for(int i=NUM-len;i<=NUM-1;i++){
	       cout<<result[i];
	   }
   cout<<endl<<step;
   
   while(true){}
   return 0;
}
