#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

const int N = 1e5;
vector<pair<long long, long long>> graph[N];
long long numNodes;
long long numEdges;
vector<pair<long long, long long>> paths;
const int mod = 1e9 + 7;

void shortestPath(long long head) {
    paths.resize(numNodes + 1);
    for (long long i = 0; i <= numNodes; i++) {
        paths[i].first = LLONG_MAX;
        paths[i].second = 0;
    }
    paths[head].first = 0;
    paths[head].second = 1;
    priority_queue< pair<long long, long long>, vector <pair<long long, long long>>, greater<pair<long long, long long>> > q;
    q.push({ 0,head });

    while (!q.empty()) {
        long long current = q.top().second;
        long long currWeight = q.top().first;
        q.pop();

        if (currWeight > paths[current].first) {
            continue;
        }

        for (auto neigh : graph[current]) {
            long long childNum = neigh.first;
            long long childWeight = neigh.second;
            if (paths[childNum].first > currWeight + childWeight) {
                paths[childNum].first = currWeight + childWeight;
                paths[childNum].second = paths[current].second%mod;
                q.push({ paths[childNum].first, childNum });
            }
            else if (paths[childNum].first == currWeight + childWeight) {
                paths[childNum].second = ((paths[childNum].second% mod) +(paths[current].second%mod)) % mod;
                
            }
        }

    }

}


int main() {

    cin >> numNodes >> numEdges;
    for (long long i = 0; i < numEdges; i++) {
        long long start;
        long long end;
        long long weight;
        cin >> start >> end >> weight;
        graph[start].push_back({ end, weight });
    }
    shortestPath(1);

    if (paths[numNodes].first == LLONG_MAX) {
        cout << -1 << " " << 0;
    }
    else {
        cout << paths[numNodes].first  << " " << paths[numNodes].second%mod << endl;
    }
    return 0;
}