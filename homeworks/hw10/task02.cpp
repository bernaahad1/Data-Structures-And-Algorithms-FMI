#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;
const int N = 1001;
int row;
int col;

vector<pair<int, int>> afterMinute(bool adj[N][N], vector<pair<int, int>> sick) {
    vector<pair<int, int>> result;
    for (size_t i = 0; i < sick.size(); i++) {
        result.push_back({ sick[i].first,sick[i].second });
        if (sick[i].first + 1 < row && adj[sick[i].first + 1][sick[i].second]==false) {
            adj[sick[i].first + 1][sick[i].second] = true;
            result.push_back({ sick[i].first + 1,sick[i].second });
        }
        if (sick[i].first - 1 >= 0 && adj[sick[i].first - 1][sick[i].second] == false) {
            adj[sick[i].first - 1][sick[i].second] = true;
            result.push_back({ sick[i].first - 1,sick[i].second });
        }
        if (sick[i].second + 1 < col && adj[sick[i].first][sick[i].second + 1]==false) {
            adj[sick[i].first][sick[i].second+1] = true;
            result.push_back({ sick[i].first,sick[i].second +1});
        }
        if (sick[i].second - 1 >= 0&& adj[sick[i].first][sick[i].second - 1]==false) {
            adj[sick[i].first][sick[i].second-1] = true;
            result.push_back({ sick[i].first,sick[i].second-1 });
        }
    }
    return result;
}

int main() {
    bool adj[N][N] = {0};
    
    int duration;
    int sickP;
    cin >> row >> col >> duration;
    cin >> sickP;
    vector<pair<int, int>> sick;
    for (int i = 0; i < sickP; i++) {
        int x;
        int y;
        cin >> x >> y;
        sick.push_back({ x - 1, y - 1 });
        adj[x - 1][y - 1] = true;
    }
    while (duration > 0) {
        sick = afterMinute(adj, sick);
        duration--;
    }
    cout << (row * col) - sick.size() << endl;

    return 0;
}