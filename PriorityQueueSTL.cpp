#include<iostream>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
struct Node{
	int w;
	Node* next;
	int v;
};
Node* createNode(int v, int w){
	Node* newNode = new Node();
	newNode->next = NULL;
	newNode->w = w;
	newNode->v = v; 
	return newNode;
}
void edge(Node* a[], int u, int v, int w){
	Node* head = a[u];
	Node* newNode = createNode(v,w);
	newNode->next = head;
	a[u] = newNode;
	Node* head2 = a[v];
	Node* newNode2 = createNode(u,w);
	newNode2->next = head2;
	a[v] = newNode2;
}
void printEdges(Node* a[], int n){
	for(int i=0;i<n;i++){
		Node* head = a[i];
		while(head!=NULL){
			cout<<i<<"->"<<head->v<<" "<<endl;;
			head = head->next;
		}
		cout<<endl;
	}
}
void depthFirst(Node* a[], int visit[], int u){
	Node* head = a[u];
	cout<<u<<" ";
	visit[u] = 1;
	while(head!=NULL){
		int cur = head->v;
		if(visit[cur]!=1){
			depthFirst(a,visit,cur);		 
		}
		head = head->next;
	}
	
}
int* breadthFirst(Node *a[] , int visit[], int u, int n){
	int *array = new int[n];
	visit[u] = 1;
	cout<<u<<" ";
	array[u] = 0;
	queue<int> q;
	q.push(u);
	int val = 1;
	while(!q.empty()){
		
		Node* head = a[q.front()];
		q.pop();
		while(head!=NULL){
			int cur = head->v;
			if(visit[cur]!=1){
				cout<<cur<<" ";
				visit[cur] = 1;
				q.push(cur);
				array[cur] = val;
			}
			head = head->next;
		}
		val++;
		
	}
	return array;
	
}
int* dishstra(Node* a[], int u, int n){
	int* set = new int[n];
	int* dist = new int[n];
	for(int i=0;i<n;i++){
		set[i] = 0;
		dist[i] = INT_MAX;
	}
	set[u] = 1;
	dist[u] = 0;
	Node* head = a[u];
	int work = u;
	while(head!=NULL){
		int cur = head->v;
		int w = head->w;
		if(dist[cur]>dist[work]+w){
			dist[cur] = dist[work]+w;
		}
		head = head->next;
		if(head==NULL){
			int min = INT_MAX, index = -1;
			for(int i=0;i<n;i++){
				if(set[i]!=1&&dist[i]<min){
					min = dist[i];
					index = i;
				}
			}
			if(index==-1){
				break;
			}else{
				head = a[index];
				work = index;
				set[index] = 1;
			}
		}
	}
	

	
	return dist;
	
}


int main(){
	int n, edges;
	cout<<"Enter Nodes and Edges respectively";
	cin>>n>>edges;
	cout<<"Right Now Working on the undirected Graphs:";
	Node* a[n] ;
	for(int i=0;i<n;i++){
		a[i] = NULL;
	}
	while(edges--){
		int u,v,w;
		cin>>u>>v>>w;
		edge(a, u,v,w);
	}
	printEdges(a, n);
	int visit[n];
	
	int x;
	while(true){
		cout<<"Enter the starting node for depth first search: ";
		cin>>x;
		for(int i=0;i<n;i++){
			visit[i] = 0;
		}
		cout<<"Depth First Search... ";
		depthFirst(a,visit,x);
		cout<<endl<<"Breadth First Search...";
		for(int i=0;i<n;i++){
			visit[i] = 0;
		}
		cout<<endl;
		int* array = breadthFirst(a,visit,x,n);
		cout<<endl<<"Distances of each node from the given node: ";
		for(int i=0;i<n;i++){
			cout<<array[i]<<" ";
		}
		cout<<endl;
		int start;
		cout<<"Enter the starting node:";
		cin>>start;
		int* dist = dishstra(a,start,n);
		for(int i=0;i<n;i++){
			cout<<dist[i]<<" ";
		}
	}
	
	
}
