#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

/*
   
*/

// MAX = 501的时候case3无法通过
//const int MAX = 501;   
const int MAX = 1000;

int main(){
	
	freopen("D:/input/input3.txt", "r", stdin);

	int value[MAX];
	int num, toPay;
	scanf("%d%d", &num, &toPay);

	for (int k = 0; k < MAX; k++){
		value[k] = 0;
	}

	for (int i = 0; i < num; i++){
		int temp;
		scanf("%d", &temp);
		value[temp] ++;
	}

	int v1 = 0, v2 = 0;

	for (int j = 1; j <= toPay/2; j++){
		value[j]--;
		value[toPay - j]--;
		if (value[j] >= 0 && value[toPay - j] >= 0){
			v1 = j;
			v2 = toPay - j;
			break;
		}
	}

	if (v1 != 0 && v2 != 0){
		printf("%d %d", v1, v2);
	}
	else{
		printf("No Solution");
	}

	return 0;
}