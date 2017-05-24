#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ipair;
struct Node{
	int v;
	int w;
	Node* next;
};
Node* createNode( int v, int w){
	Node* newNode = new Node();
	newNode->next = NULL;
	newNode->v = v;
	newNode->w = w;
	return newNode;
}
void insertNode(int u,int v, int w, Node* a[]){
	Node* newNode = createNode(v,w);
	newNode->next = a[u];
	a[u] = newNode;
	newNode = createNode(u,w);
	newNode->next = a[v];
	a[v] = newNode;	
}
void printGraph(int nodes, Node* a[]){
	for(int i=0;i<nodes;i++){
		Node* head = a[i];
		cout<<"Nodes connecting "<<i<<"are: ";
		while(head!=NULL){
			cout<<head->v<<" ";
			head = head->next;
		}
		cout<<endl;
	}
}
void depthFirst(Node* a[], int u, int visit[]){
	visit[u] = -1;
	cout<<u<<" ";
	Node* head = a[u];
	while(head !=NULL){
		int cur = head->v;
		if(visit[cur]!=-1){
			depthFirst(a,cur,visit);
		}
		head = head->next;
	}
}
void depthFirstStack(int u, Node* a[], int visit[], int n){
	stack<int> s;
	for(int i=0;i<n;i++){
		visit[i] = 0;
	}
	s.push(u);
	 
	while(!s.empty()){	
		int cur = s.top();
		s.pop();
		if(visit[cur]!=-1){
			cout<<cur<<" ";
			visit[cur] = -1;
			Node* head = a[cur];
			while(head!=NULL){
				int curV = head->v;
				if(visit[curV]==0){
					s.push(head->v);
				}
				head = head->next;
			}
		}
		
	}
	
}
void breadthFirst(int u, Node* a[], int visit[]){
	queue<int> q;
	visit[u] = -1;
	cout<<u<<" ";
	q.push(u);
	while(!q.empty()){
		Node* head = a[q.front()];
		q.pop();
		while(head!=NULL){
			int val = head->v;
			if(visit[val]!=-1){
				cout<<val<<" ";
				visit[val] = -1;
				q.push(val);
			}
			head = head->next;
		}
	}
}
void doingNewly(Node* a[], int u, int n){
	queue<int> q;
	int* dist  = new int[n];
	for(int i=0;i<n;i++){
		dist[i] = INT_MAX;
	}
	q.push(u);
	dist[u] = 0;
	while(!q.empty()){
		int mainU = q.front();
		q.pop();
		Node* head = a[mainU];
		while(head!=NULL){
			int curU = head->v;
			int curW = head->w;
			if(dist[curU]>dist[mainU]+curW){
				dist[curU] = dist[mainU]+curW;
				q.push(curU);
			}
			head = head->next;
		}
	}
	for(int i=0;i<n;i++){
		cout<<dist[i]<<" ";
	}
	
	
	
}
 
void dijstra(Node* a[], int u, int n){
	int dist[n];
	int visit[n];
	for(int i=0;i<n;i++){
		visit[i] = 0;
		dist[i] = INT_MAX;
	}
	dist[u] = 0;
	priority_queue<ipair, vector<ipair>, greater<ipair> > pq;
	pq.push(make_pair(dist[u], u)); 
	while(!pq.empty()){
		int node = pq.top().second;
		Node* head = a[node];
		pq.pop();
		visit[node] = -1;
		while(head!=NULL){
			int curNode = head->v; 
			if(visit[head->v]!=-1&&dist[curNode]>dist[node]+head->w){
				dist[curNode] = dist[node]+head->w;
				pq.push(make_pair(dist[curNode], curNode));
			}
			head = head->next;
		}
		
	}
	cout<<"Oh!! Fuck Dijstra Calculated something..."<<endl;
	for(int i=0;i<n;i++){
		cout<<dist[i]<<" ";
	}
	 
}
int main(){
	/*
	7
9
0 1 2
1 4 6
4 2 3
2 0 4
0 3 6
4 3 5
3 5 7
3 6 9
6 5 8
	*/
	
	
	
	int nod,edg;
	cin>>nod>>edg;
	Node* a[nod];
	for(int i=0;i<nod;i++){
		a[i] = NULL;
	}
	for(int i=0;i<edg;i++){
		int u,v,w;
		cin>>u>>v>>w;
		insertNode(u,v,w,a);
	}
	printGraph(nod, a);
	cout<<endl<<endl;
	int visit[nod];
	for(int i=0;i<nod;i++)
	visit[i] = 0;
	cout<<"From Where you want to start your ripping off";
	int ripStart;
	cin>>ripStart;
	depthFirst(a,ripStart,visit);
	for(int i=0;i<nod;i++){
		visit[i] = 0;
	}
	cout<<endl;
	
	breadthFirst(ripStart,a,visit);
	
	dijstra(a,ripStart,nod);
	cout<<endl;
	cout<<"Tring some thing fucking new";
	cout<<endl;
	doingNewly(a,ripStart,nod);
	cout<<endl;
	depthFirstStack(ripStart, a, visit, nod);
}
