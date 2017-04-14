#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<"Enter the number of indexes are there in the array"<<endl;
	cin>>n;
	int a[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	bool lower = true;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i][j]!=0){
				lower = false;
				break;
			}
		}
	}
	if(lower){
		cout<<"It is not a upper Triangular Matrix"<<" "<<lower<<endl;
	}else{
		cout<<"It is a Upper Triangular Matrix"<<" "<<lower<<endl;	
	}
	
}
