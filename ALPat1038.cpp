#include<iostream>
#include<vector>
#include<map>
#include<string>   //strcpy����������pat��Ҫʹ��string.hͷ�ļ�
#include<algorithm>
using namespace std;

/*
  5 32 321 3214 0229 87
  ���229 321 3214 32 87
  ���ַ��������˼�룺�������ַ���ǰ��ƴ�ӣ��Ա��ĸ�ƴ�ӽ���Ƚϴ�
  ע������ ����  4  00 00 12 011 ��� 1112
           ����  2  00 00 ���0  ---> case 2
*/
const int NUM = 100005;
string vec[NUM];

bool compare(string s1,string s2){
	string temp1 = s1+s2;
	string temp2 = s2+s1;
	//cout<<temp1<<" "<<temp2<<endl;
	//ȥ�����ִ���ͷ�ġ�0��
	while(temp1[0]== '0'&&temp1!="0"){
		temp1 = temp1.substr(1,-1);
	}
	while(temp2[0]== '0'&&temp2!="0"){
		temp2 = temp2.substr(1,-1);
	}
	if(temp1.size()!=temp2.size()){
		return temp1.size() < temp2.size();
	}
	for(int i=0;i<temp1.size();i++){
		if(temp1[i]!=temp2[i]){
		 //   cout<<temp1[i]<<" "<<temp2[i]<<endl;
			//cout<<"---------"<<endl;
			return temp1[i] < temp2[i];
		   
		}	
	}
	return false;
}

int main()
{
	freopen("D:/pattest/smallestnumber.txt","r",stdin);
	int n;
	cin>>n;
	string num;
	for(int k=0;k<n;k++){
		cin>>vec[k];
	}
	sort(vec,vec + n,compare);

	//�ѵ�һ��Ԫ�ص�0ȥ��������֮�⣬��ͷ����Ԫ�ؿ��ܶ���0
	int i = 0;
	string str = vec[i];
	while(str[0]== '0'){
		str = str.substr(1,-1);
		if(str=="" && i + 1<n){
		   i++;
		   str = vec[i];
		}else if(str=="" && i + 1 == n){ 	//ע�����û�����������������ΪO������
		   str = "0";
		   break;
		}
	}
	cout<<str;
	i++;
	if(n - i> 0){
	   for( ;i<n;i++){
	   cout<<vec[i];
	   }
	}
	while(true){}
    return 0;
}


