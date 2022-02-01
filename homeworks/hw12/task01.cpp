#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

const int N = 1000;
vector<int> adj[N];
vector<int> dist;

int nodes;
int edges;

void findPath(int start, int mark)
{
    dist[start] = mark;

    for (auto neighbour : adj[start])
    {
        if (dist[neighbour] != mark) {
            findPath(neighbour, mark);
        }
    }

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> nodes >> edges;
    for (int i = 0; i < edges; i++) {
        int start;
        int end;
        cin >> start >> end;
        adj[start-1].push_back(end-1);
        adj[end-1].push_back(start-1);
    }
    dist.resize(nodes, -1);
    int mark = 1;
    for (int i = 0; i < nodes; i++) {
        if (dist[i] == -1) {
            findPath(i, mark);
            mark++;
        }
    }
    int inputs;
    cin >> inputs;
    while (inputs > 0) {
        int type;
        int start;
        int end;
        cin >> type >> start >> end;
        if (type == 1) { //question
            if (dist[start-1] == dist[end-1]) {
                printf("1");
            }
            else {
                printf("0");
            }
        }
        else if (type == 2) { //info
            adj[start-1].push_back(end-1);
            adj[end-1].push_back(start-1);
            findPath(end-1, dist[start-1]);
        }
        inputs--;
    }

    return 0;
}
