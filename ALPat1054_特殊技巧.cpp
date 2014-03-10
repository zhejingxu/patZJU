#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

/*

*/

int main(){
	
	freopen("D:/input/input1054.txt", "r", stdin);
	int M, N;
	scanf("%d %d", &M, &N);

	int curCor = -1, curCounts = 0;
	for (int i = 0; i < M*N; i++){
		int tempCor = -1;
		scanf("%d", &tempCor);
		if (tempCor == curCor){
			curCounts++;
		}
		else if (curCounts==0){
			curCounts = 1;
			curCor = tempCor;
		}else{
			curCounts--;
			if (curCounts == 0){
				curCor = -1;
			}
		}
	}
	printf("%d", curCor);
	return 0;
}