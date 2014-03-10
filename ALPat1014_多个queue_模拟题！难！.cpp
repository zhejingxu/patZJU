#include<stdio.h>
#include<stdlib.h>
#include<queue>
using namespace std;

/*
   该题目过程分为三个步骤：
   1. 在17:00之前，首先各个客户选择最短的队伍（同样长短选窗口序号最小）
   2. 需找当前最快结束的时间min，如果找不到最短时间，说明遍历结束，跳出while
   3. 通过min更新每个队伍的剩余时间
*/


const int NUM = 1001;
const int WINDOW = 21;
const int TIMELIMIT = 540;

typedef struct Person{
	int id;
	int timeleft;
};

queue <Person> line[WINDOW];
int time[NUM];
int result[NUM];

int main(void){
   freopen("D:\input.txt","r",stdin);

   int windowNum,cap,personNum,queryNum;
   scanf("%d%d%d%d",&windowNum,&cap,&personNum,&queryNum);

   for(int i=1;i<=personNum;i++){
	  scanf("%d",&time[i]);
	  result[i] = 0;
   }
   for(int i=1;i<windowNum;i++){
	  queue <Person> q;
      line[i] = q;
   }

   int timer = 0;   //记录当前的时间
   int personLeft = personNum;  //记录当前需要办理业务的人

   while(true){
	   	   
	       //遍历所有窗口所有队列中，寻找剩余人数最少的队伍
           if(timer<TIMELIMIT){
		   for(int i=1;i<=cap;i++){
			   for(int j=1;j<=windowNum;j++){
				   if(line[j].size() == i-1 && personLeft > 0){
				      Person p;
					  p.id = personNum - (personLeft--) + 1;
					  p.timeleft = time[p.id];
					  line[j].push(p);
				   }
			   }
		     }
		   }

		   //完成放入新客户的行为后，要进行寻找当前最小的等待时间min
		   int min = 0;
		   for(int i = 1;i <= windowNum; i++){
			   if(line[i].size()!=0){
				   if(min==0||min>line[i].front().timeleft){
					   min = line[i].front().timeleft;
				   }
			   }
		   }

		   if(min==0){
		      break;
		   }

		   timer += min;

		   //进行对所有对象的timeleft的更新
		   for(int i = 1;i <= windowNum; i++){
			   if(line[i].size()!=0){
			       line[i].front().timeleft -= min;
			   if(line[i].front().timeleft==0){
				   result[line[i].front().id] = timer;
				   line[i].pop();

				   if(timer >= TIMELIMIT){
					   while(!line[i].empty()){
						   line[i].pop();
					   }
				   }
			   }
		     }
		   }

	   
   }

   
   int query;
	   for(int i = 0; i < queryNum; i++){
		   scanf("%d",&query);
		   if(result[query]==0){
			   printf("Sorry\n");
		   }
		   else{
		      printf("%02d:%02d\n",result[query]/60+8,result[query]%60);
		   }
	   }

   while(true){}
   return 0;
}