#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include<queue>
#include <algorithm>
#include <set>
using namespace std;

const int N = 1000001;
vector<int> gr[N];
vector<int> deg;
int nodes;
int edges;
queue<int> q;
vector<int> visited;
vector<int> alrIn;

queue<int> findTheMinTreeRoots() {
    int leftNodes = nodes;
    while (leftNodes > 2) {
        
        queue<int> newQ;
        alrIn.clear();
        alrIn.resize(nodes, 0);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            leftNodes--;
            for (auto neigh : gr[curr]) {
                if (deg[neigh] > 0) {
                    deg[curr]--;
                    deg[neigh]--;
                    if (alrIn[neigh] == 0 && deg[neigh]==1) {
                        newQ.push(neigh);
                        alrIn[neigh]++;
                    }
                    
                }
            }

        }
        q = newQ;

    }
    return q;
}


int main() {
    cin >> nodes;
    deg.clear();
    deg.resize(nodes, 0);
    
    edges = nodes - 1;
    while (edges > 0) {
        int start;
        int end;
        cin >> start >> end;
        gr[start].push_back(end);
        gr[end].push_back(start);
        deg[start]++;
        deg[end]++;

        edges--;
    }

    alrIn.resize(nodes, 0);
    for (int i = 0; i < nodes; i++) {
        if (deg[i] == 1) {
            q.push(i);
            alrIn[i]++;
        }

    }
    q = findTheMinTreeRoots();
    
    set<int> result;
    while (!q.empty()) {
        result.insert(q.front());
        q.pop();
    }
    for (auto curr : result) {

        cout << curr << " ";

    }

    return 0;
}