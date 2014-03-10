#include<stdlib.h>
#include<stdio.h>
#include<vector>
using namespace std;

/*
   ��������ʱʹ������forѭ��������ñ����ķ�������������case��ʱ
   ����Ҫ���㷨�����Ż�������[i,j]��������Ҫ������һ��ֱ�Ӵ�[i+1,j]֮��ʼ������ʡȥ�м�ļ���ʱ��
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