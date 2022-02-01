#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <iterator>

using namespace std;


int main(){
    set<int> masks;
    masks.insert(0);
    int size;
    cin >> size;
    while (size > 0) {
        int input;
        cin >> input;
        int curr = input;
        while (curr > 0) {
            masks.insert(curr);
            curr = (curr - 1) & input;
        }

        size--;
    }
    cout << masks.size();

    return 0;
}

