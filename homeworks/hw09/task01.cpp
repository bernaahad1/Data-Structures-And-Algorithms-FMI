#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long int size;
    cin >> size;
    vector<long long int> keys(size);
    unordered_multiset<long long int> us;
    long long int numBreaks = 0;
    for (long long int i = 0; i < size; i++) {
        cin >> keys[i];
    }
    long long int door;
    int i = 0;
    while (cin >> door) {
        us.insert(keys[i]);
        if (us.count(door) > 0) {
            auto key = us.find(door);
            us.erase(key);

        }
        else {
            numBreaks++;
        }
        i++;
    }
    printf("%lld",numBreaks);
    return 0;
}