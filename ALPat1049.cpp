#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

/*
   ����������Ч�ʲ���ȡ����λ��ʮλ�ȵ�1�Ĵ�������ǰ���������أ���һ���Ĺ���
   ���֮��132ҳ
   2^30 = 1 073 741 824 ������int��������
*/

int main(){
	
	freopen("D:/input/input1049.txt", "r", stdin);

	int n;
	scanf("%d", &n);
	int lowNum = 0;
	int currentNum = 0;
	int highNum = 0;
	int iFactor = 1;
	int iCount = 0;

	while (n / iFactor!=0){
		lowNum = n - (n / iFactor)*iFactor;
		currentNum = (n / iFactor) % 10;
		highNum = n / (iFactor * 10);
		switch (currentNum)
		{
		case 0:
			iCount += highNum * iFactor;
			break;
		case 1:
			iCount += highNum * iFactor + lowNum + 1;
			break;
		default:
			iCount += (highNum + 1)*iFactor;
			break;
		}
		iFactor *= 10;
	}

	printf("%d", iCount);

	return 0;
}