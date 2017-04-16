#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* left;
	Node* right;
};
struct lNode{
	int data;
	lNode* small;
	lNode* large;
};
lNode* createlNode(int data){
	lNode* lnode = new lNode();
	lnode->data = data;
	lnode->large = NULL;
	lnode->small = NULL;
	return lnode;
}
Node* createNode(int data){
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
Node* insert(Node* root, int data){
	if(root==NULL){
		Node* newNode = createNode(data);
		return newNode;
	}
	if(root->data>data){
		root->left = insert(root->left, data);
		return root;
	}else{
		root->right = insert(root->right, data);
		return root;
	}
}
void inOrder(Node* root){
	if(root==NULL)
		return ;
	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}
int sizeOfTree(Node* root){
	if(root->left==NULL&&root->right==NULL){
		return 1;
		//one if the root node is the leaf node
	}else{
		int lCount = 0;
		int rCount = 0;
		if(root->left!=NULL){
			lCount = sizeOfTree(root->left);
		}
		if(root->right!=NULL){
			rCount = sizeOfTree(root->right);
		}
		 
		return lCount+rCount+1;
		// here one is added because of the centeral node say which is calling left and 
		//right node so the output will be sum of lCount i.e the left subtree count //and
		//right subtree count but still we need to add the count of the node from where it 
		// was being called
		
		
	}
}
 
bool check(Node* root1, Node* root2){
	
	if(root1==NULL&&root2==NULL){
		return true;
	}else if(root1==NULL){
		return false;
	}else if(root2==NULL){
		return false;
	}else if(root1->data==root2->data){
		
		bool lcheck = false, rcheck = false;
	 
		 lcheck = check(root1->left, root2->left);
		 rcheck = check(root1->right, root2->right);
		 
	 
		
		return lcheck&rcheck;
	}
	else{
		return false;
	}
}
int height(Node* root){
	if(root==NULL){
		return 0;
	}
	int lheight = height(root->left);
	int rheight = height(root->right);
	return max(lheight, rheight)+1;
}
void convertMirror(Node* root){
	if(root ==NULL){
		return;
	}
	Node* temp = root->left;
	root->left = root->right;
	root->right = temp;
	convertMirror(root->left);
	convertMirror(root->right);
}
int leaves(Node* root){
	if(root==NULL){
		return 0;
	}
	else if(root->left==NULL&&root->right==NULL){
		return 1;
	}
	else{
		int lCount = leaves(root->left);
		int rCount = leaves(root->right);
		return lCount + rCount;
	}
}
lNode* convertToLL(Node* root){
	//method not completed yet
 
}
int minOfTree(Node* root){
	if(root->left==NULL){
		return root->data;
	}else{
		return minOfTree(root->left);
	}
}
int maxOfTree(Node* root){
	if(root->right==NULL){
		return root->data;
	}else{
		return maxOfTree(root->right);
	}
}
int searchIterative(int x,Node* root){
	while( root!=NULL){
		if(root->data>x){
			root = root->left;
		}else if(root->data<x){
			root = root->right;
		}else{
			return 1;
		}
	}
	return 0;
}
int nodeLeftSum(Node* root){
	if(root==NULL){
		return 0;
	}else{
		root->data = root->data+nodeLeftSum(root->left);
		if(root->right!=NULL){
			root->right->data +=  nodeLeftSum(root->right);
		}
	}
}
int main(){
	while(true){
	Node* root = NULL;
	cout<<"Enter the number of elements to be entered in the tree";
	int n;
	cin>>n;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			root = insert(root, x);
		}
		inOrder(root);
		cout<<sizeOfTree(root);
		/*cout<<"Enter other tree to check if both tree are identical";
		cout<<"Enter "<<n<<" Elements ";
		Node* root2 = NULL;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			root2 = insert(root2, x);
		}
		inOrder(root2);
		if(check(root, root2)){
			cout<<"Both Trees are equal";
		}else{
			cout<<"Shit! Not Equal";
		}*/
		cout<<"Calculating the height of trees...."<<endl;
		cout<<height(root)-1<<endl;
		cout<<"Now Converting the tree to its mirror...";
		//convertMirror(root);
		inOrder(root);
		cout<<endl;
		cout<<"Leaf Nodes in binary tree...";
		cout<<leaves(root);
		cout<<endl;
		cout<<minOfTree(root);
		cout<<endl;
		cout<<"Searching Iteratively for an element X, enter X: ";
		int x;
		cin>>x;
		cout<<searchIterative(x,root);
		
		
		
		
	}

	
}
