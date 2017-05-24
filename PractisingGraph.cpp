#include<iostream>
#include<queue>
using namespace std;
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
void findCycle(Node* a[], int visit[], int u){
	visit[u]++;
	if(visit[u]>2){
		return false;
	}
	Node* head = a[u];
	while(head != NULL){
		if(visit[u]<2){
			visit[u]++;
			findCycle(a,visit,head->v);
		}
		head = head->next;
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
	
	int visit[n];
	for(int i=0;i<n;i++){
		visit[i] = 0;
	}
	int u;
	cout<<"Enter the node for starting point of depthFirst Search: ";
	cin>>u;
	depthFirst(a,n,visit,u);
	cout<<"Enter the node for the starting point of Breadth First Search: ";
	int breadthStart;
	cin>>breadthStart;
	for(int i=0;i<n;i++)	visit[i] = 0;
	bFirst(a,n,visit,u);
	
}
