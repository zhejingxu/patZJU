#include<iostream>
#include<iomanip>
using namespace std;

int main(void){	
	freopen("D:/input.txt","r",stdin);

	double a[3],b[3],c[3];
    int max1=0,max2=0,max3=0;
	char letter[ ] = {'W','T','L'};
	
	for(int i = 0;i<3;i++){
	   cin>>a[i];
	   if(a[i]>a[max1]){
	      max1 = i;
	   }
	}

	for(int i = 0;i<3;i++){
	   cin>>b[i];
	   if(b[i]>b[max2]){
	      max2 = i;
	   }
	}

	for(int i = 0;i<3;i++){
	   cin>>c[i];
	   if(c[i]>c[max3]){
	      max3 = i;
	   }
	}

	double result = (a[max1]*b[max2]*c[max3]*0.65-1)*2;

	result+=0.0001;  //因为结果37.975结果会等于37.97，所以把37.975->37.9751结果会为37.98

	cout<<letter[max1]<<" "<<letter[max2]<<" "<<letter[max3]<<" "<<setiosflags(ios::fixed)<<setprecision(2)<<result;

	while(true){}
    return 0;
}
