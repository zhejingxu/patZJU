#include<iostream>
#include<vector>
using namespace std;

const int NUM = 1005;
int result = 0;
int citys[NUM];  //���ݡ����鼯����˼�룬��������ÿ���ڵ��ŵ����Լ��ĸ��ڵ㣬�����ڵ��ŵľ����Լ�

typedef struct Highways{
	int start;
	int stop;
};

int findFather(int child){
	if(!citys[child]){  //�ýڵ㵱ǰΪ���ڵ�
		return child;   //���ظø��ڵ��ֵ
	}
	else{
		citys[child] = findFather(citys[child]);   //ֱ�ӽ��ݹ��л��Root��Ϊ�����ӽڵ������Ԫ�أ�������������ʡ�²��ٵݹ�ʱ��
	    return citys[child];   
	}
}


void calResult(int cityToCheck,int c1,int c2){
	if(cityToCheck==c1||cityToCheck==c2){
	    return;   //˵������ĳ���cityToCheck�պ�������·�ߵ�c1����c2����Ӱ����ͨ����
	}
	int c1_ = findFather(c1);   //�����ض��ڵ�ĸ��ڵ㣨ÿ�����鼯�ø��ڵ����Ա����ж��ǲ��Ǵ���ͬһ�����ϣ�
	int c2_ = findFather(c2);
	if(c1_==c2_){   //���ڵ���ͬ����ʾc1��c2��ͬһ����������Ը�·�߲�Ӱ����ͨ����
	    return;
	}
	else{
	    result--;  //���ڵ㲻ͬ��˵����·�ߵ���ӻ�Ӱ����ͨ�������ǵ���ͨ������Ŀ����1��

		citys[c1_] = c2_;    //ע��˴��ǽ����ڵ���кϲ�������������citys[c1] = c2->���һ��case�ᱨ���

		return;
	}
}

int main(void){	
	freopen("D:/input.txt","r",stdin);
	int cityNum,highwaysNum,checked;
	cin>>cityNum>>highwaysNum>>checked;

	Highways hw;
	vector <Highways> vec;
	for(int i = 0;i<highwaysNum;i++){
		cin>>hw.start;
		cin>>hw.stop;
		vec.push_back(hw);
	}
		
	int cityToCheck;
	for(int i=0;i<checked;i++){
		//ÿ�����һ��case��Ҫ���¶Բ��鼯������г�ʼ������Ϊÿ����ͬ��cityToCheck����Ӱ�첢�鼯��������
	    for(int i = 0;i<NUM;i++){
	        citys[i] = 0;
	    }
		result = cityNum - 2;
	    cin>>cityToCheck;
		for(int j = 0;j<vec.size();j++){
			calResult(cityToCheck,vec[j].start,vec[j].stop);
		}
	    cout<<result<<endl;
	}
	while(true){}
    return 0;
}

