#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node (int data){
        this->data = data;
        next = NULL;
    }
};

int lengthLL(Node* head){
    Node* temp = head;
    int count = 0;
    while (temp != NULL){
        temp = temp->next;
        count++;
    }
    return count;
}

Node* removeNode(Node* head, int index){
    int length = lengthLL(head);
    if (index == 0) return head;
    else if ((length - index) == 0){
        Node* newNode = head->next;
        delete head;
        return newNode;
    }
    Node* temp = head;
    for (int i = 1; i < (length-index); i++)
        temp = temp->next;
    Node* t = temp->next->next;
    delete temp->next;
    temp->next = t;
    return head;
}

oid printLL(Node* head){
    Node* temp = head;
    while (temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL\n\n";
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    int data; cin >> data;
    while (data != -1){
        Node* newNode = new Node(data);
        if  (head == NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    printLL(head);
    int index;
    cout << "what index of element you want to remove from back of LL: ";
    cin >> index;
    head = removeNode(head, index);
    printLL(head);
    cout << "what index of element you want to remove from back of LL: ";
    cin >> index;
    head = removeNode(head, index);
    printLL(head);
    return 0;
}
