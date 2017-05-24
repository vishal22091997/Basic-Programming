#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int *a = new int[n];
	int curMax = INT_MIN;
	int times = 1;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		if(x>curMax){
			times = 1;
			curMax = x;
		}else if(x==curMax){
			times++;
		}
	}
	cout<<times<<endl;
		
}
