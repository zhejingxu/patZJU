#include<iostream>
#include<vector>
#include<map>
#include<string>   //strcpy����������pat��Ҫʹ��string.hͷ�ļ�
#include<algorithm>
using namespace std;

/*
   �տ�ʼ���á��������к����������ַ�������Ӵ����ķ�������ʱ��
   
   ���ڲ����ɡ�ĳ�����ĵ�����Χ������ɢ���ķ���
   ���ĳ�����ĵ������������
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


