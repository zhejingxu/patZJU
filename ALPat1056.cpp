#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

/*
    模拟题：考虑比较机制和如何计算排名
*/

typedef struct Player{
	int weight;
	int round;
	Player(){ round = 0; }
	int index;
};

Player getWinner(queue<Player> q){
	Player fattest;
	fattest.weight = -1;
	int size = q.size();
	for (int i = 0; i < size; i++){
		Player p = q.front();
		q.pop();
		if (p.weight>fattest.weight){
			fattest = p;
		}
	}
	return fattest;
}

int main(){
	
	freopen("D:/input/input10562.txt", "r", stdin);

	int iPlayer, iGroup;
	scanf("%d %d", &iPlayer, &iGroup);
	vector <Player> players (iPlayer);
	queue <Player> q1, q2;

	for (int i = 0; i < iPlayer; i++){
		scanf("%d", &players[i].weight);
		players[i].index = i;
	}
	for (int j = 0; j < iPlayer; j++){
		int id;
		scanf("%d", &id);
		q1.push(players[id]);
	}

	int currentRound = 0;
	int roundAdd = 0;
	
	while (!q1.empty()){
		Player winner;
		if (currentRound == 0){
			currentRound = 1;
		}else{
			//int iWinner = q1.size() / iGroup + q1.size() % iGroup == 0 ? 0 : 1;
			int iWinner = q1.size() / iGroup;
			iWinner += (q1.size() % iGroup == 0? 0: 1);
			//增加轮数的总人数减去winner的数目
			roundAdd = q1.size() - iWinner;
			if (q1.size() == 1){
				Player p = q1.front();
				players[p.index].round = currentRound+1;
			    break;
			}
			currentRound += roundAdd;
		}
		int qSize = q1.size() / iGroup;
		for (int u = 0; u < qSize; u++){
			queue<Player> q;
			for (int t = 0; t < iGroup; t++){
				Player p = q1.front();
				q1.pop();
				players[p.index].round = currentRound;
				q.push(p);
			}
			winner = getWinner(q);
			q2.push(winner);
		}

		if (!q1.empty()){
		    winner = getWinner(q1);
		    qSize = q1.size();
		    for (int e = 0; e < qSize; e++){
			    Player pleft = q1.front();
			    q1.pop();
			    players[pleft.index].round = currentRound;
		     }
		    q2.push(winner);
		}

		qSize = q2.size();
		for (int k = 0; k < qSize; k++){
			Player p = q2.front();
			q1.push(p);
			q2.pop();
		}
		
	}

	for (int r = 0; r < players.size(); r++){
		printf("%d", currentRound - players[r].round +2);
		if (r != players.size() - 1){
			printf(" ");
		}
	}

	return 0;
}