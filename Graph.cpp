#include<iostream>
using namespace std;
struct uNode{
	int vNode;
	int w;
	uNode* next;
};
uNode* createNode(int v, int w){
	uNode* node = new uNode();
	node->next = NULL;
	node->vNode = v;
	node->w = w;
	return node;
}
void addNode(uNode* a[], int u, int v, int w){
	uNode* newNode = createNode(v,w);
	uNode* newNode2 = createNode(u,w);
	newNode2->next = a[v];
	a[v] = newNode2;
	
	
	newNode->next = a[u];
	a[u] = newNode;
}
void print(uNode* a[], int n){
	for(int i=0;i<n;i++){
		uNode* cur = a[i];
		cout<<"Printing the nodes connected to "<<i<<" Node...."<<endl;
		while(cur!=NULL){
			cout<<"entered"<<endl;
			cout<<i <<" is connected to " <<cur->vNode<<" has weight "<<cur->w<<endl;
			cur = cur->next;
		}
	}
}
void depthFirst(uNode* a[],int x, int visit[]){
	 
		cout<<x<<" ";
	 
	visit[x] = 1;
	uNode* cur = a[x];
	while(cur!=NULL){
		if(visit[cur->vNode]!=1){
			depthFirst(a,cur->vNode, visit);
		}
		cur = cur->next;
	}
		
}

int main(){
	cout<<"How Many vertices in the graph: ";
	int n;
	cin>>n;
	uNode* a[n];
	for(int i=0;i<n;i++){
		a[i] = NULL;
	}
	int edges;
	cout<<"Enter the number of edges: ";
	cin>>edges;
	for(int i=0;i<edges;i++){
		int u,v,w;
		cout<<"Enter u v w: ";
		cin>>u>>v>>w;
		addNode(a,u,v,w);
	}
	
	print(a,n);
	int* visit = new int[n];
	for(int i=0;i<n;i++){
		visit[i] = 0;
	}
	depthFirst(a,0,visit);
	
	
	
	
}
