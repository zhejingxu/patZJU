#include<iostream>
#include<string>
using namespace std;

int main(void){	
	//freopen("D:/input.txt","r",stdin);
	string num;
	cin>>num;
	int sum = 0;
	for(int i=0;i<num.length();i++){
	   sum += num[i]-48;
	}
	string english[] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
	//输入的数次不超过100位，所以sum最大为900
	int bai = sum/100;
	int shi = sum/10%10;
	int ge = sum%10;

	if (0==sum){
	   cout<<"zero";
	}else{
		if(bai!=0){
		    cout<<english[bai]<<" ";
		}
		if(!(bai==0&&shi==0)){
		    cout<<english[shi]<<" ";
		}
		cout<<english[ge];
	}

	/*while(true){}*/
    return 0;
}
