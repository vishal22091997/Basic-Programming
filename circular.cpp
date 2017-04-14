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
	return newNode;
}
void addNode(int data){
	Node* newNode = createNode(data);
	if(head == NULL){
		head = newNode;
		newNode->next = head;
		return;
	}
	Node* temp = head;
	while(temp->next!=head){
		temp = temp->next;
	}
	newNode->next = temp->next;
	temp->next = newNode; 
	
	
}
void printList(){
	Node* temp = head;
	int count = 1;
	while(temp!=head||count){
		count =0;
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}
bool deleteElement(int data){
	Node* temp = head;
	if(head->data == data){
		if(head == head->next){
			head == NULL;
		}else{
			Node* temp2 = head;
			head = head->next;
			Node
			while(temp2->next!=head)
		}
	}
	
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cout<<"Enter the number: ";
		cin>>x;
		addNode(x);
	}
	printList();
	cout<<"Which Item Do you want to remove: ";
	int remove;
	cin>>remove;
	deleteElement(remove);
	
	
}
