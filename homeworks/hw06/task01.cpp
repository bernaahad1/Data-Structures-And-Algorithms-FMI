#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Node {
public:
    int key;
    vector<Node*>children;
    int numChildren;

    Node(int key, vector<Node*>children = {}, int numChildren = 0) :
        key(key), children(children),numChildren(numChildren) {

    }
    
    void addChild(Node* child) {
        this->children.push_back(child);
        numChildren++;
    }
};

int getAllChildren(Node* node) {
    int num = node->numChildren;
    for (int i = 0; i < node->numChildren; i++) {
        num += getAllChildren(node->children[i]);
    }
    return num;
}

int main() {
    int size;
    cin >> size;
    vector<Node*> arr;
    for (int i = 0; i < size; i++) {
        arr.push_back(new Node(i));
    }
    int key;
    
    while (cin >> key) {
        int child;
        cin >> child;
        arr[key]->addChild(arr[child]);
    }

    for (int i = 0; i < size; i++) {
        cout << getAllChildren(arr[i]) << " ";
    }

    return 0;
}
