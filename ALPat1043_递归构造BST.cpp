#include<iostream>
#include<vector>
#include<map>
#include<string.h>   //strcpy函数调用在pat中要使用string.h头文件
#include<algorithm>
using namespace std;

/*
   1.通过递归来生成二叉查找树
   2.查找右子树，其值为第一个大于等于根节点的值，得到右子树后可继续划分左字数和右子树
*/

const int NUM = 1005;
int a[NUM];
bool ifBST = true;
vector <int> vec;

void buildTree(int begin,int end,bool mirror){
	if(begin>end) return;
	int root = begin;
	int rightTreeRoot = end + 1;
	for(int i=root+1;i<=end;i++){
		if(!mirror){
			if(rightTreeRoot>end && a[root]<=a[i]){
				rightTreeRoot = i;
			}else if(rightTreeRoot<=end && a[root]>a[i]){
				ifBST = false;
				break;
			}
		}else{
			if(rightTreeRoot>end && a[root]>a[i]){
			    rightTreeRoot = i;
			}else if(rightTreeRoot<=end && a[root]<= a[i]){
			    ifBST = false;
				break;
			}
		}
	}
	buildTree(root+1,rightTreeRoot-1,mirror);
	buildTree(rightTreeRoot,end,mirror);
	vec.push_back(a[root]);
}

int main()
{
	freopen("D:/pattest/ifBSTthree.txt","r",stdin);
	int n; cin>>n;
	for(int i=0;i<n;i++){
	   cin>>a[i];
	}
	buildTree(0,n-1,false);
	if(!ifBST){
	   ifBST = true;
	   vec.clear();
	   buildTree(0,n-1,true);
	}
	if(!ifBST){cout<<"NO";}
	else{
	   cout<<"YES\n";
	   for(int i=0;i<vec.size();i++){
	       cout<<vec[i];
		   if(i!=vec.size()-1){
		     cout<<" ";
		   }
	   }
	}
	while(true){}
    return 0;
}


