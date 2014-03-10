/*
 http://pat.zju.edu.cn/contests/pat-a-practise/1026
 ����ģ���⣬���̣߳�ѭ������������˵��߼������ѭ������ʱ�䴰�ڵ�Ҫ�򵥡�

 ����̫���ˣ���Ĳ����Լ�д~�ͳ������ϵĴ�
 
 ��ֹ2013-7��PAT��1026�Ĳ������ݶ������⣬��ʹ����caseûͨ����Ҳ��AC��
 
 2
 10:00:00 30 1
 12:00:00 30 1
 5 1
 3
 
 0 0 2 0 0
 */

#include<stdio.h>
#include<algorithm>
#include<deque>
#include<math.h>
using namespace std;
#define END 13*60*60

struct player{
    int arrive, process, vip;
} players[10005];

struct table{
    int servedCount, vip, available, id;
}tables[101];

int n, k, m;

bool operator <(const player &a, const player &b)
{
    return a.arrive < b.arrive;
}

bool operator <(const table &a, const table &b)
{
    if (a.available == b.available)
        return a.id < b.id;
    else
        return a.available < b.available;
}

bool sortt(const table &a, const table &b)
{
    return a.id < b.id;
}
int main()
{
	freopen("D:/tabletennis.txt","r",stdin);
    scanf( "%d", &n);
    for (int i = 1; i <= n; ++ i){
        int h, m, s, p, v;
        scanf( "%d:%d:%d %d %d", &h, &m, &s, &p, &v);
        players[i].arrive = (h - 8)*3600 + m*60 + s;
        players[i].process = p > 120 ? 120 : p;
        players[i].vip = v;
    }
	//ע����������sort���㣬��һ������������ĵ�һ��Ԫ�أ��ڶ������������һ��Ԫ�ص��ٺ�һ��Ԫ��
    sort(players + 1, players + n + 1);  
    
    scanf( "%d %d", &k, &m);
    for (int i = 1; i <= k; ++ i)
        tables[i].id = i;
    while(m --) {
        int tmp;
        scanf( "%d", &tmp);
        tables[tmp].vip = 1;
    }

    //deque˫�˶���
    deque<int> waiting;

	//players�Ĵ����α꣬��ǵ�һ��δ�������player
    int cur = 1;
    int timer = 0;

	//whileѭ��ÿ�δ���һ��pair��һ�����ӣ���Ϊpair���Ⱥ�˳��ģ�����ÿ�ο���ֻ����һ����
    while(timer < END) {

		//������ǰʱ��timerǰ��������pair�����뵽deque��
        while (cur <= n && players[cur].arrive <= timer){
			waiting.push_back(cur ++);
		}
        
		//�����ǰʱ��û��pair����ȴ�����Ϊ�գ�����ѡ�����µ�һ��pair������arrive time����timer
        if (waiting.size() == 0) {

            if (cur <= n && players[cur].arrive < END) {
                timer = players[cur].arrive;
                waiting.push_back(cur ++);

				//������timer֮�󣬽�ԭ�Ⱦ�available�����ӵĿ���ʱ�����Ϊtimer
                for (int i = 1; i <= k; ++ i) {  
                    if (tables[i].available < timer) {
                        tables[i].available = timer;
                    }
                }

                //�����ӽ�����������
                sort(tables + 1, tables + k);

            }else { 
				//cur>n ����ʱ�䳬��timer���ù��̽���
                break;
            }
        }
        
        int vip = 0;
		//�ҵ���ǰ�ȴ������е�һ��vip
        for (int i = 0; i != waiting.size(); ++ i)
            if (players[waiting[i]].vip){
                vip = waiting[i];
                break;
            }
        //�����ǰ���д���vip��Ѱ�ҵ�ǰ��vip����
        int viptable = 0;
        if (vip)
            for (int i = 1; i <= k && tables[i].available == timer; ++ i)
                if (tables[i].vip) {
                    viptable = i;
                    break;
                }
        
        //ȷ����ǰѭ����Ҫ���������curt����Աcurp
        int curp, curt;
        if (viptable) {
            curt = viptable;
            curp = vip;
			//��������c++�е�ʹ�ã���
            for (deque<int>::iterator it = waiting.begin(); it != waiting.end(); ++ it)
                if ((*it) == vip) {
                    waiting.erase(it);
                    break; 
                }
        }else {
			//���û��vip pair��ֱ��ȡ����һ��pair����
            curp = waiting.front();
            waiting.pop_front();
            curt = 1;
        }
        
        int art = players[curp].arrive;
        int stt = timer;
		//floor(x)ȡ������x�������������floor(9.99) = 9 ����Ҫ����3.5->4 
        printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", art/3600 + 8, art/60%60, art%60, stt/3600 + 8, stt/60%60, stt%60, (int)floor((stt - art)/60.0 + 0.5)); //ע��cell������ʹ��
        
		//���±�ʹ�õ�table��Ϣ
        tables[curt].servedCount ++;
        tables[curt].available = timer + players[curp].process * 60;
        
        //���Ĺ�������table����������׼����һ�ֵĴ���
        sort(tables + 1, tables + k + 1);
        timer = tables[1].available;
    }
    
	//��ԭ�����ҵ�tablesͨ��id���½��й���
    sort(tables + 1, tables + k + 1, sortt);
    
	for (int i = 1; i <= k; ++ i) {
        printf( "%d",tables[i].servedCount);
        if (i != k)
            printf( " ");
    }
	while(true){}
    return 0;
}