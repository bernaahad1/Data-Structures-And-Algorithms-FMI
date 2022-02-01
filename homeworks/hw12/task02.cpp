#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int start;
    int end;
    long long int effort;
    long long int profit;
    int num;

    Node(int start=0,int end = 0, long long int effort = 0, long long int profit = 0,int num=0) :
       start(start), end(end), effort(effort), profit(profit),num(num) {

    }
    bool operator<(const Node& other) {
        if (this->effort == other.effort) {
            return this->profit > other.profit;
        }
        return this->effort < other.effort;
    }
};

const int N = 2*int(1e5) ;
vector<Node> edgeList;
vector<int> parent;

int nodes;
int edges;

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
    
        parent.clear();
        parent.resize(nodes, -1);

        int count = 0;

        for (int i = 0; i < edges; i++) {
            int from = edgeList[i].start;
            int to = edgeList[i].end;

            int root1 = findRoot(from);
            int root2 = findRoot(to);

            if (root1 != root2) {
                count++;
                cout<<edgeList[i].num<<endl;
                parent[root1] = root2;

                if (count == nodes - 1) {
                    break;
                }
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
        long long int effort;
        long long int profit;
        cin >> start >> end >> effort >> profit;
        edgeList.push_back(Node(start-1, end-1, effort, profit,i+1));
    }
    kruskalAlg();

    return 0;
}
