#include <bits/stdc++.h>
using namespace std;

class Node{
public:
   int data;
   Node *next;
   Node (int data){
      this->data = data;
      this->next = NULL;
   }
};

void printLinkedList(Node* head){
   Node* temp = head;
   while (temp != NULL){
      cout << temp->data << "->";
      temp = temp->next;
   }
   cout << "NULL" << endl;
}

Node* takeInput(){
   Node* head = NULL;
   Node* tail = NULL;
   int data; cin >> data;
   if (data == -1) return NULL;
   while (data != -1){
      Node* newNode = new Node(data);
      if (head == NULL){
         head = newNode; tail = newNode;
      }
      else{
         tail->next = newNode;
         tail = newNode;
      }
      cin >> data;
   }
   return head;
}

int lengthLL(Node* head){
   Node* temp = head;
   int count = 0;
   while (temp != NULL){
      temp = temp->next;
      count++;
   }
   return count;
}

Node* mergeTwoLists(Node* lst1, Node* lst2){
    if (lst1 == NULL) return lst2;
    if (lst2 == NULL) return lst1;
    
    Node* ptr = lst1;
    if (lst1->data > lst2->data){
        ptr = lst2;
        lst2 = lst2->next;
    }else{
        lst1 = lst1->next;
    }
    
    Node* curr = ptr;
    while (lst1 && lst2){
        if (lst1->data < lst2->data){
            curr->next = lst1;
            lst1 = lst1->next;
        }else{
            curr->next = lst2;
            lst2 = lst2->next;
        }
        curr = curr->next;
    }
    
    if (!lst1) curr->next = lst2;
    else{curr->next = lst1;}
    
    return ptr;
}

Node* insertNode(int data, int N, Node* head){ // N = 3
   Node* newNode = new Node(data);
   if (N == 0){
      newNode->next = head;
      return newNode;
   }
   Node* t = head;
   for (int i = 1; i < N; i++){ // 5, 6, 89, 21, 56
      t = t->next;
   }
   newNode->next = t->next;
   t->next = newNode;
   return head;
}

//using insertion method using dummy pointer
Node* insertNode1(int data, int N, Node* head){
   Node* dummyptr = new Node(-1);
   dummyptr->next = head;

   Node* t = dummyptr;
   for (int i = 0; i < N; i++){
      t = t->next;
   }
   Node* newdata = new Node(data);
   newdata->next = t->next;
   t->next = newdata;
   return head;
}

Node* recursionInsertion(int data, int N, Node* head){
   if (N == 0){
      Node* newNode = new Node(data);
      newNode->next = head;
      return newNode;
   }
   // calling recurisvely 
   Node* rec = recursionInsertion(data, N-1, head->next);
   // setting the value
   head->next = rec;
   return head;
}

Node* deleteNode(int N, Node* head){
   if (N == 0){
      Node* newhead = head->next;
      delete head; // we can just increment head but that won't delete the space in memory so we made a new variable and delete the head
      return newhead;
   }
   Node* t = head;
   for (int i = 1; i < N; i++){
      t = t->next;
   }
   Node* n = t->next->next;
   delete t->next;
   t->next = n;
   return head;
}

// Node* deleteNode1(int N, Node* head){
//    Node* dummyptr = new Node(-1);
//    dummyptr->next = head;
//    Node* temp = dummyptr;
//    for (int i = 0; i < N; i++){
//       temp = temp->next;
//    }
//    Node* n = temp->next->next;
//    delete temp->next;
//    temp->next = n;
//    return head;
// }

Node* reversedLL(Node* head){
   if (head == NULL || head->next == NULL) return head;
   Node* newNode = reversedLL(head->next);
   head->next->next = head;
   head->next = NULL;
   return newNode;
}

int main(){
   // Node* newNode0 = new Node(0);
   // Node* newNode1 = new Node(1);
   // Node* newNode2 = new Node(2);
   // Node* newNode3 = new Node(3);
   // Node* newNode4 = new Node(4);

   // newNode0->next = newNode1;
   // newNode1->next = newNode2;
   // newNode2->next = newNode3;
   // newNode3->next = newNode4;
   // newNode4->next = NULL;
   cout << "Enter -1 when you want to finish the linked list ...\n";
   Node* head = takeInput();
   printLinkedList(head);
   int length = lengthLL(head);
   printf("The length of the linked list is %d\n", length);
   // head = insertNode(7, 0, head);
   // head = insertNode1(8, 3, head);
   // head = recursionInsertion(7, 0, head);
   // head = recursionInsertion(8, 3, head);
   // cout << "\nLinked List after inserting some random numbers in: \n";
   // printLinkedList(head);
   
   // head = deleteNode(0, head);
   // head = deleteNode1(0, head);
   head = deleteNode(3, head);
   cout << "\nLinked List after deleting some elements from within: \n";
   printLinkedList(head);
   head = reversedLL(head);
   printf("Linked list after reversing its order\n");
   printLinkedList(head);
   return 0;
}
