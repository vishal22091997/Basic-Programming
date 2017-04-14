#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int *a = new int[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		int temp = a[i];
		int j;
		for( j=i-1;j>=0;j--){
			if(a[j]>temp){
				a[j+1] = a[j];
			}else{
				break;
			}
		}
		a[j+1] = temp;
	}
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	///Selection Sort...
	cout<<"Selection Sort...."<<endl;
	for(int i=0;i<n;i++){
		int min = a[i];
		for(int j=i;j<n;j++){
			if(a[j]<min){
				min = a[j];
			}
		}
		a[i] = min;
	}
	cout<<"Done Selection Sort"<<endl;
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	
	
	
	
	
}
