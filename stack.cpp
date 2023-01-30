#include <bits/stdc++.h>
using namespace std;

class Stack{
public:
	int array[5];
	int max_size = 5, size = 0, top = -1;

	void push(int element){
		if (size == max_size) cout << "stack overflow\n";
		top++; size++;
		array[top] = element;
	}

	int pop(){
		if (size == 0) cout << "stack underflow\n";
		int e = array[top];
		top--; size--;
		return e;
	}

	int top_element(){
		return array[top];
	}

	bool is_empty(){
		if (size == 0) return true;
		return false;
	}
};

int main(){
	cout.setf(ios::boolalpha);
	Stack stack;
	stack.push(12);
	stack.push(76);
	stack.push(45);
	stack.push(98);
	cout << stack.pop() << endl;
	cout << stack.top_element() << endl;
	cout << stack.is_empty() << endl;
	for (auto x: stack.array){
		cout << x << endl;
	}
	return 0;
}
