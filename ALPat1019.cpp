#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

/*
   ������Ϊ10��9�η�����С��baseΪ2������������ɵ�����λ�����ᳬ��100
   �����ݲ�����int��long  ----> ����û�п����������
   ����������0�Ļ����Yes��0
*/

vector <int> vec;

int main(void){
   freopen("D:\input4.txt","r",stdin);
   int n,base;
   scanf("%d %d",&n,&base);
   int temp;
   if(n==0){
      printf("Yes\n0");
	  while(true){}
	  return 0;
   }
   while(n!=0){
      temp = n%base;
	  vec.push_back(temp);
	  n /= base;
   }
   bool ifPalin = true;
   for(int i=0;i<vec.size()/2;i++){
	   if(vec[i]!=vec[vec.size()-1-i]){
	      ifPalin = false;
		  break;
	   }
   }
   if(ifPalin){
      printf("Yes\n");
   }else{
      printf("No\n");
   }
   for(int i=vec.size()-1;i>=0;i--){
	   printf("%d",vec[i]);
	   if(i!=0){
	      printf(" ");
	   }
   }
   while(true){}
   return 0;
}
