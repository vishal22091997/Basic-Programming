#include<iostream>
using namespace std;
void sortBub(int *a, int n){
	for(int i=0;i<n-1;i++){
		bool pass = false;
		for(int j=0;j<n-i;j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
				pass = true;
			}
		}
		if(!pass){
			break;
		}
	}
}
int main(){
	int n;
	cin>>n;
	int *a = new int[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sortBub(a,n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	
	
}
