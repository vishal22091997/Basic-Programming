#include<iostream>
using namespace std;
void mergeSort(int left[], int right[], int A[], int lena, int lenb ){
	int j = 0, k = 0, i = 0;
	 cout<<lena<<" "<<lenb;
	 
	while(j<lena&&k<lenb){
		if(left[j]>right[k]){
			A[i++] = right[k++];
		}else{
			A[i] = left[j];
		}
	}
	if(j<lena){
		while(j<lena){
			A[i++] = left[j++]; 
		}
	}
	
	if(k<lenb){
		while(k<lenb){
			A[i++] = left[k++]; 
		}
	}
	 cout<<"end"<<endl;
}
void merge(int A[],int low,int high){
	if(high>low){
		int mid = (low+high)/2;
		merge(A, low, mid);
		merge(A, mid+1, high);
		mergeSort(A, low, mid, high);
	}
	
}



int main(){
	cout<<"Enter the Elements you want to enter in the Array";
	int n;
	cin>>n;
	int *A = new int[n];
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	merge(A,0,n);
	cout<<"After Sorting..."<<endl;
	for(int i=0;i<n;i++){
		cout<<A[i]<<" ";
	}
}
