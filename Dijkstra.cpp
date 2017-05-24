#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* left;
	Node* right;
};
Node* createNode(int data){
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
Node* insertNode(int data, Node* root){
	if(root==NULL){
		Node* newNode = createNode(data);
		return newNode;
	}
	if(root->data>data){
		root->left = insertNode(data, root->left);
	}else if(root->data<data){
		root->right = insertNode(data, root->right);
	}
	return root;
}
void inOrder(Node* root){
	if(root!=NULL){
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}
}
void preOrder(Node* root){
	if(root!=NULL){
		cout<<root->data<<" ";
		preOrder(root->left);
		preOrder(root->right);
	}
}
Node* findVal(int data, Node* root, Node* &parent){
	while(root!=NULL){
		if(root->data>data){
			parent = root;
			root = root->left;
		}else if(root->data<data){
			parent = root;
			root = root->right;
		}else{
			return root;
		}
	}
}
/*
void deleteNode(Node* root, int data){
	if(root==NULL){
		return root;
	}
	else if(root->data>data){
		root->left = deleteNode(root->left, data);
	}else if(root->data<data){
		root->right = deleteNode(root->right, data);
	}else{
		if(root->left==NULL && root->right==NULL){
			delete root;
			return NULL;
		}else if(root->left!=NULL){
			
		}
		
		
		
		
		
		
		
		
		
	}
	
	
	
	
}
*/


int lca(Node* root, int v1, int v2){
	if(root->data>v1&&root->data>v2){
		return lca(root->left, v1, v2);
	}else if(root->data<v1&&root->data<v2){
		return lca(root->right, v1,v2);
	}else if(root->data>=min(v1,v2)&&root->data<=max(v1,v2)){
		return root->data;
	}
}


int main(){
	cout<<"Enter the number of noder to be there in the tree: ";
	int n;
	cin>>n;
	Node* root = NULL;
	while(n--){
		int x;
		cin>>x;
		root = insertNode(x,root);
	}
	cout<<"In Order"<<endl;
	inOrder(root);
	cout<<endl;
	cout<<"Post Order"<<endl;
	preOrder(root);
	cout<<"Enter a and b for which we want to find lca ";
	int a,b;
	cin>>a>>b;
	cout<<lca(root,a,b);
}
