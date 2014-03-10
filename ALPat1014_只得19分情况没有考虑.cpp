#include<iostream>
#include<vector>
using namespace std;
const int NUM = 1001;
const int WINDOWS = 21;

/*
    1.������Ŀ��2 2 7 5
                1 2 6 4 3 534 2
                3 4 5 6 7
	  ��� 1_8:01 3_8:07 5_8:10
	       2_8:02 4_8:06 6_17:00 7 sorry(can't served befored 17:00)
*/

int transactionTime [NUM];  //����ҵ������ʱ��
int query [NUM];
int servedTime[NUM];  //����ʱ�䣬ȡ��8:00��Է���
int firstTime[WINDOWS]; //ÿ�ӵ�ǰ���һ������Ҫʱ�䣬����С��ֵ��ʾ�¹˿Ͳ��뵽��һ����
int whichWindow[NUM]; //ÿ���ͻ��ŵڼ�������

void init(){
	for(int i=0;i<NUM;i++){
	    transactionTime[i] = 0;
		query[NUM] = 0;
		servedTime[NUM] = 540;
	}
}

int main(void){
   init();
   freopen("D:\input.txt","r",stdin);
   int Nwindow,Ncap,Ncustomer,Nquery;
   cin>>Nwindow>>Ncap>>Ncustomer>>Nquery;
   for(int i=1;i<=Ncustomer;i++){
	   cin>>transactionTime[i];
   }
   for(int i=0;i<Nquery;i++){
       cin>>query[i];
   }
   if(Nwindow==1&&Ncap==1){
	   servedTime[1] = transactionTime[1];
	   for(int i=1;i<=Ncustomer;i++){
	      servedTime[i] = servedTime[i-1] + transactionTime[i];
	   }
   }
   else{
   //���й˿���С�ڵ���MN
   if(Ncustomer <= Nwindow * Ncap){
	   for(int i=1;i<=Ncustomer;i++){
	        whichWindow[i] = i % Nwindow;
			if(whichWindow[i]==0){
			   whichWindow[i] = Nwindow;
			}
			if(i <= Nwindow){   //����ǵ�һ�ӵĹ˿�
			    servedTime[i] = transactionTime[i];
			}else{
			    servedTime[i] = servedTime[i-Nwindow] + transactionTime[i];
			}
	   }
   }
   //���й˿�������MN
   else{
	   for(int i=1;i<=Nwindow * Ncap;i++){
	       whichWindow[i] = i % Nwindow;
		   if(whichWindow[i]==0){
			   whichWindow[i] = Nwindow;
			}
		   if(i<=Nwindow){
		      servedTime[i] = transactionTime[i];
			  firstTime[i] = transactionTime[i];

		   }else{
			  servedTime[i] = servedTime[i-Nwindow] + transactionTime[i];
		   }
	   }
	   for(int i=Nwindow * Ncap + 1;i<=Ncustomer;i++){
		   //Ѱ�ҵ�ǰ������С��firstTime
		   int min = 1;
		   for(int j = 1;j<=Nwindow;j++){
			   if(firstTime[j] < firstTime[min]){
			      min = j;
			   }
		   }
		   whichWindow[i] = min; //��õ�min��ʾ��ǰ������������뿪
		   //������������firstTime
		   bool breakPoint = false;
		   for(int j = i-1;!breakPoint;j--){
			   if(whichWindow[j]==min && (servedTime[j]-transactionTime[j]) == firstTime[min]){
			       firstTime[min] += transactionTime[j];
				   breakPoint = true;
			   }
		   }
		   //���¼���˿͵�servedTime
		   breakPoint = false;
		    for(int j = i-1;!breakPoint;j--){
			   if(whichWindow[j]==min){
			       servedTime[i] += servedTime[j] + transactionTime[i];
				   breakPoint = true;
			   }
		   }
	   }
   }
   }
   for(int i=0;i<Nquery;i++){
	  if(servedTime[query[i]]<=540){
	  int hour = 8 + (servedTime[query[i]]/60);
	  int minute = servedTime[query[i]] % 60;
	  if(hour<10){
	     cout<<"0";
	  } cout<<hour<<":";
	  if(minute<10){
	     cout<<"0";
	  }cout<<minute<<endl;
	  }
	  else{
	     cout<<"Sorry"<<endl;
	  }
   }

   while(true){}
   return 0;
}