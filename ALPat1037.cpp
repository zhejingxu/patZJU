#include<iostream>
#include<vector>
#include<map>
#include<string>   //strcpy函数调用在pat中要使用string.h头文件
#include<algorithm>
using namespace std;

/*
  对于任意四个数字
  a1 a2
  b1 b2
  假如有a2>a1,b2>b1则一定有a2*b2+a1*b1 > a1*b2+a2*b1
  可以证明a2b2+a1b1-a2b1-a1b2>0

  该题的每个pair不一定要进行配对，所以排序后，将同号相乘，异号忽略
*/

const int NUM = 100005;
int a[NUM],b[NUM];

int main()
{
	freopen("D:/pattest/magiccoupon.txt","r",stdin);
	int nc,np;

	cin>>nc;
	for(int i=0;i<nc;i++){
	    cin>>a[i];
	}
	sort(a,a+nc);

	cin>>np;
	for(int i=0;i<np;i++){
	    cin>>b[i];
	}
	sort(b,b+np);

	int sum = 0;
	int p1 = 0;
	while(a[p1]<0 && b[p1]<0){
	   sum+=a[p1]*b[p1];
	   p1++;
	   if(p1==nc||p1==np){
	      break;
	   }
	}
	int p2 = nc-1;
	int p3 = np-1;
	while(a[p2]>0&&b[p3]>0){
	    sum+=a[p2]*b[p3];
		p2--;p3--;
		if(p2<0||p3<0){
		   break;
		}
	}
	cout<<sum<<endl;
	while(true){}
    return 0;
}


