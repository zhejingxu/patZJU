/*
VS ע�Ϳ�ݼ�
CTRL + K Ȼ��  CTRL + C (ע��)
CTRL + K Ȼ��  CTRL + U (ȡ��ע��)
*/

#include <iostream>
#include <string>
using namespace std; 

int main( )
{
   string chinese [] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
   string nums;
   cin>>nums;
   int sum = 0;
   for(int i=0;i<nums.length();i++){
	   sum += (nums[i] - 48);
   }
   int digit = 0;
   int result[4]={-1,-1,-1,-1};
   int i = 0;

   while(sum!=0){
       result[i] = sum%10;
	   sum = sum/10;
       i++;
   }
   for(int i=3;i>=0;i--){
       if(-1!=result[i]){
	     cout<<chinese[result[i]];
	     	   if(0!=i){
		   cout<<" ";
	   }
	   }
   }
   system("pause");
   return 0;
}