#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

/*
   Ƶ������PeekMedian����ʱ�������򣬵����˳�ʱ��
   ������״���飬��֮����ͨ�Ķ��ַ����������޶���100ms�ڵõ������
*/


bool compare(int a, int b){
	return a < b;
}

int main(){
	
	freopen("D:/input/stack1057.txt", "r", stdin);
	vector<int> vec;

	int iCommand;
	scanf("%d", &iCommand);
	for (int i = 0; i < iCommand; i++){
		char command[15];
		scanf("%s", command);

		if (command[1] == 'u'){
			//push������ȡ���е�����
			int num;
			scanf("%d", &num);
			vec.push_back(num);
		}

		if (command[1] == 'o'){
			if (vec.size() == 0){
				printf("Invalid\n");
			}else{
				printf("%d\n", vec[vec.size()-1]);
				//end() ��ָ���������һ��Ԫ�صĺ�һ��λ��
				vec.erase(vec.end()-1);
			}
		}

		if (command[1] == 'e'){
			if (vec.size() == 0){
				printf("Invalid\n");
			}
			else{
				vector<int> copy;
				for (int j = 0; j < vec.size(); j++){
					int temp = vec[j];
					copy.push_back(temp);
				}
				sort(copy.begin(), copy.end(), compare);
			    int pos = 0;
			    if (vec.size() % 2 == 0){
					pos = vec.size() / 2 - 1;
				}
				else{
					pos = (vec.size()-1)/2;
				}
			    printf("%d\n", copy[pos]);
			}
		}
	}

	return 0;
}