#include<iostream>
using namespace std;

const int NUM = 10005;
int a[NUM];

/* ���赽��ǰ��iλ֮ǰ�����������max������Ե�begin��end�Ѿ��������ǰ����i����tempBegin��¼��ǰsum��begin
   �����������a[i]��sum>max�����µ����������max������begin��end
   ��������˸�a[i]��0<sum<max���������
   ��������˸�a[i]��sum<0����sum=0,����tempBegin
*/

bool ifAllNeg(int a[NUM],int k){
	for(int i=0;i<k;i++){
		if(a[i]>=0){        //ע��a[i]=0�����������ȫΪ�������硰 -1 -2 -3�������0 -1 -3������ ��-1 0 -3�� ��� ��0 0 0 ������������ͷβ�����ʱ�������
		    return false;
		}
	}
	return true;
}

int main(void){	
	freopen("D:/input.txt","r",stdin);

	int k;
	cin>>k;

	for(int i=0;i<k;i++){
	   cin>>a[i];
	}

	if(ifAllNeg(a,k)){
	   cout<<"0 "<<a[0]<<" "<<a[k-1];
	}else{
	   int sum = 0, max = -1;        //ע��max�ĳ�ʼֵ����Ϊ����������Ϊ0�����硰-1 0 -3�� ��� ��0 0 0 ������ʱmax = 0 
	   int begin = 0, end = 0, tempBegin = 0;    
	   for(int i=0;i<k;i++){
	       sum+=a[i];
		   if(sum>max){
		      max = sum;
			  begin = tempBegin;
		      end  = i;
		   }else if(sum<0){
		      tempBegin = i+1;
		      sum = 0;
		   }
	   }
	   cout<<max<<" "<<a[begin]<<" "<<a[end];
	}

	while(true){}
    return 0;
}
