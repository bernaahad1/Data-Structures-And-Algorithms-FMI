#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<queue>
#include <climits>
#include <set>
#include <unordered_set>
using namespace std;

const int N = int(1e5+1);

vector<pair<int, int>> graph[N];
vector<int> dist;
int numNodes;
int numEdges;
int numStartPoints;
int numEndPoints;

unordered_set<int> groupEnds;

void findMinPath(int start) {
    dist.resize(numNodes + 1);
    set<int> neededMinDist;
    for (int i = 0; i <= numNodes; i++) {
       dist[i] = INT_MAX;            
    }
    dist[start] = 0;
       
    priority_queue< pair<int, int>, vector <pair<int, int>>, greater<pair<int, int>> > q;
    q.push({ 0,start });
    
    while (!q.empty()) {
       int current = q.top().second;
       int currWeight = q.top().first;
       q.pop();
    
       if (currWeight > dist[current]) {
          continue;
       } 
    
       for (auto neigh : graph[current]) {
           int childNum = neigh.first;
           int childWeight = neigh.second;
           if (dist[childNum] > currWeight + childWeight) {
                dist[childNum] = currWeight + childWeight;
                if (groupEnds.count(childNum) != 0) {
                     neededMinDist.insert(dist[childNum]);
                }
                 q.push({ dist[childNum], childNum });
           }
                
       }
    
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> numNodes >> numEdges;
    for (int i = 0; i < numEdges; i++) {
        int from;
        int to;
        int weight;
        cin >> from >> to >> weight;
        graph[from].push_back({ to,weight });
        graph[to].push_back({ from,weight });
    }
    cin >> numEndPoints;
    for (int i = 0; i < numEndPoints; i++) {
        int ends;
        cin >> ends;
        graph[numNodes].push_back({ ends,0 });
        graph[ends].push_back({ numNodes,0 });
        groupEnds.insert(ends);
    }
    findMinPath(numNodes);
    cin >> numStartPoints;
    for (int i = 0; i < numStartPoints; i++) {
        int starts;
        cin >> starts;
        cout << dist[starts]<<endl;
        
    }
    return 0;
}