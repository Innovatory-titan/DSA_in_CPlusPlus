#include <bits/stdc++.h>
using namespace std;

class QueueArrays{
	int firstIndex, nextIndex, size;
	int *arr;
	int capacity;

public:
	QueueArrays(int capacity){
		this->capacity = capacity;
		arr = new int[capacity];
		firstIndex = 0;
		nextIndex = 0;
		size = 0;
	}

	void enqueue(int data){
		if (size == capacity) cout << "Queue Overflowed~~\n";
		arr[nextIndex] = data;
		size++;
		nextIndex = (nextIndex+1) % capacity;
	}

	int dequeue(){
		if (size == 0){
			cout << "UNDERFLOW~~\n";
			return -1;
		}
		int value = arr[firstIndex];
		firstIndex = (firstIndex+1) % capacity;
		size--;
		return value;
	}

	int front(){
		if (size == 0) return -1;
		return arr[firstIndex];
	}

	int getsize(){return size;}

	bool is_empty(){return size == 0;}
};

int main(){
	QueueArrays queue(10);
	queue.enqueue(89);
	queue.enqueue(23);
	queue.enqueue(23);
	queue.enqueue(90);
	queue.enqueue(45);
	queue.enqueue(100);
	cout << queue.getsize() << endl;
	cout << queue.dequeue() << endl;
	cout << queue.front() << endl;
	return 0;
}
