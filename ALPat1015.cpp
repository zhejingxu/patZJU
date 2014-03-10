#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

/*
   N is a reversible prime with radix D
   其含义是N是变成D进制后再进行倒序
*/

bool ifPrime(int n){
	if(n==1||n==0){
	   return false;
	}
	if(n==2||n==3){
	   return true;
	}
	   for(int i=2;i<=sqrt((double)n);i++){
		   if(n%i==0){
		      return false;
		   }
	   }
	return true;
}

int reverse(int n,int radix){
    int result = 0;
	while(n!=0){
	  int temp = n % radix;
      n /= radix;
	  result = result * radix + temp;
	}
	return result;
}

int main(void){
   freopen("D:\input.txt","r",stdin);
   int n,radix;
   scanf("%d",&n);
   while( n >= 0){
      scanf("%d",&radix);
	//  int trynum = reverse(n,radix);
	  if(ifPrime(n) && ifPrime(reverse(n,radix))){
	     printf("Yes\n");
	  }
	  else{
	     printf("No\n");
	  }
      scanf("%d",&n);
   }
   while(true){}
   return 0;
}