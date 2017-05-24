#include<iostream>
#include<queue>
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
void depthSearch(uNode* a[], int visit[], int x){
	cout<<x<<endl;
	visit[x] = 1;
	uNode* cur = a[x];
	while(cur!=NULL){
		if(visit[cur->vNode]!=1){
			depthSearch(a,visit,cur->vNode);
		}
		cur = cur->next;
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
/*


5
7
0 1 2 
0 3 2
1 3 2
1 2 5
1 4 8
2 3 5
3 4 9





*/
int* breadth(int u, uNode* a[],int visit[], int n){
	visit[u] = 1;
	queue<int> q;
	int *distances = new int[n];
	distances[u] = 0;
	q.push(u);
	while(!q.empty()){
		int curNode = q.front();
		uNode* cur = a[curNode];
		int myDist = distances[curNode];
		
		q.pop();
		while(cur!=NULL){
			if(visit[cur->vNode]==0){
				distances[cur->vNode] = myDist+1;
				visit[cur->vNode] = 1;
				q.push(cur->vNode);	
			}
			cur = cur->next;
		}
	}
	return distances;
	
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
	int count = 5;
	/*
	
	while(count--){
		cout<<"Depth First Search of which element : "<<endl;
		int x;
		cin>>x;
		for(int i=0;i<n;i++){
			visit[i] = 0;
		}
		if(x<n&&x>=0)
			depthFirst(a,x,visit);
		else
			cout<<"Invalid x"<<endl;
	}
	*/
	///now coming to breadth first search
	count = 5;
	cout<<"Now Time for the breadth first search";
	while(count--){
		cout<<"Breadth First Search of which element : "<<endl;
		int x;
		cin>>x;
		for(int i=0;i<n;i++){
			visit[i] = 0;
		}
		int *distances;
		if(x<n&&x>=0)
			distances =  breadth(x,a,visit,n);
		else
			cout<<"Invalid x"<<endl;
			
		 cout<<"Printing";
		for(int i=0;i<n;i++){
			cout<<distances[i]<<" ";
		}
			
			
	}
	
	
	
	
}
