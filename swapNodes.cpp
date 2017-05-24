#include<bits/stdc++.h>
#include<queue>
using namespace std;
struct Node{
	Node* left;
	Node* right;
	int data;
};
Node* createNode(int data){
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
Node* insert(Node* root, int data){
	Node* newNode = createNode(data);
	return newNode;
}
Node* insertLeft(Node* cur, int data){
	Node* newNode = createNode(data);
	cur->left = newNode;
	return newNode;
}
Node* insertRight(Node* cur, int data){
	Node* newNode = createNode(data);
	cur->right = newNode;
	return newNode;
}
void inOrder(Node* root)
{
	if(root!=NULL){
		inOrder(root->left);
		 
			cout<<root->data<<" ";
		  
		inOrder(root->right);
	}	
}
int depth(Node* root){
	if(root==NULL){
		return 0;
	}else{
		int left = depth(root->left);
		int right = depth(root->right);
		return max(right, left)+1;
	}
}
void changeAt(Node* root, int change, int  height){
	if(root==NULL){
		return;
	}
	if(change==height){
		 
		Node* left = root->left;
		Node* right = root->right;
		root->left = right;
		root->right = left;
		return;
	}else{
		changeAt(root->left, change,height+1);
		changeAt(root->right, change,height+1);
	}
}

int main(){
	int n;
	cin>>n;
	Node* root = NULL;
	root = insert(root, 1);
	queue<Node*> q;
	q.push(root);
	while(n--){
		int lef, rig;
		cin>>lef>>rig;
		Node* curRoot = q.front();
		q.pop();
		if(lef != -1){
			q.push(insertLeft(curRoot, lef));
		}else{
			curRoot->left = NULL;
		}
		if(rig!=-1){
			q.push(insertRight(curRoot, rig));
		}else{
			curRoot->right = NULL;
		}
		 
	}
	int dep = depth(root);
	int x;
	cin>>x;
	 
	while(x--){
		int change;
		cin>>change;
		for(int i=change;i<dep;i+=change){
			changeAt(root,i,1);
		}
		inOrder(root);
	}
	
	
	
}
