#include<iostream> 
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
const int NUM = 21;

/*
   1.���ַ���ת��Ϊһ��20λ��ά���飬һά��Ϊ�����±�һά�ж��Ƿ��ظ���double�����һ���µ�����
   2.�Ա����������Ƿ��ظ�  ---- > ԭ�������λ��飬������������hash[10]������������¼ÿλ���ֵĴ������ܰ���
   */

int main(void){
   freopen("D:\havefunwithnumbers.txt","r",stdin);
   string str;
   getline(cin,str);
   int num[NUM];  //��������ÿλ����
   int numD[NUM];  //˫����Ľ��
   bool ifHave[NUM];  //�жϵڶ�������ĵ�ǰλ�Ƿ��Ѿ��ظ���
   for(int i=0;i<NUM;i++){
       num[i] = 0;
	   ifHave[i] = false;
   }
   
   for(int i=str.size()-1;i>=0;i--){
	   num[i] = str.at(i) - 48;
   }
   int bit = 0;  //�жϵ�ǰ��û�н�λ
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
