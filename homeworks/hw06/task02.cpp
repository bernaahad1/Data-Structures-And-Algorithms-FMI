#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int index = 0;
    int coordinates = 0;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(int index = 0, int coordinates = 0, Node* left = nullptr, Node* right = nullptr) :
        index(index), coordinates(coordinates), left(left), right(right) {

    }

    void addChild(int leftIndex, int rightIndex) {
        if (leftIndex != -1) {
            this->left = new Node(leftIndex, this->coordinates - 1);
        }
        if (rightIndex != -1) {
            this->right = new Node(rightIndex, this->coordinates + 1);

        }
    }
};

bool compare(const pair<int, int>& p1, const pair<int, int>& p2) {
    if (p1.second < p2.second) {
        return true;
    }
    if (p1.second == p2.second && p1.first < p2.first) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    int size;
    cin >> size;
    vector<pair<int,int>> X;
    vector<Node*> nodes(size,nullptr);

    nodes[0] = new Node(0, 0);
    X.push_back({ 0,0 });
   for (int i = 0; i < size; i++) {
        int left;
        int right;
        cin >> left >> right;
        nodes[i]->addChild(left, right);
        if (left != -1) {
            nodes[left] = nodes[i]->left;
            X.push_back({ left,nodes[left]->coordinates });
        }
        if (right != -1) {
            nodes[right] = nodes[i]->right;
            X.push_back({ right,nodes[right]->coordinates });
        }
    }

    sort(X.begin(), X.end(),compare);
    
    cout << X[0].first << " ";
    for (int i = 1; i < size; i++) {
        if (X[i].second == X[i - 1].second) {
            continue;
        }
        else {
            cout << X[i].first << " ";
        }
    }
    
    for (size_t i = 0; i < nodes.size(); i++) {
        delete nodes[i];
    }
    return 0;
}