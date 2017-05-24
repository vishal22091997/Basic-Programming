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
Node* insert(Node* temp, int data){
	if(temp==NULL){
		Node* newNode = createNode(data);
		return newNode;
		
	} if(temp->data >= data){
		temp->left = insert(temp->left, data);
		
	}else if(temp->data < data){
		temp->right = insert(temp->right, data);
		
	}
	return temp;
}
bool search(Node* root,int data){
	if(root==NULL){
		return false;
	}else{
		if(root->data>data){
			return search(root->left, data);
		}else if(root->data<data){
			return search(root->right, data);
		}else{
			return true;
		}
	}
}
 
int height(Node* root){
	if(root==NULL){
		return 0;
	}else {
		int left = height(root->left);
		int right = height(root->right);
		return max(left, right)+1;
	}
}
int main(){
	int g;
	cin>>g;
	while(g--){
		int n, m;
		cin>>n>>m;
		Node* root = NULL;
		int count = 0;
		for(int i=0;i<n;i++){
			int val ;
			cin>>val;
			root =  insert(root, val); 		
		}
		for(int i=0;i<m;i++){
			int val ;
			cin>>val;
			if(search(root, val)){
				cout<<"YES"<<endl;
					
			}else{
				cout<<"NO"<<endl;
			}
			 
		}
	 
		
	}
}
