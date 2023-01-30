#include <bits/stdc++.h>
using namespace std;

class StackNode{
public:
	int data;
	StackNode* next;
};

StackNode* newNode(int data){
	StackNode* stackNode = new StackNode();
	stackNode->data = data;
	stackNode->next = NULL;
	return stackNode;
}

void push(StackNode** root, int data){
	StackNode* stackNode = newNode(data);
	stackNode->next = *root;
	*root = stackNode;
	cout << data << " has been pushed in the stack\n";
}

int pop(StackNode** root){
	StackNode* temp = *root;
	*root = (*root)->next;
	int popped_data = temp->data;
	free(temp);
	cout << popped_data << " has been popped out of stack\n";
	return popped_data;
}

int main(){
	StackNode* root = NULL;
	//pushing some elements;
	push(&root, 45);
	push(&root, 99);
	push(&root, 12);
	push(&root, 101);
	cout << pop(&root);
	return 0;
}
