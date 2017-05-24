#include<iostream>
#include<climits>
using namespace std;
struct Node{
	int v;
	Node* next;
};
Node* createNode(int v){
	Node* newNode = new Node();
	newNode->v = v;
	newNode->next = NULL;
	return newNode;
}
void addNode(Node* a[], int u, int v){
	Node* newNode = createNode(v);
	Node* newNode2 = createNode(u);
	newNode2->next = a[v];
	a[v] = newNode2;
	newNode->next = a[u];
	a[u] = newNode;
}
int dfs(int visit[], int x,Node* a[], int g, int val){
	visit[x] = 1;	
	Node* cur = a[x];
	if(x==g){
		return val-1;
	}
	while(cur!=NULL){
		val = 0;
		if(visit[cur->v]==0){
			return dfs(visit, cur->v, a,g,val);
		}
		cur = cur->next;
	}
}
int main(){
	int ver, edg;
	cin>>ver;
	edg = ver-1;
	int *visit = new int[ver];
	for(int i=0;i<ver;i++){
		visit[i] = 0;
	}
	Node* a[ver];
	for(int i=0;i<ver;i++){
		a[i] = NULL;
	}
	for(int i=0;i<edg;i++){
		int u,v;
		cin>>u>>v;
		addNode(a, u-1, v-1);
	}
	int x;
	cin>>x;
	int minVal = INT_MAX, index = INT_MAX;
	for(int i=0;i<x;i++){
		int g;
		cin>>g;
		g--;
		cout<<dfs(visit,g-1,a,0,0);
	}
	
	
}	
