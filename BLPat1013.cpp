#include <iostream>
#include <math.h>
using namespace std;

bool ifPrime(int num){
	if(2==num||3==num){
	    return true;
	}
	for(int i=2;i<=sqrt((double)num);i++){
		if(0==num%i){
		    return false;
		}
	}
	return true;
}

int main(void){
	int n1,n2;
	cin>>n1>>n2;
	int count = 1;
	int n = 1,currentNum = 2;
	while(n<=n2){
		if(ifPrime(currentNum)){
		    if(n>=n1){
			   
			      cout<<currentNum;
				  if(0!=count%10 && n!=n2)  cout<<" ";
				  if(0==count%10 && n!=n2)  cout<<endl;
				  count++;
			}
			n++;
		}
		currentNum++;
		
	}

	system("pause");
    return 0;
}