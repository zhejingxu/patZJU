#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

/*
   暴力方法的效率不可取，个位、十位等的1的次数与其前后的数字相关，有一定的规律
   编程之美132页
   2^30 = 1 073 741 824 可以用int数据类型
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