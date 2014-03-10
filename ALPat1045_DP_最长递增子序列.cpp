#include<stdlib.h>
#include<stdio.h>
#include<vector>
using namespace std;

int seq[201];
int dp[10001];

// DP问题最长子序列

int main(){
	
	//freopen("D:/input.txt", "r", stdin);

	int maxNum;
	scanf("%d", &maxNum);

	for (int j = 0; j < 201; j++){
		seq[j] = -1;
	}

	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		int num;
		scanf("%d", &num);
		seq[num] = i;   //可以根据数字检索到顺序
	}

	int M;
	scanf("%d", &M);

	vector<int> vec;
	for (int p = 0; p < M; p++){
		int temp;
		scanf("%d", &temp);
		if (seq[temp] != -1){
			vec.push_back(seq[temp]);
		}
	}

	int max = 0;

	if (vec.size()>0){
		dp[0] = 1;

		for (int q = 1; q < vec.size(); q++){
			dp[q] = 1;  //基本长度是1
			for (int t = 0; t < q; t++){
				if (vec.at(t) <= vec.at(q)){
					if (dp[t] + 1>dp[q]){
						dp[q] = dp[t] + 1;
					}
				}
			}
		}
		
		for (int k = 0; k < vec.size(); k++){
			if (dp[k]>max){
				max = dp[k];
			}
		}

	}

	printf("%d", max);
	system("pause");
	return 0;
}