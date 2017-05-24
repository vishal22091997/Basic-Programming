#include<iostream>
using namespace std;
int main(){
	int g;
	cin>>g;
	while(g--){
		int a,n;
		cin>>a>>n;
		bool print = false;
		 
		for(int i=0;i<n;i++){
			if(a==0){
				cout<<"No "<<i+1<<endl;
				print = true;
			}
			int x;
			cin>>x;
			if(x==0){
				a--;
			}else{
				a+=2;
			}
			
		}
		if(!print){
			cout<<"Yes "<<a<<endl;
		}
	}
}
