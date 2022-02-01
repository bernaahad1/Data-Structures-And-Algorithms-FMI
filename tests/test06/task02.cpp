#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> adj[100000];
vector<int> visited;
int nodes;
int edges;

void findPath(int start,int comp){
    visited[start]=comp;
    
    for(auto neigh:adj[start]){
        if(!visited[neigh]){
            findPath(neigh,comp);
        }
    }
}
int main() {
    int inp;
    cin>>inp;
    while(inp--){
        cin>>nodes>>edges;
        for(int i=0;i<edges;i++){
            int start;
            int end;
            cin >> start >> end;
            adj[start].push_back(end);
            adj[end].push_back(start);
        }
        visited.clear();
        visited.resize(nodes,0);
        int comp=0;
        for(int i=0;i<nodes;i++){
            if(visited[i]==0){
                comp++;
                findPath(i,comp);                
            }
        }
        
        cout<<comp<<" ";
        for(int i=0;i<nodes;i++){
            adj[i].clear();
        }
        
    }
    return 0;
}
