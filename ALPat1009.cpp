#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

const int NUM  = 2005;

int main(void){	
	freopen("D:/input.txt","r",stdin);
	double a1[NUM],a2[NUM];
	int num1 = 0,num2 =  0;
	int exp = 0;
	double coexp = 0;

	for(int i=0;i<NUM;i++){
	    a1[i] = 0;
		a2[i] = 0;
	}

	cin>>num1;
	for(int i = 0;i<num1;i++){
	     cin>>exp;
		 cin>>a1[exp];
	}

	cin>>num2;
	double temp = 0;
	for(int i = 0;i<num2;i++){
	     cin>>exp;
		 cin>>coexp;
		 for(int j=0;j<(NUM/2);j++){
			 temp = a2[exp+j];
		     a2[exp+j] = temp + coexp * a1[j];
		 }
	}

	int count = 0;
	for(int i=0;i<NUM;i++){
	    if(fabs(a2[i])>=0.1){
			count++;
		}
	}
	cout<<count;

	for(int i=NUM-1;i>=0;i--){
		if(fabs(a2[i])>=0.1){
			cout<<" "<<i<<" "<<setiosflags(ios::fixed)<<setprecision(1)<<a2[i];
		}
	}

	while(true){}
    return 0;
}
