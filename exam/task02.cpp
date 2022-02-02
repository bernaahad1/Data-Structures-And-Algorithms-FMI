#include <map>
#include <set>
#include <queue>
#include <vector>
#include <climits>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> adj[1001];
int nodes;
int edges;
vector<int> dist;
int startingNode;


void findMinPaths(int start){
    dist[start]=0;
    queue<int> q;
    q.push(start);
    
    while(!q.empty()){
        int currNode=q.front();
        q.pop();
        for(auto neigh: adj[currNode]){
            if(dist[neigh]>dist[currNode]+1){
                dist[neigh]=dist[currNode]+1;
                q.push(neigh);
            }
        }
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int inputs;
    cin>>inputs;
    while(inputs--){
        cin >> nodes >> edges;
        while(edges--){
            int start, end;
            cin >> start >> end;
            adj[start-1].push_back(end-1);
            adj[end-1].push_back(start-1);
        }
        cin >> startingNode;
        startingNode--;
        dist.clear();
        dist.resize(nodes,INT_MAX);
        findMinPaths(startingNode);
        
        for(int i=0;i<nodes;i++){
            if(dist[i]!=INT_MAX && i!=startingNode){
                cout<<dist[i]*6<<" ";
            }
            else if(dist[i]==INT_MAX){
                cout<<-1<<" ";
            }
        }
    
        for(int i=0;i<nodes;i++){
           adj[i].clear();
        }
        cout<<endl;
    }
    return 0;
}