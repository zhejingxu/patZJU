#include<stdio.h>
#include<stdlib.h>
#include<queue>
using namespace std;

/*
   ����Ŀ���̷�Ϊ�������裺
   1. ��17:00֮ǰ�����ȸ����ͻ�ѡ����̵Ķ��飨ͬ������ѡ���������С��
   2. ���ҵ�ǰ��������ʱ��min������Ҳ������ʱ�䣬˵����������������while
   3. ͨ��min����ÿ�������ʣ��ʱ��
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

   int timer = 0;   //��¼��ǰ��ʱ��
   int personLeft = personNum;  //��¼��ǰ��Ҫ����ҵ�����

   while(true){
	   	   
	       //�������д������ж����У�Ѱ��ʣ���������ٵĶ���
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

		   //��ɷ����¿ͻ�����Ϊ��Ҫ����Ѱ�ҵ�ǰ��С�ĵȴ�ʱ��min
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

		   //���ж����ж����timeleft�ĸ���
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