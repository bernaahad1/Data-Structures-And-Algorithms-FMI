#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <stack>
using namespace std;

vector<string> words;
const int N = 101;
map<char, vector< char>> adj;
map<char, bool> visited;
stack<char> st;


void makeAdjL(int size) {
    for (int i = 0; i < size-1; i++) {
        size_t ind = 0;
        while (ind < min(words[i].size(), words[i + 1].size())) {
            if (words[i][ind] != words[i + 1][ind]) {
                adj[words[i][ind]].push_back(words[i + 1][ind]);
                break;
            }
            ind++;
        }
    }
}

void dfs(char curr) {
    visited[curr] = 1;
    for (auto neigh : adj[curr]) {
        if (!visited[neigh]) {
            dfs(neigh);
        }
    }
    st.push(curr);
}

void topologSort() {
    for (auto curr : adj) {
        if (visited[curr.first] == false) {
            dfs(curr.first);
        }
    }
}

int main()
{
    int size;
    cin >> size;
    for (int i = 0; i < size; i++) {
        string word;
        cin >> word;
        words.push_back(word);
    }

    makeAdjL(size);
    topologSort();
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

}