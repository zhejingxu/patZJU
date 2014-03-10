#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct Person{
    string id;
	string signIn;
	string signOut;
};

bool compare(string str1,string str2){
	
	for(int i=0;i<8;i++){
		if(str1[i]<str2[i]){
		   return true;
		}
		else if(str1[i]>str2[i]){
		   return false;
		}
	}
}

int main(void){	
	freopen("D:/input.txt","r",stdin);
	int n;
	cin>>n;
	Person p;
	vector <Person> vec;
	
	for(int i=0;i<n;i++){
		cin>>p.id;
		cin>>p.signIn;
		cin>>p.signOut;
		vec.push_back(p);
	}
	int first = 0,last = 0;
	string currentSignIn = vec[0].signIn,currentSignOut = vec[0].signOut;
	if(n>1){
	  for(int i=0;i<n;i++){
		if(!compare(currentSignIn,vec[i].signIn)){
			currentSignIn = vec[i].signIn;
			first = i;
		}
		if(compare(currentSignOut,vec[i].signOut)){
			currentSignOut = vec[i].signOut;
			last = i;
		}
	   }
	}
	cout<<vec[first].id<<" "<<vec[last].id;

	while(true){}
    return 0;
}
