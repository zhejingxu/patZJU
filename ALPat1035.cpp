#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

struct Pair{
    char username[11];
	char password[11];
};

int main()
{
	freopen("D:/pattest/passwordthree.txt","r",stdin);
	int count;
	int modified;
	bool ifmodified = false;
	char password[11];
	cin>>count;
	vector <Pair> vec;
	for(int i = 0;i<count;i++){
	   Pair p;
	   ifmodified = false;
	   cin>>p.username;
	   cin>>p.password;
	   //One solution is to replace 1 (one) by @, 0 (zero) by %, l by L, and O by o.
	   for(int j=0;j<11;j++){
		   if(p.password[j]=='1'){
			   ifmodified = true;
			   p.password[j] ='@';
		   }
		   if(p.password[j]=='0'){
			   ifmodified = true;
			   p.password[j] ='%';
		   }
		   if(p.password[j]=='l'){
			   ifmodified = true;
			   p.password[j] ='L';
		   }
		   if(p.password[j]=='O'){
			   ifmodified = true;
			   p.password[j] ='o';
		   }
	   }
	   if(ifmodified){
		   vec.push_back(p);
	   }
	}
	
	if(vec.size()==0){
		//这里要注意细节啊啊啊啊啊
		if(count==1){
		   cout<<"There is 1 account and no account is modified"<<endl;
		}else{
		   cout<<"There are "<<count<<" accounts and no account is modified"<<endl;
		}
	     
	}else{
		cout<<vec.size()<<endl;
		for(int i=0;i<vec.size();i++){
			cout<<vec[i].username<<" "<<vec[i].password<<endl; 
		}
	}
	while(true){}
    return 0;
}


