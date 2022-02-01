#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
     unsigned int size;
    cin >> size;
    vector <int> arr;

    for (size_t i = 0; i < size; i++) {
        int num;
        cin >> num;
        if (num <= 0) {
            i--;
            size--;
            continue;
        }
        else {
            arr.push_back(num);
        }
    }
    sort(arr.begin(), arr.end());

    int min = 1;
    for (size_t i = 0; i < size; i++) {
        if (arr[i] <= 0) {
            continue;
        }
        if (i > 0 && arr[i] == arr[i - 1]) {
            continue;
        }
        if (min < arr[i]) {
            break;
        }
        else if (min == arr[i]) {
            min++;
        }
    }
    
    cout << min << endl;
    return 0;
}