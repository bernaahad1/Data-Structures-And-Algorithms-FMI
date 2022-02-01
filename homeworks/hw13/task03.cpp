#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1000000;
vector<int> countEdg;
vector<int> gr[N];
int oddEdg = 0;
int visited[N];


void dfs(int curr) {
    visited[curr] = 1;

    for (auto neigh : gr[curr]) {
        if (!visited[neigh]) {
            dfs(neigh);
        }
    }
}

bool isConnected(int start,int end) {
    dfs(start);
    for (int i = start; i <= end; i++) {
        if (visited[i] == false) {
            return false;
        }
    }
    return true;
}

int main() {

    int queries;
    cin >> queries;
    while (queries > 0) {
        int nodes;
        int edges;
        int minNode = N;
        int maxNode = 0;
        oddEdg = 0;
        cin >> nodes >> edges;
        countEdg.clear();
        countEdg.resize(N, 0);
        for (int i = 0; i < N; i++) {
            visited[i] = false;
        }
        
        
        while (edges > 0) {
            int start;
            int end;
            cin >> start >> end;
            countEdg[start]++;
            countEdg[end]++;
            gr[start].push_back(end);
            gr[end].push_back(start);
            
            if (start < minNode) {
                minNode = start;
            }
            if (end < minNode) {
                minNode = end;
            }
            if (start > maxNode) {
                maxNode = start;
            }
            if (end > maxNode) {
                maxNode = end;
            }
            edges--;
        }

        for (int i = minNode; i <= maxNode; i++) {
            if (countEdg[i] % 2 != 0) {
                oddEdg++;
            }
            
        }
        
        if (nodes-1 > maxNode - minNode) {
            cout << "none" << endl;
        }
        else if (isConnected(minNode,maxNode)) {
            if (oddEdg == 0) {
                cout << "ecycle" << endl;
            }
            else if (oddEdg == 2) {
                cout << "epath" << endl;
            }
            else {
                cout << "none" << endl;
            }
        }
        else {
            cout << "none" << endl;
        }
        queries--;
        for (int i = 0; i < N; i++) {
            gr[i].clear();
        }
        
    }
    return 0;
}