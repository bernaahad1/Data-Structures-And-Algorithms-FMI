#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct compare {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
        return (p1.first > p2.first);
    }
};
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int size;
    cin >> size;
    vector<pair<int,int>> arr;
    for (int i = 0; i < size; i++) {
        int num;
        cin >> num;
        arr.push_back({num, i});
    }
    

    int currTime = arr[0].first;
    int min = currTime;
    int max = currTime;
    int i = 1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> q;
    while (i < size || (!q.empty())) {
        while (i < size && arr[i].second <= currTime) {
            q.push(arr[i]);
            i++;
        }

        if ((!q.empty()) && q.top().second <= currTime) {
            int waitTime = currTime - q.top().second + q.top().first;
            if (waitTime < min) {
                min = waitTime;
            }
            if (waitTime > max) {
                max = waitTime;
            }
            currTime += q.top().first;
            q.pop();
            continue;
        }
        currTime++;
    }

    cout << min << " " << max << endl;
    
    return 0;
}
