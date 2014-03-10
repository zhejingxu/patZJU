#include<iostream>
#include<vector>
#include<iomanip>
#include<math.h>
using namespace std;

int main(void){
	double a[1001]={0.0};
	int n;
	int ex;
	cin>>n;
	while(n--){
	   cin>>ex;
	   cin>>a[ex];
	}
	cin>>n;
	double temp_co;
	while(n--){
	   cin>>ex;
	   cin>>temp_co;
	   a[ex] += temp_co;
	}
	int count = 0;
	for(int i=0;i<1001;i++){
		if(fabs(a[i])>=0.1){
		   count++;
		}
	}
	cout<<count;
	if(count!=0){
	   cout<<" ";
	}
	for(int i=1000;i>=0;i--){
		if(fabs(a[i])>=0.1){
			count--;
		    cout<<i<<" ";
			cout<<setiosflags(ios::fixed)<<setprecision(1)<<a[i];
			if(0!=count){
			    cout<<" ";
			}
		}
	}
	system("pause");
    return 0;
}