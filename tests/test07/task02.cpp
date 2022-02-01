#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;
const int N = 2001;
vector<pair<long long, long long>> gr[N];
unordered_set<long long> wrongNums;
int nodes;
long long edges;

bool findEdge(long long start, long long end) {

    for (auto neigh : gr[start]) {
        int isBad=wrongNums.count(neigh.second);
        if (neigh.first == end && isBad==0) {
            return true;
        }
    }
    return false;
}

int main() {
    cin >> nodes >> edges;

    while (edges > 0) {
        long long start;
        long long end;
        long long weight;
        cin >> start >> end >> weight;
        gr[start].push_back({ end,weight });

        edges--;
    }
    long long numWrongNums;
    cin >> numWrongNums;
    while (numWrongNums > 0) {
        long long num;
        cin >> num;
        wrongNums.insert(num);
        numWrongNums--;
    }
    int  numInputs;
    cin >> numInputs;

    while (numInputs > 0) {
        long long numNodes;
        cin >> numNodes;
        long long start;
        cin >> start;
        numNodes--;
        bool found = true;
        while (numNodes > 0) {
            long long num;
            cin >> num;
            if (!findEdge(start, num)) {
                found = false;
                break;
            }
            start = num;
            numNodes--;
        }
        cout << found;
        numInputs--;
    }
    return 0;
}
