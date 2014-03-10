#include<stdlib.h>
#include<stdio.h>
#include<vector>
using namespace std;

const int MAX = 100001;

int main(){
	
	freopen("D:/input.txt", "r", stdin);

	int N;
	scanf("%d", &N);

	int distance[MAX];
	int total = 0;
	distance[0] = 0;
	for (int i = 1; i <= N; i++){
		int len;
		scanf("%d",&len);
		total += len;
		distance[i] = len + distance[i-1];//distance[1]表示第一个城市到当前城市的距离
	}

	int M;
	scanf("%d", &M);
	for (int j = 0; j < M; j++){
		int city1, city2;
		scanf("%d", &city1);
		scanf("%d", &city2);
		if (city1>city2){
			int temp = city1;
			city1 = city2;
			city2 = temp;
		}
		int len = distance[city2-1] - distance[city1-1];
		if (len > (total - len)){
			len = total - len;
		}
		printf("%d\n", len);
	}

	//system("pause");
	return 0;
}