#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
vector<int> arr;

int pank(long long time) {
    int numPank = 0;
    for (size_t i = 0; i < arr.size(); i++) {
        numPank += (time / arr[i]);
    }
    return numPank;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int minNeededTime = 0;
    long long numPank, numCooks;
    cin >> numPank >> numCooks;

    while (numCooks--) {
        int num;
        cin >> num;
        if (num > minNeededTime) {
            minNeededTime = num;
        }
        arr.push_back(num);
    }
    long long minMadeWithAll = pank(minNeededTime);
    long long currTime = minNeededTime;
    long long madePank = minMadeWithAll;
    while (madePank < numPank) {
        currTime += minNeededTime;
        madePank = pank(currTime);
    }
    if (madePank == numPank) {
        cout << currTime;
        return 0;
    }

    while (madePank > numPank) {
        currTime--;
        int newP = pank(currTime);
        if (newP < numPank) {
            cout << currTime + 1;
            return 0;
        }
        while (newP == numPank) {
            currTime--;
            newP = pank(currTime);
        }
        if (newP < numPank) {
            cout << currTime + 1;
            return 0;
        }
        madePank = newP;
    }
    

    cout << currTime;

    return 0;
}
