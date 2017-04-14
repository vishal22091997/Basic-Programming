#include<iostream>
#include<stack>
using namespace std;

struct Node{
	int data;
	Node* next;
};

Node* createNode(int data){
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
void enqueue(int data, Node* start, Node* end){
	Node* newNode = createNode(data);
	if(end==NULL){
		start = newNode;
		end = newNode;
		return;
	}
	end->next = newNode;
	end = newNode;
}
void reverseQueue(){
	Node* temp = start;
	Node* newQ = NULL;
	Node* newQe =  NULL;
	while(temp!=end){
		enqueue(temp->data,newQ, newQe);
		temp = temp->next;
	}
	Node* temp2 = new
}
int main(){
	Node* start = NULL;
    Node* end = NULL;
}
