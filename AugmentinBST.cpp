#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* left;
	Node* right;
	int count;
};
Node* createNode(int data){
	Node* newNode = new Node();
	newNode->data = data;
	newNode->count = 0;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
Node* insertNode(Node* root, int data){
	if(root==NULL){
		Node* newNode = createNode(data);
		newNode->count = 1;
		return newNode;
	}else if(root->data>data){
		root->left = insertNode(root->left, data);
	}else if(root->data<data){
		root->right = insertNode(root->right, data);
	}else if(root->data==data){
		root->count++;}
	return root;
}
void inOrder(Node* root){
	if(root!=NULL){
		inOrder(root->left);
		cout<<root->data<<" "<<root->count<<endl;
		inOrder(root->right);
	} 
}
void findData(Node* root, int data){
	if(root==NULL){
		return;
	}else if(root->data>data){
		findData(root->left, data);
	}else if(root->data<data){
		findData(root->right, data);
	}else{
		cout<<root->data<<" ";
	}
}
void checkSimilarity(Node* root, Node* root2){
	if(root!=NULL){
		checkSimilarity(root->left, root2);
		findData(root2, root->data);
		checkSimilarity(root->right, root2);
	}
}
void inOrderSave(Node* root, int a[], int &start){
	if(root!=NULL){
		inOrderSave(root->left, a, start);
		a[start++] = root->data;
		inOrderSave(root->right, a, start);
	}
}
void checkSimilarArraysAndPrint(int a[], int b[], int n, int m){
	 // this method can be called as the intersection of two arrays
	 //this method takes linear time i.e O(n+m);
	int i = 0,j = 0; 
	while(i<n&&j<m){
		if(a[i]>b[j]){
			j++;
		}else if(a[i]<b[j]){
			i++;
		}else{
			cout<<a[i++]<<" ";
			j++;
		}
	}
	 
}
int main(){
	cout<<"How Many";
	int n;
	cin>>n;
	Node* root = NULL;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		root =  insertNode(root, x);
	}
	inOrder(root);
	Node* root2 = NULL;
	cout<<"How Many for second";
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		int x;
		cin>>x;
		root2 =  insertNode(root2,x);
	}
	cout<<"Second Tree..."<<endl;
	inOrder(root2);
	// checkSimilarity(root2, root) first elements root2's every element will be processed
	// over and it will be matched with all values of root tree with binary search tree
	cout<<"\n Printing the elements which are similar in Tree:1 and Tree:2\n";
	
	if(n>m){
		checkSimilarity(root2, root);// this will have complexity of mlog(n)
	}else{
		checkSimilarity(root, root2);// this will have complexity of nlog(m)
	}
	// After adding this last if-else Structure the complexity of the solution is minimized
	
	cout<<"Doing the same solution by taking the linear Time with some Extra Space";
	int a[n];
	int start1 = 0;
	inOrderSave(root, a,start1);
	int b[m];
	int start2 = 0;
	inOrderSave(root2, b,start2);
	 
	cout<<endl;
	checkSimilarArraysAndPrint(a,b,start1,start2); //this method is O(n+m);
	//where n+m is the size of array1 and array2
	
	
}
