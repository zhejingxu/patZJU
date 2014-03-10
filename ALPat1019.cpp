#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

/*
   最大的数为10的9次方，最小的base为2，所以最后生成的数的位数不会超过100
   大数据不能用int和long  ----> 这题没有考虑这种情况
   特例：输入0的话输出Yes和0
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
