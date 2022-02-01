#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int start, end, weight;

    Edge(int start=0, int end=0, int weight=0) :
    start(start), end(end), weight(weight){
    }

    bool operator<(const Edge& edg) {
        return this->weight < edg.weight;
    }
};

const int N = 1000 ;
vector<Edge> edgeList;
vector<int> parent;

int nodes;
int edges;
int minSpeed = 1;
int maxSpeed = 30000;

int findRoot(int node)
{
    if (parent[node] == -1)
        return node;

    int root = findRoot(parent[node]);

    parent[node] = root;

    return root;
}

void kruskalAlg() {
    sort(edgeList.begin(), edgeList.end());
    for (int j = 0; j < edges; j++) {
        parent.clear();
        parent.resize(nodes, -1);

        int count = 0;
        int minWeight = edgeList[j].weight;
       
        for (int i = j; i < edges; i++) {
            int from = edgeList[i].start;
            int to = edgeList[i].end;

            int root1 = findRoot(from);
            int root2 = findRoot(to);

            if (root1 != root2) {
                count++;
                parent[root1] = root2;

                if (count == nodes-1) {
                    if (edgeList[i].weight - minWeight < maxSpeed - minSpeed) {
                        minSpeed = minWeight;
                        maxSpeed = edgeList[i].weight;
                    }
                    break;
                }
            }

        }
        if (count < nodes-1) {
            break;
        }
    }
    cout << minSpeed << ' ' << maxSpeed;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> nodes >> edges;
    for (int i = 0; i < edges; i++) {
        int start;
        int end;
        int weight;
        cin >> start >> end >> weight;
        edgeList.push_back(Edge(start-1, end-1, weight));
    }
    kruskalAlg();

    return 0;
}