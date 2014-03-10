#include<iostream>
using namespace std;


int main(void){	
	freopen("D:/input.txt","r",stdin);

	int n;
	int floor,currentFloor = 0;
	int time = 0;

	cin>>n;
	for(int i=0;i<n;i++){
	   cin>>floor;
	   if(currentFloor>floor){
	       time+=4*(currentFloor-floor)+5;
	   }else{
		   time+=6*(floor-currentFloor)+5;
	   }
	   currentFloor = floor;
	}
	cout<<time;
	
	

	while(true){}
    return 0;
}
