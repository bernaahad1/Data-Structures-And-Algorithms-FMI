#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *leftNode;
        Node *rightNode;
        Node(int d) {
            data = d;
            leftNode = NULL;
            rightNode = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->leftNode, data);
                    root->leftNode = cur;
                } else {
                    cur = insert(root->rightNode, data);
                    root->rightNode = cur;
               }

               return root;
           }
        }
    int findLSum(Node* curr){
        if(curr==nullptr){
            return 0;
        }
        if(curr->leftNode==nullptr && curr->rightNode == nullptr){
            if(curr->data%2!=0){
                
                return curr->data;
            }
        }
        return findLSum(curr->leftNode)+findLSum(curr->rightNode);
    }

	void leaves(Node *root) {
		if(root==nullptr){
            return;
        }
        cout<<findLSum(root);
    }


}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
	myTree.leaves(root);
    return 0;
}