#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    vector<char> arr;
    int size;
    cin >> size;
    for (int i = 0; i < size; i++) {
        char ch;
        cin >> ch;
        arr.push_back(ch);
    }
    sort(arr.begin(), arr.end());

    
    vector<char> part1;
    vector<char> part2;

    for (int i = 0; i < size; i++) {
        if (arr[i] >= 'a') {
            part2.push_back(arr[i]);
            continue;
        }
        if (arr[i] >= 'A') {
            part1.push_back(arr[i]);
        }
        
    }
    int begin = size - (part1.size() + part2.size());
    unsigned int first = 0;
    unsigned int second = 0;
    for (int i = begin; i < size; i++) {
        if (second < part2.size()) {
            arr[i] = part2[second];
            second++;
            continue;
        }
        else {
            arr[i] = part1[first];
            first++;
        }
    }

    for (int i = 0; i < size; i++) {
        cout << arr[i];
    }
 
    return 0;
}
