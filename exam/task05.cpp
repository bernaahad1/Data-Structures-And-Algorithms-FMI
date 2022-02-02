#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> adj[200001];
int inp;
int edges;
vector<int> childW;

int findW(int curr) {
    if (adj[curr].size() == 0) {
        childW[curr] = 0;
        return curr;
    }
    int currW = 0;
    for (auto neigh : adj[curr]) {
        currW += findW(neigh);

    }
    childW[curr] = currW;
    return childW[curr] + curr;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cin >> edges >> inp;
    int maxNode = 0;
    while (edges--) {
        int start;
        int end;
        cin >> start >> end;
        if (maxNode < start) {
            maxNode = start;
        }
        if (maxNode < end) {
            maxNode = end;
        }
        adj[start].push_back(end);
    }
    childW.resize(200001, 0);
    for (int i = 1; i < maxNode+1; i++) {
        if (!adj[i].empty() && childW[i] == 0) {
            findW(i);
        }
    }
    while (inp--) {
        int start;
        cin >> start;
        cout << childW[start] << endl;
    }
    return 0;
}
