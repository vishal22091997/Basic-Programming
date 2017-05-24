#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	
	
	int n;
	cin>>n;
	ll prod = 1;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		prod*=x;
	}
	ll num = 1;
	ll temp = 1;
	while(prod>temp){
		num++;
		temp = pow(num, n);	
	}
	cout<<num;
}
