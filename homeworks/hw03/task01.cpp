#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long long int score;
    cin >> score;
    int numPresents = 0;
    long long int i = 0;
    long long int lastFind = i;
    while (score > 0) {
        i++;
        if ((i * i * i) == score) {
            numPresents++;
            score -= (i * i * i);
            i = 0;
            lastFind = i+1;
        }
        else if ((i * i * i) < score) {
            lastFind = i;

        }
        else if ((i * i * i) > score) {
            numPresents++;
            score -= (lastFind*lastFind*lastFind);
            i = 0;
            lastFind = i+1;
        }
        
    }
    cout << numPresents << endl;
    return 0;
}