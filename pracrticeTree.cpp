#include<iostream>
#include<queue>
using namespace std;
struct Node{
	Node* l;
	Node* r;
	Node* p;
	int data;
};
Node* createNode(int data){
	Node* node = new Node();
	node->data = data;
	node->l = NULL;
	node->r = NULL;
	return node;
}
void inOrder(Node* root){
	if(root==NULL)
		return;
	inOrder(root->l);
	cout<<root->data<<" ";
	inOrder(root->r);
}
Node* insertNode(Node* root, int data){
	Node* newNode = createNode(data);
	if(root==NULL){
		newNode->p = NULL;
		return newNode;
	} 
	Node* temp = root;
	Node* par = NULL;
	while(temp!=NULL){
		par = temp;
		if(temp->data>data){
			temp = temp->l;
		}else{
			temp = temp->r;
		}
	}
	if(par->data>data){
		par->l = newNode;
	}else{
		par->r = newNode;
	}
	newNode->p = par;
	return root;
	
	
}
void levelOrder(Node* root){
	queue<Node*> q;
	Node* start = root;
	q.push(root);
 
	while(!q.empty()){
		
		Node* temp = q.front();
		q.pop();
		cout<<temp->data<<" ";
		
		if(temp->l!=NULL){
			q.push(temp->l);
		}if(temp->r!=NULL){
			q.push(temp->r);
		}
	 
	}
}
void inOrderLine(Node* root){
	 cout<<"In Order Traversal"<<endl;
	queue<Node*> q;
	q.push(root);
	int cur = q.size();
	while(!q.empty()){
		Node* temp = q.front();
		q.pop();
		cur--;
		
		
		cout<<temp->data<<" ";
		if(temp->l!=NULL)
			q.push(temp->l);
		if(temp->r!=NULL)
			q.push(temp->r);
		if(cur==0){
			cout<<endl;
			cur = q.size();
		}	
	}
}
int leaves(Node* root){
	
	if(root->l==NULL&&root->r==NULL){
		return 1;
	}else{
		int left=0,right=0;
		if(root->l!=NULL){
			left = leaves(root->l);
		}
		if(root->r!=NULL){
			right = leaves(root->r);
		}
		return left+right;
	}
}
int main(){
	while(true){
	cout<<"How Many Elements do you want me to enter:>? ";
	int n;
	cin>>n;
	Node* root = NULL;
	while(n--){
		int x;
		cin>>x;
		root = insertNode(root, x);
	}
	inOrder(root);
	cout<<endl;
	levelOrder(root);
	inOrderLine(root);
	cout<<leaves(root);
	
	}
}
