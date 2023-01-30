#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* next;
	Node* prev;

	Node (int data){
		this->data = data;
		this->next = NULL;
		this->prev = NULL;
	}
};

int lengthLL(Node* head){
	int count = 0;
	while(head != NULL){
		head = head->next; count++;
	}
	return count;
}

Node* takeInput(Node* head, Node* tail){
	int data; cin >> data;
	while (data != -1){
		Node* newNode = new Node(data);
		if (head == NULL){
			head = newNode;
			tail = newNode;
		}else{
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

void printLL(Node* head){
	Node* temp = head;
	while (temp != NULL){
		cout << temp->data << "<->";
		temp = temp->next;
	}
	cout << "NULL\n";
}

Node* insertion(int data, int N, Node* head){
	Node* newNode = new Node(data);
	if (N == 0){
		newNode->next = head;
		newNode->prev = NULL;
		return newNode;
	}
	Node* temp = head;
	for (int i = 1; i < N; i++){
		temp = temp->next;
	}
	newNode->next = temp->next;
	temp->next = newNode;
	newNode->prev = temp;
	return head;
}

Node* deletion(Node* head, int N){
	if (N == 0){
		Node* nextNode = head->next;
		delete head;
		return nextNode;
	}
	Node* temp = head;
	for (int i = 1; i < N; i++){
		temp = temp->next;
	}
	Node* t = temp->next->next;
	delete temp->next;
	temp->next = t;
	t->prev = temp;
	return head;
}

Node* reversedLL(Node* head){
	if (head == NULL || head->next == NULL) return head;
	Node* rec = reversedLL(head->next);
	rec->prev = NULL;
	head->next->next = head;
	head->prev = head->next;
	head->next = NULL;
	return rec;
}

int main(){
	Node* head = NULL, *tail = NULL;
	head = takeInput(head, tail);
	printLL(head);
	head = insertion(999, 5, head);
	cout << "Doubly linked list after inserting some elements...\n";
	printLL(head);
	head = deletion(head, 3);
	cout << "Doubly linked list after deleting some elements...\n";
	printLL(head);
	cout << "The length of the Doubly linked list is " << lengthLL(head) << endl;
	head = reversedLL(head);
	cout << "Doubly linked list after reversing its order...\n";
	printLL(head);
	return 0;
}
