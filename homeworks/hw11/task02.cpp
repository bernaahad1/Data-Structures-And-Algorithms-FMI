#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

struct Edge {
    int end;
    int kg;
    int time;
    

    Edge(int end = 0, int kg = 0, int time = 0):
    end(end),kg(kg),time(time){
    }
};

int maxKg = INT_MIN;
int minKg = INT_MAX;
const int N = 100001;
vector<Edge> graph[N];
int numNodes;
int numEdges;
int maxTime;
vector<int> paths;

bool shortestPath(int start,int max) {
    paths.resize(numNodes + 1);
    for (int i = 0; i <= numNodes; i++) {
        paths[i] = INT_MAX;
        
    }
    paths[start] = 0;
    
    priority_queue< pair<int, int>, vector <pair<int, int>>, greater<pair<int, int>> > q;
    q.push({ 0,start });

    while (!q.empty()) {
        int current = q.top().second;
        int currTime = q.top().first;
        q.pop();

        if (currTime > paths[current]) {
            continue;
        }

        for (auto neigh : graph[current]) {
            int childNum = neigh.end;
            int childTime = neigh.time;
            int childKg = neigh.kg;
            if (childKg<=max &&(paths[childNum] > currTime + childTime)) {
                if (currTime + childTime <= maxTime) {
                     paths[childNum] = currTime + childTime;
                     q.push({ paths[childNum], childNum });
                }
                
            }
            
        }

    }
    if (paths[numNodes] == INT_MAX) {
        return false;
    }
    if (paths[numNodes] <= maxTime) {
        return true;
    }
    return false;
}

int findMin() {
    int left = minKg;
    int right = maxKg;
    int last = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (shortestPath(1, mid)) {
            right = mid - 1;
            last = mid;
        }
        else {
            left = mid + 1;
        }
    }
    return last;
}


int main() {
    cin >> numNodes >> numEdges >> maxTime;

    for (int i = 0; i < numEdges; i++) {
        int start;
        int end;
        int kgNeeded;
        int time;
        cin >> start >> end >> kgNeeded>>time;
        Edge node(end, kgNeeded, time);
        graph[start].push_back(node);
        if (kgNeeded < minKg) {
            minKg = kgNeeded;
        }
        if (kgNeeded > maxKg) {
            maxKg = kgNeeded;
        }
    }
    cout << findMin() << endl;
    
    return 0;
}