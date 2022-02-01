#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
  

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int numTopics;
    int numTeams;
    vector<long long int> topics;
    vector<long long int> teams;

    cin >> numTopics >> numTeams;
    for (int i = 0; i < numTopics; i++) {
        long long int num;
        cin >> num;
        topics.push_back(num);
    }

    for (int j = 0; j < numTeams; j++) {
        long long int num;
        cin >> num;
        teams.push_back(num);
    }

    for (int i = 0; i < numTeams; i++) {
        auto lowerEl = lower_bound(topics.begin(), topics.end(), teams[i]);
        auto upperEl = upper_bound(topics.begin(), topics.end(), teams[i]);
        int lowInd = lowerEl - topics.begin();
        int uppInd = upperEl - topics.begin();
        if (topics[0] >= teams[i]) {
            cout << topics[0] << endl;
        }
        else if (topics[numTopics - 1] <= teams[i]) {
            cout << topics[numTopics - 1] << endl;
        }
        else if (topics[lowInd] == teams[i]) {
            cout << teams[i] << endl;
        }
        else if ((teams[i] - topics[lowInd - 1]) <= (topics[uppInd] - teams[i])) {
            cout << topics[lowInd - 1] << endl;
        }
        else {
            cout << topics[uppInd] << endl;

        }
    }

    return 0;
}
