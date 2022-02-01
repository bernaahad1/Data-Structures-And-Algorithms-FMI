#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

void duel(deque<int>& P, deque<int>& N) {
    while ((!P.empty()) && (!N.empty())) {
        if (P.back() > (N.front()) * (-1)) {
            N.pop_front();
        }
        else if (P.back() < (N.front()) * (-1)) {
            P.pop_back();
        }
        else {
            P.pop_back();
            N.pop_front();
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int size;
    cin >> size;
    deque<int> N;
    deque <int> P;
    int num;
    while (cin >> num) {
        if (num < 0) {
            if (P.empty()) {
                printf("%d ", num);
            }
            else {
                N.push_back(num);
            }
        }
        else {
            if (!N.empty()) {
                duel(P, N);
                if (P.empty()) {
                    while (!N.empty()) {
                        printf("%d ", N.front());
                        N.pop_front();
                    }
                }
            }
            P.push_back(num);
        }
    }

    duel(P, N);
    while (!P.empty()) {
        printf("%d ", P.front());
        P.pop_front();
    }
    while (!N.empty()) {
        printf("%d ", N.front());
        N.pop_front();
    }

    printf("\n");

    return 0;
}