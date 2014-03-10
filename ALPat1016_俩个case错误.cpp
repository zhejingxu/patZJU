#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

/*
   1.从输入的信息中分解问题 注意字符串数组的比较和分解！！！
   2.结构体排序问题：排序规则 name -> on>off -> day -> hour -> minute
   3.对于每个on的记录寻找off记录中在其时间后最小的那项
   4.注意对于chargeTotal==0的记录则不输出任何结果！！！！case2

   5.注意以下排序后的情况：
   10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 7
5
0 01:02:14:22 on-line
0 01:02:14:23 on-line
0 01:02:14:24 off-line
0 01:02:14:25 off-line
0 01:02:14:26 off-line

   当第二组和第三组配对后，第一组就不能在和第四组配对
   */

typedef struct Record{
	char name[21];
	int day;
	int hour;
	int minute;
    int totaltime;
	bool ifOn;
	bool ifPaired;
};

vector <Record> records;
int costs[48];
int dayFee = 0;  //一整天的所有费用

bool compare(Record rec1,Record rec2){
	int result = strcmp(rec1.name,rec2.name);
	if(result!=0){
	   return result < 0;
	}
	return rec1.totaltime < rec2.totaltime;
}

int calCharge(int beginHour,int beginMinute,int total){
	int charge = 0;

	//天数差产生的total
	int day = total/(24*60);
	charge += day * dayFee;
	total %= (24*60);

	//分钟差产生的total
	charge += costs[beginHour] * (60-beginMinute);
	total -= (60-beginMinute);

	//小时数差产生的total
	int hour = total/60;
	int i = beginHour+1;

	for( ;i<beginHour+1+hour;i++){
	    charge += costs[i]*60;
	}
	charge += costs[i]*(total%60);

	return charge;
}

int main(void){
   freopen("D:\input2.txt","r",stdin);
   int month;

   for(int i=0;i<24;i++){
      scanf("%d",&costs[i]);
	  costs[i+24] = costs[i];
	  dayFee += costs[i]*60;
   }
   int recordNum;
   scanf("%d",&recordNum);
   if(recordNum==0){
      return 0;
   }
   for(int i=0;i<recordNum;i++){
	  char s[10];
      Record r;
	  scanf("%s %d:%d:%d:%d %s",r.name,&month,&r.day,&r.hour,&r.minute,s);
	  r.totaltime = r.day*24*60 + r.hour * 60 + r.minute;
	  if(s[1]=='n'){
		  r.ifOn = true;
	  }else{
		  r.ifOn = false;
	  }
	  r.ifPaired = false;
	  records.push_back(r);
   }

   sort(records.begin(),records.end(),compare);

   double chargeTotal;
   char tempName[21];
   bool ifNewCustomer = false;
   bool ifCanTotal = false;
   for(int i = 0;i<records.size();i++){
	   
	   if(strcmp(tempName,records[i].name)!=0){   //检测到一个新的客户姓名，要输入上个用户名的总账单
		   if(ifCanTotal){  //判断有没有上一个客户要输出信息
		      printf("Total amount: $%.2f\n",chargeTotal/100);
			  ifCanTotal = false;
		   }
		   ifNewCustomer = true;
		   chargeTotal = 0;
		   strcpy(tempName,records[i].name);
	   }

	   if(!records[i].ifOn && i!= 0){
		   bool breakpoint = false;
		   for(int j = i-1;j>=0 ;j--){
			   if(records[j].ifOn && strcmp(tempName,records[j].name)==0 && !records[j].ifPaired && !breakpoint){
				  double charge = (double)calCharge(records[j].hour,records[j].minute ,records[i].totaltime - records[j].totaltime);
				  records[j].ifPaired = true;
				  records[i].ifPaired = true;
				  chargeTotal += charge;
				  ifCanTotal = true;
				  if(ifNewCustomer){
				      printf(records[i].name);
		              printf(" %02d\n",month);
				  }ifNewCustomer = false;
				  printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",records[j].day,records[j].hour,records[j].minute,records[i].day,records[i].hour,records[i].minute,records[i].totaltime - records[j].totaltime,charge/100);
				  breakpoint = true;
			   }
			   records[j].ifPaired = true;
		   }
	   }
   }   
       if(ifCanTotal){
		   printf("Total amount: $%.2f\n",chargeTotal/100);
	   }
   while(true){}
   return 0;
}
