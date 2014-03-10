#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int BEGIN = 8 * 60 * 60;
const int END = 17 * 60 * 60;
/*
   类似于操作系统FCFS进程调度

   用priority_queue建立一个队列，模拟所有K个窗口。优先队列将结束时间最早的人放到队列的顶端，
   每次循环处理一个人的结束。然后步入一个黄线外等待的人。如果那个时刻，下一个人还没有达到，
   则可以将该人开始执行的时间记录为他的到达时间，并加入队列中。 

   还有一点需要注意的：HH:MM:SS的时间格式，可以转换为累积秒数的时间，方便计算比较。
*/

typedef struct Person{
    int arrive;
	int process;
	int start;
};

vector <Person> vec;

int customerNum = 0;
int windowNum = 0;

bool compare(Person p1,Person p2){
	return p1.arrive < p2.arrive;
}

bool operator<(Person p1,Person p2){
	return p1.start + p1.process > p2.start + p2.process;
}

int main(void){
   freopen("D:\queueingatbank.txt","r",stdin);
   cin>>customerNum>>windowNum;
   for(int i=0;i<customerNum;i++){
       Person p;
	   int hour,minute,second;
	   scanf("%d:%d:%d %d",&hour,&minute,&second,&p.process);
	   p.process *= 60;
	   p.arrive = hour * 60 * 60 + minute * 60 + second;
	   p.start = p.arrive;
	   if(p.arrive <= END){
	      vec.push_back(p);
	   }
   }
   sort(vec.begin(),vec.end(),compare);
   
   priority_queue<Person> windows;
   int index = 0;
   int total = 0;
   int timer = BEGIN;
   bool breakPoint = false;
   while(index < vec.size()){
	   while(windows.size() < windowNum){
		   	   /*case 02：只有一个case时，要判断index
	              1 3   
		          17:00:00 16
	           */
		   if(index >= vec.size()){
		       break;
		   }
		   if(vec[index].arrive <= timer){
			   vec[index].start = timer;
		   }else{
			   timer = vec[index].arrive;
		   }
		   windows.push(vec[index]);
		   total += vec[index].start - vec[index].arrive;
		   index++;
	   }

	   if(index >= vec.size()){
		       break;
	   }

	   Person p = windows.top();
	   windows.pop();
	   timer = p.start + p.process;
   }
   printf("%.1f",(total/60.0/vec.size()));
   while(true){}
   return 0;
}

