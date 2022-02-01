#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    vector<int> arr;
    unordered_map<int, int> input;
    vector<int> firstHalf;
    vector<int> secondHalf;

    int size;
    cin >> size;
    for (int i = 0; i < size; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
        input[num]++;
    }
    
    for (int i = 0; i < size; i++) {
        if (input[arr[i]] == 1) {
            firstHalf.push_back(arr[i]);
            continue;
        }
        else if (input[arr[i]] > 1) {
            input[arr[i]] = -1;
            secondHalf.push_back(arr[i]);
           
        }
    }
    for (auto curr: firstHalf) {
        cout << curr << " ";
    }
    for (auto curr : secondHalf) {
        cout << curr << " ";
    }

    return 0;
}