#include<iostream>
#include<cmath>

using namespace std;
struct Node{
	int data;
	Node* left;
	Node* right;
};
struct qNode{
	Node* data;
	qNode* next;
};
qNode* front = NULL;
qNode* rear = NULL;
qNode* makeNode(Node* data){
	qNode* newNode = new qNode();
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
void enqueue(Node* data){
	qNode* newNode = makeNode(data);
	if(rear==NULL){
		rear = front = newNode;
		return;
	}
	rear->next = newNode;
	rear = newNode;
}
Node* dequeue(){
	Node* sol;
	if(front==NULL){
		return NULL;
	}
	sol = front->data;
	if(front==rear){
		front = rear = NULL;
		return sol;
	}
	front = front->next;
	return sol;	
}
bool isEmpty(){
	if(front==NULL){
		return false;
	}
}

Node* createNode(int data){
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

Node* insert(Node* temp, int data){
	if(temp == NULL){
		temp = createNode(data);	
	} if(temp->data>data){
		temp->left = insert(temp->left, data);
	}else{
		temp->right = insert(temp->right, data);
	}
	return temp;
}
void printTree(Node* root){
	if(root!=NULL){
		printTree(root->left);
		cout<<root->data<<" ";
		printTree(root->right);
	}
}
bool searchTree(int data, Node* root){
	if(root!=NULL){
		cout<<root->data<<" ";
		if(root->data>data){
			searchTree(data, root->left);
		}else if(root->data<data){
			searchTree(data, root->right);
		}else{
			return true;
		}
		
	}else{
		return false;
	}
}
void kSmall(Node* root,  int v1, int v2){
	if(root!=NULL){
		kSmall(root->left, v1, v2);
		int val = root->data;
		if(val>=v1&&val<=v2){
			cout<<val<<" ";
		}
		kSmall(root->right, v1, v2);
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
int height(Node* root){
	if(root==NULL){
		return 0;
	}else {
		int lh = height(root->left);
		int rh = height(root->right);
		return max(lh,rh)+1;	
	}
}
void levelOrder(Node* root){
	if(root==NULL){
		return;
	}else{
		if(root->left!=NULL)
			enqueue(root->left);
		if(root->right!=NULL)
			enqueue(root->right);
		cout<<root->data<<" ";
		levelOrder(dequeue());
	}
}
void inOrder(Node* root){
	if(root==NULL)
		return;
	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}
void preOrder(Node* root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}
void postOrder(Node* root){
	if(root==NULL)
		return;
	preOrder(root->left);
	preOrder(root->right);
	cout<<root->data<<" ";
}
bool check(Node* root){
	if(root!=NULL){
		if(root->left!=NULL&&root->left->data>=root->data){
			cout<<"Not a Binary Search Tree";
			return false;;
		}
		if(root->right!=NULL&&root->right->data<=root->data){
			cout<<"Not a Binary Search Tree";
			return false;
		}
		
		return check(root->left);
		return check(root->right);
	}
}
void predSuc(Node* root, int key, Node* &pre, Node* &suc){
	if(root==NULL){
		return;
	}
	if(root->data==key){
		if(root->left!=NULL){
			pre = maxElement(root->left);
		}
		if(root->right!=NULL){
			suc = minElement(root->right);
		}
		return;
	}
	if(root->data>key){
		suc = root;
		predSuc(root->left,key, pre,suc);
	}else{
		pre = root;
		predSuc(root->right,key,pre,suc);
	}
	
	
	
}
bool remainCheck(Node* root, int remain){
	if(root==NULL){
		return false;
	}else{
		if(root->data>remain){
			return remainCheck(root->left, remain);
		}else if(root->data<remain){
			return remainCheck(root->right, remain);
		}else{
			return true;
		}
	}
}

void searchPair(int val, Node* root){
	if(root==NULL){
		return;
	}else if(root->data>val){
		searchPair(val, root->left);
	}else if(root->data<val){
		int remain = val-root->data;
		int myVal = root->data;
		if(remain>myVal){
			if(remainCheck(root->right, val)){
				cout<<myVal<<" "<<remain;
				return;
			}
		}else{
			if(remainCheck(root->left, val)){
				cout<<myVal<<" "<<remain;
				return;
			}
		}
		searchPair(val, root->left);
		searchPair(val, root->right);
		
		 
	}
	 
}



int main(){
	Node* root = NULL;
	int num ;
	cin>>num;
	for(int i=0;i<num;i++){
		int x;
		cin>>x;
		root =  insert(root, x);
	}
	/*printTree(root);
	cout<<"What do you want to search ?";
	int n;
	cin>>n;
	cout<<endl<<searchTree(n,root);	
	cout<<"Maximum Element is: "<<maxElement(root)<<endl;
	cout<<"Minimum Element is: "<<minElement(root)<<endl;;
	cout<<"Height of the tree: "<<height(root)-1<<endl;
	enqueue(root);enqueue(root->left);enqueue(root->right);
	cout<<dequeue()<<" "<<dequeue()<<" "<<dequeue()<<endl; 
	*/
	
	cout<<"Height of the tree: "<<height(root)-1<<endl;
	levelOrder(root);
	cout<<endl;
	cout<<"InOrder traversal..."<<endl;
	inOrder(root);
	cout<<endl;
	cout<<"PreOrder traversal..."<<endl;
	preOrder(root);
	cout<<endl;
	cout<<"Post Order traversal..."<<endl;
	postOrder(root);
	cout<<endl;
	
	///check if the tree is binary search tree or not!



	if(check(root)){
		cout<<"Is a Binary Search Tree"<<endl;
	}else{
		cout<<"Is not a Binary Search Tree"<<endl;
	}
/*
	while(true){
		cout<<"Of Whom Pre And Succ";
	int key;
	cin>>key;
	Node* pre = NULL;
	Node* suc = NULL;
	predSuc(root, key, pre, suc);
	if(pre!=NULL){
		cout<<pre->data<<endl;
	}else{
		cout<<"No Predecessor Found"<<endl;;
	}
	
	if(suc!=NULL){
		cout<<suc->data<<endl;
	}else{
		cout<<"No Successor Found"<<endl;
	}
	
	}
	*/
	
	/*
	int v1,v2;
	cin>>v1>>v2;
	kSmall(root, v1,v2);
	*/
	
	//Now Coming to find the pairs of two values present in the tree which makes up the sum as 
while(true){
		int val ;
	cin>>val;
	searchPair(val, root);
}
	
	
	
	
}
