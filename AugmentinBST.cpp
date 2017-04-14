#include<iostream>
using namespace std;
struct Node{
	Node* left;
	Node* righ;
	int data;
	int down;
};
Node* createNode(int data){
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = NULL;
	newNode->righ = NULL;
	newNode->down = 1;
	return newNode;
}
Node* insert(Node* root, int data){
	if(root==NULL)
		root = createNode(data);
	else{
		root->down+=1;
	 	if(root->data>data){
			root->left = insert(root->left, data); 	
		}else{
			root->righ = insert(root->righ, data); 
		}
	}
	return root;
}
void inOrder(Node* root){
	if(root==NULL)
		return;
	inOrder(root->left);
	cout<<root->data<<" "<<root->down<<endl;;
	inOrder(root->righ);
}
int lessThanMe(Node* root, int me){
	if(root==NULL){
		return 0;
	}
	else{
		if(root->data>me){
			return lessThanMe(root->left,me);
		}else{// out root ka data is less than me so go to right
			return lessThanMe(root->righ,me)+root->left->down+1;
		}
	}
}
int main(){
	Node* root = NULL;
	cout<<"How Many Elements do you want to enter";
	int n;
	cin>>n;
	while(n--)
	{
		int x;
		cin>>x;
		root =  insert(root,x);
	}
	inOrder(root);
	while(true){
	
	cout<<"How Many roots are less than Me Enter <Me>";
	int me;
	cin>>me;
	int ans = lessThanMe(root,me);
	cout<<ans<<endl;}
}
