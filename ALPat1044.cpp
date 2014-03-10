#include<stdlib.h>
#include<stdio.h>
#include<vector>
using namespace std;

/*
   遍历数列时使用两个for循环，如果用暴力的方法，会有两个case超时
   所以要对算法进行优化，比如[i,j]数列满足要求，则下一次直接从[i+1,j]之后开始遍历，省去中间的计算时间
*/

typedef struct Line{
	int begin;
	int end;
	int sum;
};

int main(){
	int N, value;
	scanf("%d %d", &N, &value);

	vector <int> a;
	vector <int> aSum;
	vector <Line> b;

	int temp,sumCurrent=0;
	for (int i = 0; i < N; i++){
		scanf("%d", &temp);
		sumCurrent += temp;
		a.push_back(temp);
		aSum.push_back(sumCurrent);
	}

	int sum;
	int minSum = 0;
	int point2end;
	for (int j = 0; j < N; j++){
		sum = 0;
		point2end = -1;
		if (j != 0){
			point2end = b.at(j - 1).end;
			sum = aSum.at(point2end)-aSum.at(j-1); 
		}
		int k = point2end+1;
		while (k < N){
			if (sum >= value){
				if (minSum == 0){
					minSum = sum;
				}
				if (sum < minSum){
					minSum = sum;
				}
				break;
			}
			sum += a.at(k);
			k++;
		}

		if (minSum == 0){
			minSum = sum;
		}
		if (sum >= value && sum<minSum){
			minSum = sum;
		}
		
		Line line;
		line.sum = sum;
		line.begin = j;
		line.end = k - 1;
		if (sum < value){break;}
		b.push_back(line);
	}

	for (int p = 0; p < b.size(); p++){
		Line tempLine = b.at(p);
		if (tempLine.sum == minSum){
			printf("%d-%d\n", tempLine.begin+1, tempLine.end+1);
		}
	}

	system("pause");
	return 0;
}