#include<iostream>
using namespace std;

const int NUM = 10005;
int a[NUM];

/* 假设到当前第i位之前的最大子序列max和其相对的begin，end已经求出；当前到第i个，tempBegin记录当前sum的begin
   假设加上了正a[i]后，sum>max则获得新的最大子序列max，更新begin和end
   假设加上了负a[i]后，0<sum<max则继续计算
   假设加上了负a[i]后，sum<0，另sum=0,更新tempBegin
*/

bool ifAllNeg(int a[NUM],int k){
	for(int i=0;i<k;i++){
		if(a[i]>=0){        //注意a[i]=0的情况不算是全为负，例如“ -1 -2 -3”输出“0 -1 -3”，而 “-1 0 -3” 输出 “0 0 0 ”对于子序列头尾的输出时有区别的
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
	   int sum = 0, max = -1;        //注意max的初始值必须为负数而不能为0，例如“-1 0 -3” 输出 “0 0 0 ”，此时max = 0 
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
