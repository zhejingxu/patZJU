#include<iostream> 
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
const int NUM = 100;

/*
   1.���ַ���ת��Ϊһ��20λ��ά���飬һά��Ϊ�����±�һά�ж��Ƿ��ظ���double�����һ���µ�����
   2.�Ա����������Ƿ��ظ�  ---- > ԭ�������λ��飬������������hash[10]������������¼ÿλ���ֵĴ������ܰ���
   */

int main(void){
   freopen("D:\palindromicnumber.txt","r",stdin);
   string str;
   int maxstep,step = 0;
   cin>>str>>maxstep;
   int input[NUM];  //�������Ľ��
   int result[NUM];  //���������

   for(int i=0;i<NUM;i++){
	  input[i] = 0;
      result[i] = 0;
   }

   for(int i=0;i<str.size();i++){
	   input[NUM - str.size() + i] = str.at(i) - 48;
	   result[NUM - str.size() + i] = input[NUM - str.size() + i];
   }

   int len = str.size();  //��ǰ���ݵĳ���
   bool ifExit = true;
   while(step<maxstep){
	   ifExit = true;
	   //���жϵ�ǰ�ǲ���ѭ����
	   for(int i=NUM-1;i>=NUM-len;i--){
		   if(result[i]!=result[2*NUM-1-i-len]){
		       ifExit = false;
			   break;
		   }    	       
	   }

	   if(ifExit){
	      break;
	   }

	   //������ǻ������ͽ��������input
	   for(int i=0;i<NUM;i++){
	      input[i] = result[i];
	   }

	   int bit = 0,temp;
	   for(int i=NUM-1;i>=NUM-len;i--){
		   temp = input[i] + input[2*NUM-1-i-len] + bit;
		   if(temp>=10){
		      bit = 1;
			  result[i] = temp % 10;
			  if(i==NUM-len){  //����Ѿ��ӷ������һλ
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
