#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned int round(vector<unsigned int>& arr) {
    int size = arr.size();
    unsigned int maxRounds = 0;
    int i = size - 1;
    while (i > 0) {
        if (arr[i] > arr[i - 1]) {
            unsigned int rounds = 1;
            arr.erase(arr.begin() + i);
            size--;
            while (i < size) {
                if (arr[i] > arr[i - 1]) {
                    rounds++;
                    arr.erase(arr.begin() + i);
                    size--;
                }
                else if (i > 1 && arr[i] == arr[i - 1] && arr[i] > arr[i - 2]) {
                    rounds++;
                    arr.erase(arr.begin() + i);
                    size--;
                }
                else {
                    break;
                }
            }
            if (rounds > maxRounds) {
                maxRounds = rounds;
            }
        }
        i--;
    }

    return maxRounds;
    
}
int main() {
    int size;
    cin >> size;
    vector<unsigned int> contest(size);
    for (int i = 0; i < size; i++) {
        cin >> contest[i];
    }

    cout<<round(contest);
    return 0;
}