#include<iostream>
#include<cmath>
using namespace std;
typedef long long int ll;
ll give(int n,int k){
	if(k==1){
		return n;
	}else{
		return pow(n,give(n,k-1));
	}
}
int main(){
	int n;
	cin>>n;
	cout<<give(n, 5);
}
