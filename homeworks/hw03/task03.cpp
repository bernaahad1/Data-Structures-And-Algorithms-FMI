#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int findNumOfLongestSubs(vector<unsigned int> arr){
    int size = arr.size();
    vector<unsigned int> count;
    

    count.push_back(arr[0]);
        
    for (int i = 1; i < size; i++) {
        if (count.back() < arr[i]) {
            count.push_back(arr[i]);
            
        }
        else {
            int minInd = lower_bound(count.begin(), count.end(), arr[i]) - count.begin();

            count[minInd] = arr[i];
        }
      
    }
    return count.size();
}

int main() {
    unsigned int numDemons;
    vector<pair<unsigned int, unsigned int>> demons;
    cin >> numDemons;
    for (size_t i = 0; i < numDemons; i++) {
        unsigned int defence;
        unsigned int attack;
        cin >> defence;
        cin >> attack;
        demons.push_back(make_pair(defence, attack));
    }
    sort(demons.begin(), demons.end());
  
    for (size_t i = numDemons - 1; i > 0; i--) {
        if (demons[i - 1].first == demons[i].first) {
            demons.erase(demons.begin()+(i - 1));
            
            numDemons--;
        }
    }
    vector<unsigned int> attacks;
    for (size_t i = 0; i < numDemons; i++) {
        attacks.push_back(demons[i].second);
    }
    cout << findNumOfLongestSubs(attacks) << endl;
    return 0;
}
