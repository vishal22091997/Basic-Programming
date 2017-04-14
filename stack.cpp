#include<iostream>
using namespace std;
int A[10];
int top = -1;
bool push(int data){
	if(top<10){
		A[++top] = data;
		return true;
	}else{
		return false;
	}
}
int pop(){
	if(top>=0){
		int data = A[top--];
		return data;
	}else{
		return -1;
	}
}
int main(){
	while(true){
		cout<<"what to do?: ";
		int x;
		cin>>x;
		if(x%2==0){
			cout<<"push: ";
			int x;
			cin>>x;
			push(x);
		}else{
			int val =  pop();
			if(val==-1){
				cout<<"No data";
			}else{
				cout<<val;
			}
	
		}
	}
	
	
}
