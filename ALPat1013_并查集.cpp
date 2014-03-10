#include<iostream>
#include<vector>
using namespace std;

const int NUM = 1005;
int result = 0;
int citys[NUM];  //根据“并查集”的思想，在数组中每个节点存放的是自己的父节点，而根节点存放的就是自己

typedef struct Highways{
	int start;
	int stop;
};

int findFather(int child){
	if(!citys[child]){  //该节点当前为父节点
		return child;   //返回该父节点的值
	}
	else{
		citys[child] = findFather(citys[child]);   //直接将递归中获得Root作为所有子节点的数组元素！！！！！可以省下不少递归时间
	    return citys[child];   
	}
}


void calResult(int cityToCheck,int c1,int c2){
	if(cityToCheck==c1||cityToCheck==c2){
	    return;   //说明陷落的城市cityToCheck刚好是这条路线的c1或者c2，不影响连通分量
	}
	int c1_ = findFather(c1);   //需找特定节点的父节点（每个并查集用父节点来对比来判断是不是处于同一个集合）
	int c2_ = findFather(c2);
	if(c1_==c2_){   //父节点相同，表示c1和c2在同一个集合里，所以该路线不影响连通分量
	    return;
	}
	else{
	    result--;  //父节点不同，说明该路线的添加会影响连通分量，是的连通分量数目少了1个

		citys[c1_] = c2_;    //注意此处是将父节点进行合并！！！而不是citys[c1] = c2->最后一个case会报错的

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
		//每次完成一个case都要重新对并查集数组进行初始化，因为每个不同的cityToCheck都会影响并查集数组的组成
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

