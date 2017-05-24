#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int> ipair;
int main(){
	priority_queue<ipair, vector<ipair>, greater<ipair> > q;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		q.push(make_pair(x, i));
	}	
	while(!q.empty()){
		int val = q.top().second;
		q.pop();
		cout<<val;
	}
}

