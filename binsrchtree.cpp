#include <bits/stdc++.h>
using namespace std;

/* some terms we will mostly see while using trees ---------->>>
1) root = the upper most node is called root 
2) children = nodes who is originated from other nodes are also called children
3) parent = nodes who originate other nodes from itself are also called parent
4) sibling = children nodes originated from same parent are called siblings
5) leaf = node with no children are called leaf, Internal node = at least have one child  */


class BstNode{
public:
    int data;
    BstNode* left;
    BstNode* right;

    BstNode(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

BstNode* getNewNode(int data){
    BstNode* newNode = new BstNode(data);
    newNode->left = newNode->right = NULL;
    return newNode;
}

BstNode* insertion(BstNode* rootNode, int data){
    if (rootNode == NULL){
        rootNode = getNewNode(data);
        return rootNode;
    }else if (data <= rootNode->data){
        rootNode->left = insertion(rootNode->left, data);
    }else{
        rootNode->right = insertion(rootNode->right, data);
    }
    return rootNode;
}

bool search(BstNode* rootNode, int number){
    if (rootNode == NULL) return false;
    else if (rootNode->data == number) return true;
    else if (rootNode->data < number) return search(rootNode->right, number);
    else return search(rootNode->left, number);
}

int main(){
    BstNode* rootNode = NULL;
    rootNode = insertion(rootNode, 56); rootNode = insertion(rootNode, 23); rootNode = insertion(rootNode, 78);
    rootNode = insertion(rootNode, 34); rootNode = insertion(rootNode, 12); rootNode = insertion(rootNode, 99);

    int number; cout << "Enter a number to search: "; cin >> number;
    if (search(rootNode, number)) cout << "Number found in BST\n";
    else cout << "number not found in BST\n"; 
    return 0;
}
