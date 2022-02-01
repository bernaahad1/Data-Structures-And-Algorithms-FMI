#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
    string input;
    cin >> input;
    int size = input.size();
    vector<pair<int, int>> letters(26, { 0,0 }); //the second int is for the index
    vector<pair<int, int>> capitalLetters(26, { 0,0 }); //the second int is for the index
    vector<pair<int, int>> nums(10, { 0,0 }); //the second int is for the index
    vector<int> index;
    for (int i = 0; i < size; i++) {
        if (input[i] >= 'a') {
            letters[input[i] - 'a'].first++;
            letters[input[i] - 'a'].second = i;
        }
        else if (input[i] >= 'A' && input[i] <= 'Z') {
            capitalLetters[input[i] - 'A'].first++;
            capitalLetters[input[i] - 'A'].second = i;
        }
        else {
            nums[input[i] - '0'].first++;
            nums[input[i] - '0'].second = i;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (letters[i].first == 1) {
            index.push_back(letters[i].second);
        }
        if (capitalLetters[i].first == 1) {
            index.push_back(capitalLetters[i].second);
        }
        if (i < 10 && nums[i].first == 1) {
            index.push_back(nums[i].second);
        }
    }
    sort(index.begin(), index.end());
    size = index.size();
    for (int i = 0; i < size; i++) {
        cout << index[i] << " ";
    }
    return 0;
}
