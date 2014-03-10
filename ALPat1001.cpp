#include<iostream>
#include<math.h>
using namespace std;

int main(void){
	int a,b;
	scanf("%d%d",&a,&b);
	int c = a+b;
	if(c<0){
	   printf("-");
	   c = -c;
	}
	if(0==c){
	   printf("0");
	}
	int result[7]={0,0,0,0,0,0,0};
	bool ifPrint = false;
	for(int i=0;i<7;i++){
	    result[i]=(c/(int)(pow((double)10,(double)(6-i))))%10;
		
		if(0!=result[i]){
		   ifPrint = true;
		}
		if(ifPrint){
		    printf("%d",result[i]);
			if(0==i||3==i){
			printf(",");
			}
		}

	}

	system("pause");
    return 0;
}