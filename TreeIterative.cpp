#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* left;
	Node* right;
};

Node* root = NULL;;
void insertNode(int data){
	Node* newNode = new Node();
	newNode->right = NULL;
	newNode->left = NULL;
	newNode->data = data;
	if(root==NULL){
		root = newNode;
		return;
	}
	Node* save = root;
	Node* temp = root;
	while(temp!=NULL){
		if(temp->data>data){
			save = temp;
			temp = temp->left;
		}else{
			save = temp;
			temp = temp->right;
		}
	}
	if(save->right==NULL){
		save->right = newNode;
	}else{
		save->left = newNode;
	}
}
void inOrder(Node* temp){
	if(temp==NULL){
		return;
	}
	inOrder(temp->left);
	cout<<temp->data<<" ";
	inOrder(temp->right);
}
int main(){
	
	insertNode(12);
	cout<<"Inserted";
	insertNode(22);
	cout<<"Inserted";
	insertNode(24);
	cout<<"Inserted";
	insertNode(278);
	inOrder(root);
}
