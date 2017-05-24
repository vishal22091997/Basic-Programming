#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	cin>>n>>k;
	int a[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			a[i][j] = 0;
		}
	}
	int cpos, rpos;
	cin>>cpos>>rpos;
	cpos--;rpos--;
	for(int i=0;i<k;i++){
		int c,r;
		cin>>c>>r;
		a[r-1][c-1] = -1;
	}
	int l,r,u,d,ul,ur,dl,dr;
	int tot = 0;
	for(int i=rpos+1;(i<n&&a[rpos][i]==0);i++){
		if(a[rpos][i]==0){
			tot++;
		}
		// right movement
	}
	for(int i=rpos-1;(i>=0&&a[rpos][i]==0);i--){
		if(a[rpos][i]==0){
			tot++;
		}
		//left movement
	}
	for(int i=cpos-1;(i<n&&a[rpos][i]==0);i++){
		if(a[rpos][i]==0){
			tot++;
		}
		//up movement
	}
	for(int i=rpos+1;(i<n&&a[rpos][i]==0);i++){
		if(a[rpos][i]==0){
			tot++;
		}
	}
	for(int i=rpos+1;(i<n&&a[rpos][i]==0);i++){
		if(a[rpos][i]==0){
			tot++;
		}
	}
	for(int i=rpos+1;(i<n&&a[rpos][i]==0);i++){
		if(a[rpos][i]==0){
			tot++;
		}
	}
	for(int i=rpos+1;(i<n&&a[rpos][i]==0);i++){
		if(a[rpos][i]==0){
			tot++;
		}
	}
	for(int i=rpos+1;(i<n&&a[rpos][i]==0);i++){
		if(a[rpos][i]==0){
			tot++;
		}
	}
	
	
	
	
	
	
}
