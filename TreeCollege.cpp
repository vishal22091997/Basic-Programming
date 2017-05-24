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
Node* insertNode(Node* root, int data){
	if(root==NULL){
		return createNode(data);
	}
	if(root->data>data){
		root->left = insertNode(root->left, data);
		return root;
	}else if(root->data<data){
		root->right = insertNode(root->right, data);
		return root;
	}
}
void inOrder(Node* root){
	if(root!=NULL){
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}
}
Node* deleteNodes(Node* root){
	if(root!=NULL){
		if(root->left!=NULL)
			root->left = deleteNodes(root->left);
		if(root->right!=NULL)
			root->right = deleteNodes(root->right);
		Node* temp = root;
		delete temp;
		return NULL;
	}
}
 
int giveHeight(Node* root){
	if(root==NULL){
		return 0;
	}else{
		int left = giveHeight(root->left);
		int right = giveHeight(root->right);
		return max(left, right)+1;
	}
}
int main(){
	cout<<"How Many Nodes?: ";
	int n;
	cin>>n;
	Node* root = NULL;
	while(n--){
		int x;
		cin>>x;
		root = insertNode(root, x);
	}
	inOrder(root);
	/*
	root = deleteNodes(root);
	cout<<endl<<"Deleting Elements from the Fucking Tree..."<<endl<<"Showing the elements of the Tree..."<<endl;
	inOrder(root);
	*/
	//checking the height of the tree
	int height = giveHeight(root);	
	cout<<height-1<<endl;
	
	
	
	
}
