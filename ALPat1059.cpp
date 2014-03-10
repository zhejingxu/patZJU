#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

typedef struct Factor{
	int exf;
	int factor;
};

vector <Factor> vec;

bool ifPrime(int a){
	if(2==a||3==a){
	   return true;
	}
	for(int i=2;i<=(int)sqrt(a*1.0);i++){
		if(0==a%i){
		   return false;
		}
	}
	return true;
}

void cal(int num){
	Factor fac;
	for(int i=2;1!=num;i++){
		if(ifPrime(i)){
			if(num%i==0){
					fac.factor = i;
					fac.exf = 0;
				while(num%i==0){
				    num /= i;
					fac.exf++;
				}
				vec.push_back(fac);
			}	
		
		}
	
	}
}

void print(){
	for(int i = 0; i < vec.size(); i++){
		cout<< vec[i].factor;
		if(vec[i].exf != 1){
			cout<<"^"<<vec[i].exf;
		}
		if(i!=vec.size()-1){
		cout<<"*";
		}
	}
}

int main(void){
   freopen("D:\input.txt","r",stdin);
   int num;
   scanf("%d",&num);
   cout<<num<<"=";
   if(1!=num){
     cal(num);
     print();
   }
   else{
     cout<<num;
    }
   while(true){}
   return 0;
}

