#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,q;
	cin>>n>>q;
	int xorVal = 0;	
	int ans = 0;
	int *a = new int[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	while(q--){
		int type;
		cin>>type;
		if(type==1){
			int i,x;
			cin>>i>>x;
			a[i-1] = x;
		}else{
			int L,R,I,J;
			cin>>L>>R>>I>>J;
			int l,r,i,j;
			l =  1 + ((ans ^ L) % n);
			r = 1 + ((ans ^ R) % n);
			if(l > r) swap(l, r);
			i = 1 + ((I ^ ans) % (r - l + 1));
			j = 1 + ((J ^ ans) % (r - l + 1));
			if(i > j) swap(i, j);
			int size = 	r-l+1;
			int *b = new int[size];
			for(int x=0;x<size;x++){
				b[x] = a[l+x-1];
			}	
			 
			sort(b,b+size);
			xorVal = 0;
			for(int x=i;x<=j;x++){
				 
				xorVal ^= b[x-1];
			}
			ans = xorVal;
			cout<<xorVal<<endl;
		}
	}
}
