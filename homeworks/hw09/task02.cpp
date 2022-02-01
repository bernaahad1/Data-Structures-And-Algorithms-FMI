#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long int size;
    long long int k;
    cin >> size >> k;
    unordered_map<long long int, long long int> left;
    unordered_map<long long int, long long int> right;
    vector<int> arr;

    for (long long int i = 0; i < size; i++) {
        long long int num;
        cin >> num;
        arr.push_back(num);
        right[num]++;
    }
    
    if (size < 3) {
        printf("%d", 0);
        return 0;
    }
    long long int count = 0;
    for (long long int i = 0; i < size; i++) {
        right[arr[i]]--;
        if (!left.empty() && !right.empty()) {
            if (arr[i] % k == 0) {
                long long int leftCount = left[arr[i] / k];
                long long int rightCount = right[arr[i] * k];
                count += (leftCount * rightCount);
            }
        }
        left[arr[i]]++;
    }
    printf("%lld", count);

    return 0;
}