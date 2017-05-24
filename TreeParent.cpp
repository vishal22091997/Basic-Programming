#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* left;
	
	Node* right;
	
	Node* parent;
};
Node* createNode(int data, Node* parent){
	Node* newNode = new Node();
	newNode->data = data;
	newNode->parent = parent;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
Node* insertNode(int data, Node* root, Node* parent){
	if(root==NULL){
		Node* newNode = createNode(data, parent);
		return newNode;
	}else if(root->data>data){
		root->left = insertNode(data,root->left, root);
		return root;
	}else{
		root->right = insertNode(data, root->right, root);
		return root;
	}
}
void inOrder(Node* root){
	if(root!=NULL){
		inOrder(root->left);
		cout<<root->data<<" ";
		if(root->parent!=NULL){
			cout<<root->parent->data;
		}
		cout<<endl;
		inOrder(root->right);
	}
}
Node* find(int data, Node* root){
	if(root->data == data){
		return root;
	}else if(root->data>data){
		return find(data, root->left);
	}else{
		return find(data, root->right);
	}
}
Node* maxElement(Node* root){
	if(root->right==NULL){
		return root;
	}else{
		return maxElement(root->right);
	}
}
Node* minElement(Node* root){
	if(root->left==NULL){
		return root;
	}else{
		return minElement(root->left);
	}
}



void pred(Node* root, int data){
	Node* cur = find(data, root);
	if(cur==NULL){
		cout<<"No Point Present: "<<data;
		return;
	}
	if(cur->left!=NULL){
		Node* pred = maxElement(cur->left);
		cout<<pred->data<<endl;
	}else{
		Node* y = cur->parent;
		while(y!=NULL&&y->left!=NULL&&y->left->data==cur->data){
			cur = y;
			y = y->parent;
		}
		if(y!=NULL){
			cout<<y->data<<endl;
		}else {
			cout<<"Not found"<<endl;
		}
	}	
}
void succ(Node* root, int data){
	Node* cur = find(data, root);
	cout<<"Found";
	if(cur==NULL){
		cout<<"This data is not present";
		return;
	}else if(cur->right!=NULL){
		cout<<"Entered";
		Node* pred = minElement(cur->right);
		cout<<pred->data;
	}else{
		Node* y = cur->parent;
		while(y!=NULL&&y->right!=NULL&&y->right->data==cur->data){
			cur = y;
			y = y->parent;
		}
		if(y!=NULL){
			cout<<y->data;
		}else{
			cout<<"Not Present";
		}
	}
}
void secondMax(Node* root){
	Node* max = maxElement(root);
	cout<<"Secoond Maximum Element in the BST: ";
	pred(root, max->data);
}
Node* deleteNode(int data, Node* root){
	if(root==NULL)
		return root;
	else if(root->data>data){
		root->left = deleteNode(data, root->left);
	}else if(root->data<data){
		root->right = deleteNode(data, root->right);
	}else{
		//finded the root element of the tree
		if(root->left==NULL&&root->right==NULL){
			//means there is no child of the cur node to be deleted so we just have to delete the current nod
			delete root;
			return NULL;
		}		
		else if(root->left!=NULL){
			Node* temp = root->left;
			delete root;
			return temp;
		}else if(root->right!=NULL){
			Node* temp = root->right;
			delete root;
			return temp;
		}else{
			Node* max = maxElement(root->left);
			root->data = max->data;
			return deleteNode(root->data, root->left);	
		}
		
	}
}
int countBSTNodes(Node* root,int a, int b){
	if(root->data>=a&&root->data<=b){
		int left = 0, right = 0; 
		if(root->left!=NULL)
			left = countBSTNodes(root->left,a,b);
		if(root->right!=NULL)
			right = countBSTNodes(root->right,a,b);
		return left+right+1;
	}else if(root->data>b&&root->left!=NULL){
		return countBSTNodes(root->left, a,b);
	}else if(root->data<a&&root->right!=NULL){
		return countBSTNodes(root->right,a,b);
	}else{
		return 0;
	}
	
}
int countBSTSubtree(Node* root, int a, int b){
	if(root==NULL){
		return 0;
	}else if(root->data>=a&&root->data<=b){
		int left = countBSTNodes(root->left,a,b);
		int right = countBSTNodes(root->right, a,b);
		
	}
}
int main(){
	Node* root =NULL;
	Node* parent = NULL;
	cout<<"How Many? ";
	int n;
	cin>>n;
	while(n--){
		int x;
		cin>>x;
		root = insertNode(x,root,parent);
	}
	inOrder(root);
	/*while(true){
		int data;
		cin>>data;
		pred(root, data);
		succ(root, data);
	}
	*/
	/*
	secondMax(root);
	cout<<"Enter old Key";
	int old;
	cin>>old;
	int newKey;
	cin>>newKey;
	deleteNode(old, root);
	cout<<"After Deleting...";
	inOrder(root);
	root = insertNode(newKey, root, parent);
	cout<<"After inserting the new Nodes";
	inOrder(root);
	*/
	int a,b;
	cin>>a>>b;
	cout<<countBSTNodes(root, a, b);
	
}
