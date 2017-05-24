#include<iostream>
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
void dfs(int visit[], int x,Node* a[]){
	visit[x] = 1;
	 
	Node* cur = a[x];
	while(cur!=NULL){
		if(visit[cur->v]==0){
			dfs(visit, cur->v, a);
		}
		cur = cur->next;
	}
}
int main(){
	int ver, edg;
	cin>>ver>>edg;
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
	dfs(visit,x-1,a);
	int sol = 0;
	for(int i=0;i<ver;i++){
		if(visit[i]==0){
			sol++;
		}
	}
	cout<<sol<<endl;
	
	
}
