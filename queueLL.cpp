#include <bits/stdc++.h>
using namespace std;

template <typename T>  
class Node{
public:
	T data;
	Node<T>* next;

	Node(T data){
		this->data = data;
		next = NULL;
	}
};

template <typename T> 
class Queue{
	Node<T>* head;
	Node<T>* tail;
	int size;

public:
	Queue(){
		size = 0;
		head = NULL;
		tail = NULL;
	}

	void displayQueue(){
		Node<T>* temp = head;
		while (temp != NULL){
			cout << temp->data << " ";;
			temp = temp->next;
		}
	}

	bool is_empty(){
		return head == NULL;
	}

	int getsize(){
		return size;
	}

	void enqueue(T data){
		Node<T>* newNode = new Node<T>(data);
		if (head == NULL){
			head = newNode; 
			tail = newNode;
		}else{
			tail->next = newNode;
			tail = tail->next;
		}
		size++;
	}

	T dequeue(){
		if (head == NULL) return 0;
		Node<T>* temp = head;
		T value = temp->data;
		head = head->next;
		delete temp;
		size--;
		return value;
	}

	T front(){
		if (head == NULL) return 0;
		return head->data;
	}

	T back(){
		if (head == NULL) return 0;
		return tail->data; 
	}
};

int main(){
	Queue <int> queue;
	queue.enqueue(18);
	queue.enqueue(99);
	queue.displayQueue();
	cout << queue.dequeue() << endl;
	cout << queue.back() << endl;
	queue.enqueue(199);
	queue.enqueue(23);
	queue.displayQueue();
	return 0;
}