#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* next;
};
Node* head = NULL;
Node* createNode(int data){
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
Node* insertAtTheBegin(int data){
	Node* newNode = createNode(data);
	newNode->next = head;
	head = newNode;
	
}
void printNodes(){
	Node* temp = head;
	cout<<"The List is: ";
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}
void swapLast(){
	Node* temp = head;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	int datAtLast = temp->data;
	temp->data = head->data;
	head->data = datAtLast;
	cout<<"Swapping List..."<<endl;;
	printNodes();
}
Node* insertAny(int data, Node* header){
	Node* newNode = createNode(data); 
	if(header==NULL){
		return newNode;
	}
}
int main(){
	cout<<"How Many Nodes do you want to insert: ";
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		insertAtTheBegin(x);
	}
	printNodes();
	swapLast();
	cout<<"Enter other Linked List Count of digits: ";
	int newCount ;
	cin>>newCount;
	Node* newList = NULL;
	for(int i=0;i<newCount;i++){
		int x ;
		cin>>x;
		newList =  insertAny(x,newList);
	}
}
