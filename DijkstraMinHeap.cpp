#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ipair;
struct Node{
	int v;
	int w;
	Node* next;
};
Node* makeNode(int v, int w){
	Node* newNode = new Node();
	newNode->next = NULL;
	newNode->v = v;
	newNode->w = w;
	return newNode;
}
void insertNode(int u, int v, int w, Node* a[]){
	Node* newNode = makeNode(v,w);
	newNode->next = a[u]; 
	a[u] = newNode;
	
	Node* newNode2 = makeNode(u,w);
	newNode2->next = a[v];
	a[v] = newNode2;
}
void printNodes(int n, Node* a[]){
	for(int i=0;i<n;i++){
		cout<<"Node "<<i<<": ";
		Node* head = a[i];
		while(head!=NULL){
			cout<<i<<"->"<<head->v<<"("<<head->w<<")"<<endl;
			head = head->next;
		}
		cout<<endl;
	}
}
int* dijstra(Node* a[], int u, int n){
	int* dist = new int[n];
	priority_queue< ipair, vector<ipair>, greater<ipair> > q;
	for(int i=0;i<n;i++){
		dist[i] = INT_MAX;
		q.push(make_pair(INT_MAX, i ));		
	}
	q.push(make_pair(0,u));
	dist[u] = 0;
	while(!q.empty()){
		int cur = q.top().second;
		q.pop();
		Node* head = a[cur];
		while(head != NULL){
			int curVal = head->v;
			int curW = head->w;
			if(dist[curVal]>dist[cur]+curW){
				dist[curVal] = dist[cur]+curW;
				q.push(make_pair(dist[curVal] , curVal ));
			}
			head = head->next;
		}
	}
	return dist;
	
}
void bFirst(Node* a[], int n, int visit[], int u){
	visit[u] = 1;
	cout<<u<<" ";
	queue<int> q;
	q.push(u);
	while(!q.empty()){
		int node =  q.front();
		q.pop();
		Node* head = a[node];
		while(head!=NULL){
			if(visit[head->v]!=1){
				visit[head->v] = 1;
				cout<<head->v<<" ";
				q.push(head->v);
			}
			head = head->next;
		}
	}
}
void depthFirst(Node* a[], int n, int visit[], int u){
	visit[u] = 1;
	cout<<u<<" ";
	Node* head = a[u];
	while(head!=NULL){
		if(visit[head->v]!=1){
			depthFirst(a,n,visit,head->v);
		}
		head = head->next;
	}
}
void primMST(Node* a[], int u, int n){
	vector<int> parent(n, -1);
	vector<bool> inthe(n, false);
	vector<int> dist(n, 1000000);
	priority_queue<ipair, vector<ipair>, greater<ipair> > pq;
	pq.push(make_pair(0, u));
	parent[u] = 0;
	dist[u] = 0;
	inthe[u] = 0;
	while(!pq.empty()){
		int node = pq.top().second;
		int weig = pq.top().first;
		pq.pop();
		Node* head = a[node];
		while(head!=NULL){
			int v,w;
			v = head->v;
			w = head->w;
			if(inthe[v]==false &&dist[v]>dist[node]+w){
				dist[v] = dist[node]+w;
				pq.push(make_pair(dist[v], v));
				parent[v] = node;
			}
			head = head->next;
		}
		
		
		
	}
	for(int i=1;i<n;i++){
		cout<<i<<" "<<parent[i]<<endl;;
	}
	 
}

int main(){
	int n;
	cout<<"Enter the number of nodes in the graph: ";
	cin>>n;
	cout<<"Enter the number of edges: ";
	int m;
	cin>>m;
	Node* a[n];
	for(int i=0;i<n;i++){
		a[i] = NULL;
	}
	cout<<"enter Nodes";
	for(int i=0;i<m;i++){
		int u,v,w;
		cout<<"Enter [u, v, w]";
		cin>>u>>v>>w;
		insertNode(u,v,w,a);
	}
	cout<<endl<<"Printing Nodes....";
	printNodes(n,a);
	int* temp = dijstra(a,0,n);
	for(int i=0;i<n;i++){
		cout<<temp[i]<<" ";
	}
	primMST(a,0,n);
}
