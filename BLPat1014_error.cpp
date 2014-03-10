#include <iostream>
#include <string>
using namespace std;

int main(void){
	string str1,str2,str3,str4;
	cin>>str1>>str2>>str3>>str4;

	string DAY [7] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
	int len1,len2;
	if(str1.length()>=str2.length()){
		len1 = str2.length();
	}else len1 = str1.length();
	int i = 0;
	for( ;i<len1;i++){
		   if(str1[i]==str2[i]&&'A'<str1[i]&&'Z'>str1[i]){
				switch(str1[i]){
				case 'A':cout<<DAY[0]<<" ";break;
				case 'B':cout<<DAY[1]<<" ";break;
				case 'C':cout<<DAY[2]<<" ";break;
				case 'D':cout<<DAY[3]<<" ";break;
				case 'E':cout<<DAY[4]<<" ";break;
				case 'F':cout<<DAY[5]<<" ";break;
				case 'G':cout<<DAY[6]<<" ";break;
				}
				break;
		}
	}
	i++;
	for( ;i<len1;i++){
		   if(str1[i]==str2[i]){
			   if(str1[i]>'0'&&str1[i]<'9'){
			       cout<<(int)(str1[i]-'0')<<":";
			   }
			   if(str1[i]>'A'&&str1[i]<'N'){
				   cout<<(int)(str1[i]-'A')+10<<":";
			   }
			   break;
		}
	}

	if(str3.length()>=str4.length()){
		len2 = str4.length();
	}else len2 = str3.length();

	for(int j=0;j<len2;j++){
		if(str3[j]==str4[j]&&( (str3[j]>'A'&&str3[j]<'Z')||(str3[j]>'a'&&str3[j]<'z'))){
			if(j<10){
			  cout<<'0';
			}
			cout<<j<<endl;
		    break;
		}
		
	}

	system("pause");
    return 0;
}