#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int grade;
		cin>>grade;
		int nextFive = (grade/5+1)*5;
		if(grade>=38){
			if(nextFive-grade<3){
			cout<<nextFive<<endl;
			}else{
				cout<<grade<<endl;
			}
		}else{
			cout<<grade<<endl;
		}
	}
}
