#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* left;
	Node* right;
};
Node* head = NULL;
Node* createNode(int data){
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
void insertNode(int data){
	Node* newNode = createNode(data);
	if(head == NULL){
		head = newNode;
		return;
	}
	Node* temp = head;
	while(temp->right!=NULL){
		temp = temp->right;
	}
	temp->right = newNode;
	newNode->left = temp;	
}
void printNodes(){
	Node* temp = head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp = temp->right;
	}
	cout<<endl;
}
void deleteNode(int x){
	Node* temp = head;
	while(temp!=NULL&&temp->data!=x){
		temp = temp->right;
	}
	if(temp == NULL){
		cout<<"Element doesn't Exists..."<<endl;;
	}else{
		if(temp->left==NULL){
			head = head->right;
			(temp->right)->left = NULL;
		}
		else if(temp->right==NULL){
			(temp->left)->right = NULL;
		}
		else{
			(temp->left)->right = temp->right;
			(temp->right)->left = temp->left;
		}
		delete temp;
		return;
		
	}
}
int main(){
	int n;
	cin>>n;
	while(n--){
		int x;
		cin>>x;
		insertNode(x);
	}
	printNodes();
	cout<<endl<<endl;
	cout<<"Enter the node you want to delete: ";
	int x;
	cin>>x;
	deleteNode(x);
	cout<<"The List Of the nodes after Deletion are: "<<endl;;
	printNodes();
	
}
