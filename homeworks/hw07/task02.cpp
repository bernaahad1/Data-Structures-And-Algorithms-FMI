#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <iterator>
#include <climits>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    set<int> arr;
    int minXor = INT_MAX;
    arr.insert(0);
    int size;
    cin >> size;

    int curr;
    while (size > 0) {
        cin >> curr;
        if (arr.size() >= 2 && *arr.rbegin() < curr) {
            arr.insert(curr);
            auto last = arr.find(curr);
            last--;
            int currMin = *last ^ *(++last);
            if (currMin < minXor) {
                minXor = currMin;
               
            }
        }
        else if (arr.size() == 1) {
            arr.insert(curr);
            minXor = curr;
        }
        else if (!arr.count(curr)) {
             arr.insert(curr);
             auto last = arr.find(curr);
            last--;
            int currMin = *last ^ *(++last);
            if (currMin < minXor) {
                minXor = currMin;
               
            }
            currMin = *last ^ *(++last);
            if (currMin < minXor) {
                minXor = currMin;
            }
        }
        printf("%d\n", minXor);
        size--;
    }

    return 0;
}