#include<iostream>
#define MSIZE 10
using namespace std;
int size = 0;

int left(int i){
	return 2*i+1;
}
int right(int i){
	return 2*i+2;
}
int parent(int i){
	return (i-1)/2;
}

void siftUp(int i, int a[]){
	int pindex = (i-1)/2;
	if(a[pindex]<a[i]){
		cout<<"Interchanging "<<a[pindex]<<" and "<<a[i]<<endl;;
		int temp = a[i];
		a[i] = a[pindex];
		a[pindex] = temp;
		siftUp(pindex,a);
	}	
}
void insert(int x, int a[]){
	if(size>=MSIZE){
		cout<<"Queue Size Full";
	}
	a[size++] = x;
	siftUp(size-1,a);
}
void siftDown(int i,int a[]){
	int mindex = i;
	int lChild = left(i);
	int rchild = right(i);
	if(lChild<=size&&a[lChild]>a[i]){
		mindex = lChild;
	}
	if(rchild<=size&&a[rchild]>a[mindex]){
		mindex = rchild;
	}
	if(i!=mindex){
		int temp = a[i];
		a[i] = a[mindex];
		a[mindex] = temp;
		siftDown(mindex,a);
	}
}
void extractMax(int a[]){
	int val = a[0];
	a[0] = a[size-1];
	siftDown(0, a);
	size--;
	cout<<val<<endl;
}

void print(int a[]){
	for(int i=0;i<size;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

int main(){
 
	int *a = new int[MSIZE];
	for(int i=0;i<MSIZE;i++){
		int x;
		cin>>x;
		insert(x,a);
		print(a);
	}
	extractMax(a);
	
}
