#include<iostream>
#include <iomanip> 
using namespace std;

int main(void){
   int num;
   bool ifChanged [5]  ={false,false,false,false,false};
   int ifPositive = true;   
   int result [5] ={0,0,0,0,0};
   int count_3 = 0;
   int n;
   cin>>n;
   while(n--){
	   cin>>num;
	   if(num%10==0){result[0]+=num;ifChanged[0]=true;}

	   if(num%5==1){
		  
		   if(ifPositive){
		        result[1]+=num;
				ifPositive = false; 
		   }
		   else{
		        result[1]-=num;
				ifPositive = true;
		   }
		   ifChanged[1]=true;
	   }

	   if(num%5==2){
		  
	       result[2] ++;
		   ifChanged[2]=true;
	   }

	   if(num%5==3){
		  
	       result[3] +=num;
		   ifChanged[3]=true;
		   count_3++;
	   }

	   if(num%5==4){
		   
		   if(ifChanged[4]==false){
		      result[4] = num;
		   }
		   else if(result[4]<num){
		      result[4] = num;
		   }
		   ifChanged[4]=true;
	   }
   }
      
   
   
       if(ifChanged[0]){
	      cout<<result[0]<<" ";
	   }
	   else cout<<"N"<<" ";

	   if(ifChanged[1]){
	      cout<<result[1]<<" ";
	   }
	   else cout<<"N"<<" ";

	   if(ifChanged[2]){
	      cout<<result[2]<<" ";
	   }
	   else cout<<"N"<<" ";

	   if(ifChanged[3]){
		  cout<<setiosflags(ios::fixed)<<setprecision(1)<<((double)result[3]/count_3)<<" ";
	   }
	   else cout<<"N"<<" ";

	   if(ifChanged[4]){
	      cout<<result[4];
	   }
	   else cout<<"N";

	   system("pause");
   return 0;
}