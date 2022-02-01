#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100000;
vector<int> adjl[N];
int maxN = 0;

bool findCycle(int i,vector<bool> visited) {
    visited[i] = true;

    for (auto neigh : adjl[i]) {
        if (visited[neigh] == true) {
            return true;
        }
        else {
            if (findCycle(neigh, visited)) {
                return true;
            }
        }
    }

    return false;
}

bool hasCycle() {
    vector<bool> visited(N, false);

    for (int i = 0; i <= maxN; i++) {
        if (findCycle(i, visited)) {
            return true;
        }
    }
    return false;
}

int main()
{
    int inputs;
    cin >> inputs;
    while (inputs > 0) {
        int reb;
        cin >> reb;
        for (int i = 0; i < reb; i++) {
            int start;
            int end;
            cin >> start >> end;
            if (start > maxN) {
                maxN = start;
            }
            adjl[start].push_back(end);
        }

        cout<<hasCycle()<<" ";

        for (int i = 0; i <= maxN; i++) {
            adjl[i].clear();
        }
        maxN = 0;
        inputs--;
    }
    
    
    return 0;
}