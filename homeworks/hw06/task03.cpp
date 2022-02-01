#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data, Node* left = nullptr, Node* right = nullptr) :
        data(data), left(left), right(right) {
    }
    
};
Node* findMin(Node* node) {
    Node* current = node;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}
Node* insert(Node* current,int data) {
    if (current == nullptr) {
        return new Node(data);
        
    }
    if (data >= current->data) {
        current->right= insert(current->right,data);
    }
    else {
        current->left = insert(current->left,data);
    }
    return current;
}
Node* deleteNode(Node* current,int data) {
    if (current != nullptr) {
        if (data < current->data) {
            current->left = deleteNode(current->left,data);
        }
        else if (data > current->data) {
            current->right = deleteNode(current->right,data);
        }
        else {
            if (current->left == nullptr) {
                Node* temp = current->right;
                delete current;
                return temp;
            }
            if (current->right == nullptr) {
                Node* temp = current->left;
                delete current;
                return temp;
            }
            Node* min = findMin(current->right);
            current->data = min->data;
            current->right =deleteNode( current->right,min->data);
        }
        return current;
    }
    else {
        return current;
    }

}

void findKthLargest(Node* root, int k, int& count,int& find) {
    
    if (root == nullptr || count >= k) {
        return;
    }
    if (root->right != nullptr) {
       findKthLargest(root->right, k, count,find);
    }
    count++;
    if (count == k) {
        find = root->data;
        return;
    }
    if (root->left != nullptr) {
      findKthLargest(root->left, k, count,find); 
    }
    return;
}

void levelOrder(Node* root) {
    queue<Node*> level;
    level.push(root);
    while (!level.empty()) {
        Node* node = level.front();
        level.pop();
        cout << node->data << " ";
        if (node->left != nullptr) {
            level.push(node->left);
        }
        if (node->right != nullptr) {
            level.push(node->right);
        }
    }
}

int main() {
    
    int size;
    int key;
    cin >> size;
    cin >> key;
    Node* root = nullptr;
    for (int i = 0; i < size; i++) {
        int data;
        cin >> data;
        root = insert(root,data);
    }
    int count = 0;
    int find;
    findKthLargest(root, key, count, find);
    root = deleteNode(root, find);

    levelOrder(root);
    return 0;
}
